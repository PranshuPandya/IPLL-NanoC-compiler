#ifndef ASS5_16CS10053_TRANSLATOR_INCLUDED
#define ASS5_16CS10053_TRANSLATOR_INCLUDED
#include <bits/stdc++.h>
using namespace std;

class ActivationRecord
{
public:
    map<string, int> displacement;
    int totalDisplacement;

    // ActivationRecord();
};

// extern int yyparse();
enum typenode_types
{
    ARRAY,
    PTR,
    INT4,
    CHAR1,
    VOID0,
    FUNCTION,
    BOOL1,
    DEFLT
};

class typeNode;
int compute_type_size(typeNode *type);
class SymbolTable;
class SymbolTableEntry;
class typeNode
{
public:
    typenode_types type;
    typeNode *next;
    int val;
    typeNode *parameters;
    // int retType;
    typeNode(typenode_types type, typeNode *next = 0, int val = -1, typeNode * parameters = 0);
};

class SymbolTableEntry
{
public:
    string name;
    typeNode *type;
    void *initial_value;
    int size;
    int offset;
    SymbolTable *nested_table;
    SymbolTableEntry(string name, typeNode *type = nullptr, void *initial_value = nullptr, int size = -1, int offset = -1, SymbolTable *nested_table = nullptr);
    string printInitialValue();
    string printType(typeNode *type);

    enum Category
    {
        LOCAL,
        GLOBAL,
        PARAMETER,
        TEMPORARY,
        FUNCT
    } category;

    void operator=(SymbolTableEntry &x);
    void printEntry();
    void update(typeNode *type, void *initial_value, SymbolTable *nested_table);
};

class SymbolTable
{
public:
    vector<SymbolTableEntry *> stable;
    string STName;
    SymbolTable *parent;
    SymbolTable(string name);
    ActivationRecord *activationRecord;
    SymbolTableEntry *lookup(string name, int flag = 1);
    SymbolTableEntry *gentemp(typenode_types tm);
    void update();
    void printSymbolTable();
};

class Statement
{
public:
    list<int> nextlist;
};

class Expression
{
public:
    list<int> truelist;
    list<int> falselist;
    list<int> nextlist;
    SymbolTableEntry *loc;
    string type;

    Expression()
    {
        type = "not-bool";
    }
};

class Array
{
public:
    SymbolTableEntry *loc;
    SymbolTableEntry *array;
    typeNode *type;
    string atype;
    string btype;
    list<int> truelist;
    list<int> falselist;
    list<int> nextlist;
};

class quadTableEntry;
class quadTable;

enum quad_ops
{
    DEF,
    PLUS,
    MINUS,
    INTO,
    DIVISION,
    PERCENT,
    LST,
    GRT,
    LSTE,
    GRTE,
    EQLTO,
    NEQLTO,
    LAND,
    LOR,
    LNOT,
    CALL,
    EQ_BRT,
    BRT_EQ,
    U_ADDR,
    U_STAR,
    ASSIGN,
    GOTO,
    IF_GOTO,
    IF_FALSE_GOTO,
    PARAM,
    RETURN_,
    RETURN_EXPN,
    FUCN,
    FUCNEND,
    GOTOLT,
    GOTOLTE,
    GOTOGT,
    GOTOGTE,
    GOTOEQL,
    GOTONEQL,
    U_PLUS,
    U_MINUS,
    STAR_ASSIGN,
    STRING_ASSIGN,
    ASSIGN_CHAR
    

};

class quadTableEntry
{
public:
    string arg1;
    string arg2;
    string res;
    quad_ops ops;
    SymbolTableEntry *arg1_addr;
    SymbolTableEntry *arg2_addr;
    SymbolTableEntry *res_addr;
    quadTableEntry(string arg1 = "", string arg2 = "", string res = "", quad_ops ops = DEF, SymbolTableEntry *arg1_addr = nullptr, SymbolTableEntry *arg2_addr = nullptr, SymbolTableEntry *res_addr = nullptr);

    void operator=(quadTableEntry &x);
    void printQuad();
};

class quadTable
{
public:
    vector<quadTableEntry *> quadArray;

    void emit(quadTableEntry *x);

    void printQuadTable();
};

class id_attr
{
public:
    SymbolTableEntry *loc;
    char *var;
};
// global variables
extern quadTable *quad_table;
extern SymbolTable *global_symbol_table;
extern SymbolTable *cur_symbol_table;
extern SymbolTableEntry *cur_symbol_entry;
extern vector<string> stringLiterals;
extern FILE *yyin;
extern set<string> global_initialized;
extern  void finalBackpatch();
// global functions
list<int> makelist(int start);

list<int> merge(list<int> &p1, list<int> &p2);

void backpatch(list<int> &p, int l);

SymbolTableEntry *convertTypes(SymbolTableEntry *cur, typenode_types reqtype);

int compareTypes(typeNode *e1, typeNode *e2);

int typecheck(SymbolTableEntry **e1, SymbolTableEntry *e2);

void conv2Bool(Expression *e);
void convBool2Int(Expression *e);



typeNode *copyType(typeNode *t);

#endif
