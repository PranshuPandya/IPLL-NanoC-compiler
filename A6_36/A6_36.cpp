#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <list>
#include "A6_36.h"
#include "A6_36.tab.h"
using namespace std;

int yylex(void);
int yyparse(void);
int yywrap() { return 1; }

const unsigned int size_of_char = 1;
const unsigned int size_of_int = 4;
const unsigned int size_of_pointer = 8;
int number_of_temporaries = 0;
vector<string> stringLiterals;
set<string> global_initialized;
// enum typenode_types
// {
//     ARRAY,
//     PTR,
//     INT4,
//     CHAR1,
//     VOID0,
//     FUNCTION,
//     BOOL1
// };

// class typeNode;
// int compute_type_size(typeNode *type);
// class SymbolTableEntry;
// class SymbolTable;

typeNode::typeNode(typenode_types type, typeNode *next, int val, typeNode *parameters)
{
    this->type = type;
    this->next = next;
    this->val = val;
    this->parameters = parameters;
}

SymbolTableEntry::SymbolTableEntry(string name, typeNode *type, void *initial_value, int size, int offset, SymbolTable *nested_table)
{
    this->name = name;
    this->type = type;
    this->initial_value = initial_value;
    this->size = compute_type_size(type);
    this->offset = offset;
    this->nested_table = nested_table;
}
string SymbolTableEntry::printInitialValue()
{
    string ret = "";
    if (type->type == FUNCTION)
    {
        ret = "not applicable";
    }
    else if (!initial_value)
    {
        ret = "undefined";
    }
    else if (type->type == INT4)
    {
        ret = to_string((*((int *)initial_value)));
    }
    else if (type->type == CHAR1)
    {
        ret = to_string((*((char *)initial_value)));
    }
    else if (type->type == PTR)
    {
        ret = string((char *)(initial_value));
    }
    return ret;
}
string printparameters(typeNode *type)
{
    if (type->type == VOID0)
        return "void";
    else if (type->type == CHAR1)
        return "char";
    else if (type->type == INT4)
        return "int";
    return "null";
    // else if (type->type == DEFLT)
    //     return ",";
}
string SymbolTableEntry::printType(typeNode *type)
{
    if (!type)
    {
        return "null";
    }
    else if (type->type == VOID0)
        return "void";
    else if (type->type == CHAR1)
        return "char";
    else if (type->type == PTR)
        return "pointer(" + printType(type->next) + ")";
    else if (type->type == INT4)
        return "int";
    else if (type->type == ARRAY)
        return "array(" + to_string(type->val) + ", " + printType(type->next) + ")";
    else if (type->type == DEFLT)
        return ",";
    else if (type->type == FUNCTION)
    {
        string s = "function(";
        typeNode *cur = type->next;
        s += printType(cur) + ",";
        cur = type->parameters;
        if (!cur)
        {
            s += "null";
        }
        while (cur)
        {
            if (cur->type == VOID0)
                s += "void";
            else if (cur->type == CHAR1)
                s += "char";
            else if (cur->type == PTR)
            {
                s += "pointer(" + printparameters(cur->next) + ")";
                cur = cur->next;
            }
            else if (cur->type == INT4)
                s += "int";
            else if (cur->type == DEFLT && cur->next)
                s += ",";
            cur = cur->next;
        }
        // s += printType(cur);
        s += ")";
        return s;
    }
    return "Not Applicable";
}

void SymbolTableEntry::operator=(SymbolTableEntry &x)
{
    this->name = x.name;
    this->type = x.type;
    this->initial_value = x.initial_value;
    this->size = x.size;
    this->offset = x.offset;
    this->nested_table = x.nested_table;
}
// void printEntry();
void SymbolTableEntry::update(typeNode *type, void *initial_value, SymbolTable *nested_table)
{
    this->initial_value = initial_value;
    this->type = type;
    this->size = compute_type_size(type);
    this->nested_table = nested_table;
}
// };

SymbolTable::SymbolTable(string name)
{
    STName = name;
    parent = nullptr;
}
SymbolTableEntry *SymbolTable::lookup(string name, int flag)
{
    // if (stable.size())
    // {

    for (auto u : stable)
    {
        if (u->name == name)
        {
            return u;
        }
    }
    // }
    // return nullptr;
    SymbolTableEntry *tmp = nullptr;
    if (flag)
    {
        tmp = new SymbolTableEntry(name);
        tmp->category = SymbolTableEntry::LOCAL;
        if (this == global_symbol_table)
        {
            tmp->category = SymbolTableEntry::GLOBAL;
        }

        stable.push_back(tmp);
    }
    return tmp;
}
SymbolTableEntry *SymbolTable::gentemp(typenode_types tm)
{
    string name = "t" + to_string(number_of_temporaries++);

    int size;
    switch (tm)
    {
    case INT4:
        size = size_of_int;
        break;
    case CHAR1:
        size = size_of_char;
        break;
    case PTR:
        size = size_of_pointer;
        break;
    default:
        break;
    }
    typeNode *tmpnode = new typeNode(tm);

    SymbolTableEntry *tmp = new SymbolTableEntry(name, tmpnode, 0, size, -1, 0);
    tmp->category = SymbolTableEntry::TEMPORARY;
    stable.push_back(tmp);
    return tmp;
}
void SymbolTable::update()
{
    int offset = 0;
    vector<SymbolTable *> visited;
    // int offset;
    for (auto u : stable)
    {
        u->offset = offset;
        offset += u->size;
        if (u->nested_table)
        {
            // u->nested_table->update();
            visited.push_back(u->nested_table);
        }
    }

    activationRecord = new ActivationRecord();

    for (auto u : stable)
    {
        if (u->category == SymbolTableEntry::PARAMETER)
        {
            if (u->size != 0)
            {
                activationRecord->totalDisplacement -= u->size;
                activationRecord->displacement[u->name] = activationRecord->totalDisplacement;
            }
        }
    }

    for (auto u : stable)
    {
        if ((u->category == SymbolTableEntry::LOCAL && u->name != "retVal") || (u->category == SymbolTableEntry::TEMPORARY))
        {
            activationRecord->totalDisplacement -= u->size;
            activationRecord->displacement[u->name] = activationRecord->totalDisplacement;
        }
    }

    for (auto u : visited)
    {
        u->update();
    }
}
void SymbolTable::printSymbolTable()
{
    vector<SymbolTable *> child_tables;
    cout << "Table Name: " << STName << "       Parent Name: ";
    if (parent)
        cout << parent->STName << endl;
    else
        cout << "null" << endl;

    int widthname = 20;
    int widthtype = 50;
    int widthinitval = 40;
    int widthsize = 8;
    int widthoffset = 10;
    int widthnestedtab = 17;
    int totalwidth = widthinitval + widthname + widthnestedtab + widthoffset + widthsize + widthtype;
    cout << setfill('=') << setw(totalwidth) << "=" << endl;
    cout << setfill(' ') << left << setw(widthname) << "| Name"
         << left << setw(widthtype) << "| Type"
         << left << setw(widthinitval) << "| Initial Value"
         << left << setw(widthsize) << "| Size"
         << left << setw(widthoffset) << "| Offset"
         << left << setw(widthnestedtab) << "| Nested Table |" << endl;
    // cout << setfill('=') << setw(totalwidth) << "=" << endl;
    // cout << setw(20) << "Name" << setw(20) << "Type" << setw(20) << "Initial Value" << setw(20) << "Size" << setw(20) << "Offset" << setw(20) << "Nested Table\n\n";
    for (auto u : stable)
    {
        u->printEntry();
        cout << endl;
        if (u->nested_table)
            child_tables.push_back(u->nested_table);
    }
    cout << setfill('=') << setw(totalwidth) << "=" << endl;

    cout << endl
         << endl;
    for (auto u : child_tables)
    {
        u->printSymbolTable();
    }
}

void SymbolTableEntry::printEntry()
{
    int widthname = 20;
    int widthtype = 50;
    int widthinitval = 40;
    int widthsize = 8;
    int widthoffset = 10;
    int widthnestedtab = 17;
    int totalwidth = widthinitval + widthname + widthnestedtab + widthoffset + widthsize + widthtype;
    string nest;
    if (!nested_table)
        nest = "null";
    else
        nest = (nested_table->STName);
    cout << setfill(' ') << left << setw(widthname) << "| " + name
         << left << setw(widthtype) << "| " + printType(type)
         << left << setw(widthinitval) << "| " + printInitialValue()
         << left << setw(widthsize) << "| " + to_string(size)
         << left << setw(widthoffset) << "| " + to_string(offset)
         << left << setw(widthnestedtab) << "| " + nest << "|" << endl;

    // Create the bottom border of the table
    // cout << setw(20) << name;
    // cout << setw(20) << printType(type);
    // printInitialValue();
    // cout << setw(20) << size;
    // cout << setw(20) << offset;
}

int compute_type_size(typeNode *type)
{
    if (!type)
    {
        return -1;
    }
    int size = 1;

    if (type->type == INT4)
    {
        return size_of_int;
    }
    else if (type->type == CHAR1)
    {
        return size_of_char;
    }
    else if (type->type == PTR)
    {
        return size_of_pointer;
    }
    else if (type->type == ARRAY)
    {
        size *= type->val;
        size *= compute_type_size(type->next);
        return size;
    }
    else if (type->type == VOID0)
    {
        return 0;
    }
    else if (type->type == FUNCTION)
    {
        return 0;
    }

    return -1;
}

quadTableEntry::quadTableEntry(string arg1, string arg2, string res, quad_ops ops, SymbolTableEntry *arg1_addr, SymbolTableEntry *arg2_addr, SymbolTableEntry *res_addr)
{
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->res = res;
    this->ops = ops;
    this->arg1_addr = arg1_addr;
    this->arg2_addr = arg2_addr;
    this->res_addr = res_addr;
}

void quadTableEntry::operator=(quadTableEntry &x)
{
    this->arg1 = x.arg1;
    this->arg2 = x.arg2;
    this->res = x.res;
    this->ops = x.ops;
    this->arg1_addr = x.arg1_addr;
    this->arg2_addr = x.arg2_addr;
    this->res_addr = x.res_addr;
}

void quadTableEntry::printQuad()
{
    if (!(this->ops == FUCN || this->ops == FUCNEND))
    {
        cout << "\t\t";
    }
    switch (this->ops)
    {
    case PLUS:
        cout << this->res << " = " << this->arg1 << " + " << this->arg2 << endl;
        break;
    case MINUS:
        cout << this->res << " = " << this->arg1 << " - " << this->arg2 << endl;
        break;
    case INTO:
        cout << this->res << " = " << this->arg1 << " * " << this->arg2 << endl;
        break;
    case DIVISION:
        cout << this->res << " = " << this->arg1 << " / " << this->arg2 << endl;
        break;
    case PERCENT:
        cout << this->res << " = " << this->arg1 << " % " << this->arg2 << endl;
        break;
    case LST:
        cout << this->res << " = " << this->arg1 << " < " << this->arg2 << endl;
        break;
    case GRT:
        cout << this->res << " = " << this->arg1 << " > " << this->arg2 << endl;
        break;
    case LSTE:
        cout << this->res << " = " << this->arg1 << " <= " << this->arg2 << endl;
        break;
    case GRTE:
        cout << this->res << " = " << this->arg1 << " >= " << this->arg2 << endl;
        break;
    case EQLTO:
        cout << this->res << " = " << this->arg1 << " == " << this->arg2 << endl;
        break;
    case NEQLTO:
        cout << this->res << " = " << this->arg1 << " != " << this->arg2 << endl;
        break;
    case LAND:
        cout << this->res << " = " << this->arg1 << " && " << this->arg2 << endl;
        break;
    case LOR:
        cout << this->res << " = " << this->arg1 << " || " << this->arg2 << endl;
        break;
    case LNOT:
        cout << this->res << " = "
             << "!" << this->arg1 << endl;
        break;
    case EQ_BRT:
        cout << this->res << " = " << this->arg1 << " [ " << this->arg2 << " ]" << endl;
        break;
    case BRT_EQ:
        cout << this->res << " [ " << this->arg1 << " ] = " << this->arg2 << endl;
        break;
    case GOTOLT:
        cout << "if " << this->arg1 << " < " << this->arg2 << " goto " << this->res << endl;
        break;
    case GOTOLTE:
        cout << "if " << this->arg1 << " <= " << this->arg2 << " goto " << this->res << endl;
        break;
    case GOTOGT:
        cout << "if " << this->arg1 << " > " << this->arg2 << " goto " << this->res << endl;
        break;
    case GOTOGTE:
        cout << "if " << this->arg1 << " >= " << this->arg2 << " goto " << this->res << endl;
        break;
    case GOTOEQL:
        cout << "if " << this->arg1 << " == " << this->arg2 << " goto " << this->res << endl;
        break;
    case GOTONEQL:
        cout << "if " << this->arg1 << " != " << this->arg2 << " goto " << this->res << endl;
        break;
    case CALL:
        cout << this->res << " = call " << arg1 << ", " << arg2 << endl;
        break;
    case U_PLUS:
        cout << this->res << " = " << this->arg1 << endl;
        break;
    case U_MINUS:
        cout << this->res << " = "
             << "-" << this->arg1 << endl;
        break;
    case U_ADDR:
        cout << this->res << " = "
             << "&" << this->arg1 << endl;
        break;
    case U_STAR:
        cout << this->res << " = "
             << "*" << this->arg1 << endl;
        break;
    case ASSIGN:
        cout << this->res << " = " << this->arg1 << endl;
        break;
    case ASSIGN_CHAR:

        cout << this->res << " = " << (char)stoi(this->arg1) << endl;
        break;
    case GOTO:
        cout << "goto " << this->res << endl;
        break;
    case IF_GOTO:
        cout << "if " << this->arg1 << " goto " << this->res << endl;
        break;
    case IF_FALSE_GOTO:
        cout << "ifFalse " << this->arg1 << " goto " << this->res << endl;
        break;
    case PARAM:
        cout << "param " << this->arg1 << endl;
        break;
    case RETURN_:
        cout << "return " << endl;
        break;
    case RETURN_EXPN:
        cout << "return " << this->arg1 << endl;
        break;
    // case LABEL:
    case FUCN:
        cout << this->arg1 << " : " << endl;
        break;
    case FUCNEND:
        cout << this->arg1 << " : " << endl;
        break;
    case STAR_ASSIGN:
        cout << "*" << this->res << " = " << this->arg1 << endl;
        break;
    case STRING_ASSIGN:
        cout << this->res << " = " << stringLiterals[stoi(this->arg1)] << endl;
        break;
    }
}

void quadTable::emit(quadTableEntry *x)
{
    quadArray.push_back(x);
}

void quadTable::printQuadTable()
{
    for (int i = 0; i < quadArray.size(); i++)
    {
        cout << i << " : ";
        quadArray[i]->printQuad();
    }
}

quadTable *quad_table;
SymbolTable *global_symbol_table;
SymbolTable *cur_symbol_table;
typenode_types cur_type;
SymbolTableEntry *cur_symbol_entry;
// global functions
list<int> makelist(int start)
{
    list<int> newList = {start};
    return newList;
}

list<int> merge(list<int> &p1, list<int> &p2)
{
    p1.merge(p2);
    return p1;
}

void backpatch(list<int> &p, int l)
{
    for (auto u : p)
    {
        ((quad_table->quadArray)[u])->res = to_string(l);
    }
}

SymbolTableEntry *convertTypes(SymbolTableEntry *cur, typenode_types reqtype)
{
    if (cur->type->type == INT4 && reqtype == CHAR1)
    {
        SymbolTableEntry *tmp = cur_symbol_table->gentemp(reqtype);
        quadTableEntry *q = new quadTableEntry(cur->name, "", tmp->name, ASSIGN, cur, nullptr, tmp);
        // quadTableEntry *q = new quadTableEntry("int2char(" + cur->name + ")", "", tmp->name, ASSIGN, cur, nullptr, tmp);
        quad_table->emit(q);
        return tmp;
    }
    else if (cur->type->type == CHAR1 && reqtype == INT4)
    {
        SymbolTableEntry *tmp = cur_symbol_table->gentemp(reqtype);
        quadTableEntry *q = new quadTableEntry(cur->name, "", tmp->name, ASSIGN, cur, nullptr, tmp);
        // quadTableEntry *q = new quadTableEntry("char2int(" + cur->name + ")", "", tmp->name, ASSIGN, cur, nullptr, tmp);
        quad_table->emit(q);
        return tmp;
    }
    // return cur;
    return nullptr;
}

int compareTypes(typeNode *e1, typeNode *e2)
{
    if (!e1 && !e2)
        return 1;
    if (!e1)
        return 0;
    if (!e2)
        return 0;

    return (e1->type == e2->type) && compareTypes(e1->next, e2->next);
}

int typecheck(SymbolTableEntry **e1, SymbolTableEntry *e2)
{
    int flag = 0;
    if (compareTypes((*e1)->type, e2->type))
    {
        return 1;
    }
    else
    {
        SymbolTableEntry *tm = (convertTypes((*e1), e2->type->type));
        if (tm)
        {
            // cout<<"tc";
            *e1 = tm;
            cout << (*e1)->name << " " << tm->name << endl;
            return 1;
        }
    }
    return 0;
}

void conv2Bool(Expression *e)
{
    if (e->type != "bool")
    {
        e->falselist = makelist(quad_table->quadArray.size());
        quadTableEntry *tmp = new quadTableEntry(e->loc->name, "0", "", GOTOEQL, e->loc, nullptr, nullptr);
        quad_table->emit(tmp);
        e->truelist = makelist(quad_table->quadArray.size());
        tmp = new quadTableEntry("", "", "", GOTO, 0, 0, 0);
        quad_table->emit(tmp);
    }
}

void convBool2Int(Expression *e)
{
    if (e->type == "bool")
    {
        e->loc = cur_symbol_table->gentemp(INT4);
        backpatch(e->truelist, quad_table->quadArray.size());
        // quadTableEntry *q = new quadTableEntry("true", "", e->loc->name, ASSIGN, nullptr, nullptr, e->loc);
        // quad_table->emit(q);

        quadTableEntry *q = new quadTableEntry("", "", to_string(quad_table->quadArray.size() + 1), GOTO, 0, 0, 0);
        quad_table->emit(q);

        backpatch(e->falselist, quad_table->quadArray.size());
        // q = new quadTableEntry("false", "", e->loc->name, ASSIGN, nullptr, nullptr, e->loc);
        // quad_table->emit(q);
    }
}

typeNode *copyType(typeNode *t)
{
    typeNode *cur = new typeNode(t->type);
    typeNode *head = cur;
    typeNode *p = t->next;
    while (p)
    {
        cur->next = new typeNode(p->type);
        p = p->next;
        cur = cur->next;
    }
    return head;
    ;
}

void finalBackpatch()
{
    int curPos = quad_table->quadArray.size() - 1;
    int lastExit = -1;
    for (auto it = quad_table->quadArray.rbegin(); it != quad_table->quadArray.rend(); it++)
    {
        // if (curPos == 14)
        // {
        //     // if()
        //     cout<<(*it)->res;
        // }
        quad_ops op = (*it)->ops;
        if (op == FUCNEND)
        {
            lastExit = curPos;
        }
        else if (op == GOTO || op == GOTOEQL || op == GOTONEQL || op == GOTOLT || op == GOTOGT || op == GOTOLTE || op == GOTOGTE)
        {
            if ((*it)->res == "")
            {
                (*it)->res = to_string(lastExit);
                // cout << "found " << curPos << endl;
            }
        }
        curPos--;
    }
}

extern int yydebug;

// int main()
// {
// yydebug = 1;
// global_symbol_table = new SymbolTable("Global");
// cur_symbol_table = global_symbol_table;
// quad_table = new quadTable();
// int res = yyparse();
// if (res != 0)
// {
//     printf("\nSome Error Occured!\n");
// }
// else
// {
//     printf("\nParsing Succesfull.\n");
// }
// global_symbol_table->update();
// global_symbol_table->printSymbolTable();
// quad_table->printQuadTable();
// return 0;
// SymbolTable *s = new SymbolTable("Global");
// SymbolTableEntry *tm = s->lookup("a");
// tm->type = new typeNode(PTR);
// tm->type->next = new typeNode(CHAR1);
// char * p = "pranshu";
// tm->initial_value = p;
// cout<< string((char*)(tm->initial_value));
// // tm->printEntry();
// cout<< endl;
// // int a = 5;
// // typeNode *tmp = new typeNode(INT4);

// // SymbolTableEntry *tm1 = s->lookup("b");
// // char b = 'g';
// // typeNode *tmp1 = new typeNode(CHAR1);

// // SymbolTableEntry *tm2 = s->lookup("c");
// // int c = 5;
// // typeNode *tmp2 = new typeNode(INT4);

// // tm->update(tmp, &a, 0);
// // tm1->update(tmp1, &b, 0);
// // tm2->update(tmp2, &c, 0);
// // // s->lookup("a");
// // s->update();
// // s->printSymbolTable();
// int a = 5;
// int d = 5;
// // int b = a;
// // char c = 'b';
// // a = c;
// // b = a + a;

// global_symbol_table = new SymbolTable("Global");
// cur_symbol_table = global_symbol_table;
// quad_table = new quadTable();

// {
//     SymbolTableEntry *tm = cur_symbol_table->lookup("a");
//     typeNode *tmp = new typeNode(INT4);
//     tm->update(tmp, &d, 0);
// }
// // int b;
// int b = a;

// {
//     SymbolTableEntry *tm = cur_symbol_table->lookup("b");
//     SymbolTableEntry *tm1 = cur_symbol_table->lookup("a");
//     typeNode *tmp = new typeNode(INT4);

//     Expression * e = new Expression();
//     e->loc = tm1;
//     tm->update(tmp, e->loc->initial_value, 0);
// }
// char c = 'b';
// char f = 'b';

// {
//     SymbolTableEntry *tm = cur_symbol_table->lookup("c");
//     typeNode *tmp = new typeNode(CHAR1);
//     tm->update(tmp, &f, 0);
// }

// a = c;

// {
//     SymbolTableEntry *tm = cur_symbol_table->lookup("a");
//     SymbolTableEntry *tm1 = cur_symbol_table->lookup("c");

//     Expression * e = new Expression();
//     e->loc = tm1;
//     e->type = tm1->type;

//     typecheck(&e->loc,tm);
//     cout<<e->loc->name<<endl;
//     quadTableEntry *qtm = new quadTableEntry(e->loc->name, "", tm->name, ASSIGN, e->loc, nullptr, tm);
//     quad_table->emit(qtm);
// }

// b = a + a;
// {
//     SymbolTableEntry *tm = cur_symbol_table->lookup("a");
//     Expression * e = new Expression();
//     e->loc = tm;
//     e->type = tm->type;

//     Expression * e2 = new Expression();
//     e->loc = tm;
//     e->type = tm->type;
//     SymbolTableEntry *tm1 = cur_symbol_table->lookup("c");

//     Expression * e = new Expression();
//     e->loc = tm1;
//     e->type = tm1->type;

//     typecheck(&e->loc,tm);
//     cout<<e->loc->name<<endl;
//     quadTableEntry *qtm = new quadTableEntry(e->loc->name, "", tm->name, ASSIGN, e->loc, nullptr, tm);
//     quad_table->emit(qtm);
// }

// cur_symbol_table->update();
// cur_symbol_table->printSymbolTable();
// quad_table->printQuadTable();
// }