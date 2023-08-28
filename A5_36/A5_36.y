%{
#include "A5_36.h"
int yylex (void);
int yyerror (char const *s);
#define YYDEBUG 1
extern char *yytext;
extern typenode_types cur_type;
// extern yylineno;
%}

/* Bison declarations. */
%union{
    int intval;
    char char_value;
    char* str_value;

    int num_para;

    quad_ops uop;

    SymbolTableEntry *ste;
    Expression *exp;
    Array* arr;
    id_attr ida;
    Statement * smt;
    typeNode* tpn;
}

%token CHAR
%token ELSE
%token FOR
%token IF
%token INT
%token RETURN
%token VOID

%type <ida> PRA
%token <ida> IDENTIFIER
%token <intval> INTEGER_CONST
%token <char_value> CHARACTER_CONST
%token <str_value> STRING_LITERAL


%token SQBRT
%token SQBLT
%token RDBRT
%token RDBLT
%token SUB
%token ADD
%token MULT
%token DIV
%token CRBLT
%token CRBRT
%token PTRARW
%token AMPERSOND
%token MOD
%token NOT
%token QSTMK
%token LT
%token GT
%token LTE
%token GTE
%token EQUALTO
%token NOTEQUAL
%token AND
%token OR
%token ASGN
%token COLN
%token SCOLN
%token COMMA

%type<num_para> argument_expression_list;
%type<num_para> argument_expression_list_opt;

%type<tpn> parameter_list;
%type<tpn> parameter_declaration;

%type<exp> primary_expression;
%type<exp> assignment_expression;
%type<exp> expression;
%type<exp> conditional_expression;
%type<exp> logical_OR_expression;
%type<exp> logical_AND_expression;
%type<exp> equality_expression;
%type<exp> relational_expression;
%type<exp> additive_expression;
%type<exp> multiplicative_expression;
%type<exp> expression_statement;

%type<uop> unary_operator;


%type<arr> postfix_expression;
%type<arr> unary_expression;

%type<ste> direct_declarator;
%type<ste> init_declarator;
%type<ste> declarator;
%type<ste> initializer;

%type<smt> N;
%type<intval> M;

%type<smt> statement
            compound_statement
            selection_statement
            iteration_statement
            jump_statement
            block_item
            block_item_list
            block_item_list_opt

%start translation_unit

%right "then" ELSE

%% /* The grammar follows. */
M:
    {
        $$ = quad_table->quadArray.size();
    }
    ;
N:
    {
        $$ = new Statement();
        $$->nextlist = makelist(quad_table->quadArray.size());
        quadTableEntry* tmp = new quadTableEntry("", "", "", GOTO, 0, 0, 0);
        quad_table->emit(tmp);
    }
    ;
primary_expression:
    IDENTIFIER  
    {
        SymbolTableEntry * q = cur_symbol_table->lookup($1.var, 0);
        if(!q){
            q = global_symbol_table->lookup($1.var, 0);
        }
        if(!q){
            // yyerror("Error: "+$1.var+" not declared");
            cout<<"Error: "<<$1.var<<" not declared"<<endl;
            exit(1);
        // q = cur_symbol_table->lookup($1.var);

        }
        $1.loc = q;
        $$ = new Expression();
        // $$->type = $1.loc->type;
        $$->loc = $1.loc;
    }
    |INTEGER_CONST 
    {
        $$ = new Expression();
        SymbolTableEntry * tmp = cur_symbol_table->gentemp(INT4);
        int* g = new int($1);
        tmp->initial_value = g;
        $$->loc = tmp;

        // quadTableEntry* q = new quadTableEntry(to_string($1),"",tmp->name,ASSIGN,nullptr, nullptr, tmp);
        // quad_table->emit(q);
    }
    |CHARACTER_CONST 
    {
        $$ = new Expression();
        SymbolTableEntry * tmp = cur_symbol_table->gentemp(CHAR1);
        char* g = new char($1);
        tmp->initial_value = g;    
        $$->loc = tmp;

        // quadTableEntry* q = new quadTableEntry(to_string($1),"",tmp->name,ASSIGN,nullptr, nullptr, tmp);
        // quad_table->emit(q);    
    }
    |STRING_LITERAL 
    {
        cout<< $1<<endl;
        
        $$ = new Expression();
        SymbolTableEntry * tmp = cur_symbol_table->gentemp(PTR);
        
        // // cout<< $1<<endl;
        // // string *g = new string($1 );
        // char **g = new char*($1);
        // // const char * g1 = (*g).c_str();
        // // cout<<g1;
        // // char *g2 = g1;
        // // char** arg1 = new char*($1);
        // // // sprintf(arg1,"%s",$1);
        // tmp->initial_value = g;    
        // cout<<*((char **)tmp->initial_value)<<endl;
        tmp->type->next = new typeNode(CHAR1);
        tmp->initial_value = $1;
        $$->loc = tmp;
        // // char* g = new char($1);
        // // tmp->initial_value = g;
    }
    |RDBLT expression RDBRT 
    {
        $$ = $2;
    }
    ;

postfix_expression:
    primary_expression
    {
        // cout<< $1->loc->name<<" "<<endl;
        $$ = new Array();
        $$->array = $1->loc;
        $$->loc = $1->loc;
        if($1->loc)
            $$->type = $1->loc->type;
    }
    |postfix_expression SQBLT expression SQBRT
    {
        $$ = new Array();

        $$->array = $1->array;
        $$->loc = cur_symbol_table->gentemp(INT4);
        $$->atype = "arr";
        $$->type = $1->type->next;
        int p = compute_type_size($$->type);

        if($1->atype == "arr"){
            SymbolTableEntry *t = cur_symbol_table->gentemp(INT4);
            quadTableEntry* q = new quadTableEntry($3->loc->name,to_string(p),t->name,INTO, $3->loc, nullptr,t);
            quad_table->emit(q);  

            q = new quadTableEntry($1->loc->name,t->name,$$->loc->name,PLUS, $1->loc, t,$$->loc);
            quad_table->emit(q);             
        }else{
            quadTableEntry* q = new quadTableEntry($3->loc->name,to_string(p),$$->loc->name,INTO,$3->loc,nullptr, $$->loc);
            quad_table->emit(q);            
        }
    }
    |postfix_expression RDBLT argument_expression_list_opt RDBRT
    {
        $$ = new Array();
        
        $$->array = cur_symbol_table->gentemp($1->loc->type->next->type);
        quadTableEntry * q = new quadTableEntry($1->array->name,to_string($3),$$->array->name,CALL,$1->array,nullptr,$$->array);
        quad_table->emit(q);
    }
    |postfix_expression PTRARW IDENTIFIER
    {

    }
    ;

argument_expression_list_opt:
    argument_expression_list
    {
        $$ = $1;
    }
    |
    {
        $$ = 0;
    }
    ;

argument_expression_list:
    assignment_expression
    {
        $$ = 1;
        quadTableEntry * q = new quadTableEntry($1->loc->name,"","",PARAM,$1->loc,nullptr,nullptr);
        quad_table->emit(q);
    }
    |argument_expression_list COMMA assignment_expression
    {
        $$ = $1 + 1;
        quadTableEntry * q = new quadTableEntry($3->loc->name,"","",PARAM,$3->loc,nullptr,nullptr);
        quad_table->emit(q);
    }
    ;

unary_expression:
    postfix_expression 
    {
        $$ = $1;
    }
    |unary_operator unary_expression
    {
        $$ = new Array();

        switch($1)
        {
            case U_ADDR:
            {
                $$->array = cur_symbol_table->gentemp(PTR);
                $$->array->type->next = $2->array->type;
                quadTableEntry *q = new quadTableEntry($2->array->name,"",$$->array->name,U_ADDR,$2->array,nullptr,$$->array);
                quad_table->emit(q);
                break;
            }
            case U_STAR:
            {
                $$->atype = "ptr";
                $$->loc = cur_symbol_table->gentemp($2->array->type->next->type);
                $$->array = $2->array;
                quadTableEntry *q = new quadTableEntry($2->array->name,"",$$->loc->name,U_STAR,$2->array,nullptr,$$->loc);
                quad_table->emit(q);
                break;
            }
            case U_PLUS:
            {
                $$ = $2;
                break;
            }
            case U_MINUS:
            {
                $$->array = cur_symbol_table->gentemp($2->array->type->type);
                quadTableEntry *q = new quadTableEntry($2->array->name,"",$$->array->name,U_MINUS,$2->array,nullptr,$$->array);
                quad_table->emit(q);
                break;
            }
            case LNOT:
            {
                $$->array = cur_symbol_table->gentemp($2->array->type->type);
                quadTableEntry *q = new quadTableEntry($2->array->name,"",$$->array->name,LNOT,$2->array,nullptr,$$->array);
                quad_table->emit(q);
                break;                
            }
        }
    }
    ;

unary_operator:
    AMPERSOND
    {
        $$ = U_ADDR;
    }
    |MULT
    {
        $$ = U_STAR;
    }
    |ADD
    {
        $$ = U_PLUS;
    }
    |SUB
    {
        $$ = U_MINUS;
    }
    |NOT
    {
        $$ = LNOT;
    }
    ;

multiplicative_expression:
    unary_expression
    {
        $$ = new Expression();

        if($1->atype == "arr"){
            $$->loc = cur_symbol_table->gentemp($1->type->type);
            quadTableEntry *q = new quadTableEntry($1->array->name,$1->loc->name,$$->loc->name,EQ_BRT,$1->array,$1->loc,$$->loc);
            quad_table->emit(q);
        }
        else if($1->atype == "ptr"){
            $$->loc = $1->loc;
        }
        else{
            $$->loc = $1->array;
        }
    }
    |multiplicative_expression MULT unary_expression
    {
        Expression* tmp = new Expression();
        if($3->atype == "arr"){
            tmp->loc = cur_symbol_table->gentemp($3->type->type);
            quadTableEntry *q = new quadTableEntry($3->array->name,$3->loc->name,tmp->loc->name,EQ_BRT,$3->array,$3->loc,tmp->loc);
            quad_table->emit(q);
        }
        else if($3->atype == "ptr"){
            tmp->loc = $3->loc;
        }
        else{
            tmp->loc = $3->array;
        }

        if(!typecheck(&($1->loc), tmp->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();

            $$->loc = cur_symbol_table->gentemp($1->loc->type->type);
            quadTableEntry *q = new quadTableEntry($1->loc->name,tmp->loc->name,$$->loc->name,INTO,$1->loc,tmp->loc,$$->loc);
            quad_table->emit(q);

        }
    }
    |multiplicative_expression DIV unary_expression
    {
        Expression* tmp = new Expression();
        if($3->atype == "arr"){
            tmp->loc = cur_symbol_table->gentemp($3->type->type);
            quadTableEntry *q = new quadTableEntry($3->array->name,$3->loc->name,tmp->loc->name,EQ_BRT,$3->array,$3->loc,tmp->loc);
            quad_table->emit(q);
        }
        else if($3->atype == "ptr"){
            tmp->loc = $3->loc;
        }
        else{
            tmp->loc = $3->array;
        }

        if(!typecheck(&($1->loc), tmp->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();
            $$->loc = cur_symbol_table->gentemp($1->loc->type->type);
            quadTableEntry *q = new quadTableEntry($1->loc->name,tmp->loc->name,$$->loc->name,DIVISION,$1->loc,tmp->loc,$$->loc);
            quad_table->emit(q);

        }
    }
    |multiplicative_expression MOD unary_expression
    {
        Expression* tmp = new Expression();
        if($3->atype == "arr"){
            tmp->loc = cur_symbol_table->gentemp($3->type->type);
            quadTableEntry *q = new quadTableEntry($3->array->name,$3->loc->name,tmp->loc->name,EQ_BRT,$3->array,$3->loc,tmp->loc);
            quad_table->emit(q);
        }
        else if($3->atype == "ptr"){
            tmp->loc = $3->loc;
        }
        else{
            tmp->loc = $3->array;
        }

        if(!typecheck(&($1->loc), tmp->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();
            $$->loc = cur_symbol_table->gentemp($1->loc->type->type);
            quadTableEntry *q = new quadTableEntry($1->loc->name,tmp->loc->name,$$->loc->name,PERCENT,$1->loc,tmp->loc,$$->loc);
            quad_table->emit(q);

        }
    }
    ;

additive_expression:
    multiplicative_expression
    {
        $$ = $1;
    }
    |additive_expression ADD multiplicative_expression
    {
        if(!typecheck(&($1->loc), $3->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();
            $$->loc = cur_symbol_table->gentemp($1->loc->type->type);
            quadTableEntry *q = new quadTableEntry($1->loc->name,$3->loc->name,$$->loc->name,PLUS,$1->loc,$3->loc,$$->loc);
            quad_table->emit(q);

        }
    }
    |additive_expression SUB multiplicative_expression
    {
        if(!typecheck(&($1->loc), $3->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();
            $$->loc = cur_symbol_table->gentemp($1->loc->type->type);
            quadTableEntry *q = new quadTableEntry($1->loc->name,$3->loc->name,$$->loc->name,MINUS,$1->loc,$3->loc,$$->loc);
            quad_table->emit(q);

        }
    }
    ;

relational_expression:
    additive_expression
    {
        $$ = $1;
    }
    |relational_expression LT additive_expression
    {
        if(!typecheck(&($1->loc), $3->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();
            $$->truelist = makelist(quad_table->quadArray.size());
            $$->falselist = makelist(quad_table->quadArray.size() + 1);
            $$->type = "bool";
            quadTableEntry* q = new quadTableEntry($1->loc->name,$3->loc->name,"",GOTOLT,$1->loc,$3->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);            
        }        
    }
    |relational_expression GT additive_expression
    {
        if(!typecheck(&($1->loc), $3->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();
            $$->truelist = makelist(quad_table->quadArray.size());
            $$->falselist = makelist(quad_table->quadArray.size() + 1);
            $$->type = "bool";
            quadTableEntry* q = new quadTableEntry($1->loc->name,$3->loc->name,"",GOTOGT,$1->loc,$3->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);            

        }     
    }
    |relational_expression LTE additive_expression
    {
        if(!typecheck(&($1->loc), $3->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();
            $$->truelist = makelist(quad_table->quadArray.size());
            $$->falselist = makelist(quad_table->quadArray.size() + 1);
            $$->type = "bool";
            quadTableEntry* q = new quadTableEntry($1->loc->name,$3->loc->name,"",GOTOLTE,$1->loc,$3->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);            

        }     
    }
    |relational_expression GTE additive_expression
    {
        if(!typecheck(&($1->loc), $3->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            $$ = new Expression();
            $$->truelist = makelist(quad_table->quadArray.size());
            $$->falselist = makelist(quad_table->quadArray.size() + 1);
            $$->type = "bool";
            quadTableEntry* q = new quadTableEntry($1->loc->name,$3->loc->name,"",GOTOGTE,$1->loc,$3->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);            

        }     
    }
    ;

equality_expression:
    relational_expression
    {
        $$ = $1;
    }
    |equality_expression EQUALTO relational_expression
    {
        if(!typecheck(&($1->loc), $3->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            convBool2Int($1);
            convBool2Int($3);

            $$ = new Expression();
            $$->type = "bool";
            $$->truelist = makelist(quad_table->quadArray.size());
            $$->falselist = makelist(quad_table->quadArray.size() + 1);            
            quadTableEntry* q = new quadTableEntry($1->loc->name,$3->loc->name,"",GOTOEQL,$1->loc,$3->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);  
        }     
    }
    |equality_expression NOTEQUAL relational_expression
    {
        if(!typecheck(&($1->loc), $3->loc))
        {
            cout<<"Incompatible Types"<<endl;
            exit(1);
        }
        else
        {
            convBool2Int($1);
            convBool2Int($3);

            $$ = new Expression();
            $$->type = "bool";
            $$->truelist = makelist(quad_table->quadArray.size());
            $$->falselist = makelist(quad_table->quadArray.size() + 1);            
            quadTableEntry* q = new quadTableEntry($1->loc->name,$3->loc->name,"",GOTONEQL,$1->loc,$3->loc,nullptr);
            quad_table->emit(q);
            q = new quadTableEntry("","","",GOTO,nullptr,nullptr,nullptr);
            quad_table->emit(q);  
        }    
    }
    ;

logical_AND_expression:
    equality_expression
    {
        $$ = $1;
    }
    | logical_AND_expression N AND M equality_expression
    {
        convBool2Int($5);
        backpatch($2->nextlist, quad_table->quadArray.size());
        convBool2Int($1);

        $$ = new Expression();
        $$->type = "bool";
        backpatch($1->truelist,$4);
        $$->truelist = $5->truelist;
        $$->falselist = merge($1->falselist,$5->falselist);
    }
    ;

logical_OR_expression:
    logical_AND_expression
    {
        $$ = $1;
    }
    |logical_OR_expression N OR M logical_AND_expression
    {
        convBool2Int($5);
        backpatch($2->nextlist, quad_table->quadArray.size());
        convBool2Int($1);

        $$ = new Expression();
        $$->type = "bool";
        backpatch($1->falselist,$4);
        $$->truelist = merge($1->truelist,$5->truelist);
        $$->falselist = $5->falselist;
    }
    ;

conditional_expression:
    logical_OR_expression
    {
        $$ = $1;
    }
    |logical_OR_expression N QSTMK M expression N COLN M conditional_expression
    {
        $$->loc = cur_symbol_table->gentemp($5->loc->type->type);
        quadTableEntry* q = new quadTableEntry($9->loc->name,"",$$->loc->name,ASSIGN,$9->loc,0,$$->loc);
        quad_table->emit(q);

        list<int> l = makelist(quad_table->quadArray.size());
        q = new quadTableEntry("","","",GOTO,0,0,0);
        quad_table->emit(q); 

        backpatch($6->nextlist,quad_table->quadArray.size());
        q = new quadTableEntry($5->loc->name,"",$$->loc->name,ASSIGN,$5->loc,0,$$->loc);
        quad_table->emit(q);       

        list<int> m = makelist(quad_table->quadArray.size());  
        l = merge(l,m);
        q = new quadTableEntry("","","",GOTO,0,0,0);
        quad_table->emit(q); 

        backpatch($2->nextlist,quad_table->quadArray.size());
        conv2Bool($1);

        backpatch($1->truelist, $4); 
        backpatch($1->falselist, $8);
        backpatch(l,quad_table->quadArray.size());

    }
    ;

assignment_expression:
    conditional_expression 
    {
        $$ = $1;
    }
    |unary_expression ASGN assignment_expression
    {
        if($1->atype == "arr"){
            if(!compareTypes($3->loc->type, $1->type))
                $3->loc = convertTypes($3->loc,$1->type->type);

            quadTableEntry* q = new quadTableEntry($1->loc->name,$3->loc->name,$1->array->name,BRT_EQ,$1->loc,$3->loc,$1->array);
            quad_table->emit(q);  

        }else if($1->atype == "ptr"){
            typecheck(&($3->loc),$1->loc);
            quadTableEntry* q = new quadTableEntry($3->loc->name,"",$1->array->name,STAR_ASSIGN,$3->loc,nullptr,$1->array);
            quad_table->emit(q);            
        }else{
            typecheck(&($3->loc),$1->array);
            quadTableEntry* q = new quadTableEntry($3->loc->name,"",$1->array->name,ASSIGN,$3->loc,nullptr,$1->array);
            quad_table->emit(q);
        }

        $$ = $3;
    }
    ;

expression:
    assignment_expression
    {
        $$ = $1;
    }
    ;

declaration:
    type_specifier init_declarator SCOLN{}
    ;

init_declarator:
    declarator
    {
        $$ = $1;
    }
    |declarator ASGN initializer
    {
        typecheck(&($3),$1);
        quadTableEntry *q = new quadTableEntry($3->name,"",$1->name,ASSIGN,$3,nullptr,$1);
        quad_table->emit(q);
    }
    ;

type_specifier:
    VOID{
        cur_type = VOID0;
    }
    |CHAR{
        cur_type = CHAR1;
    }
    |INT{
        cur_type = INT4;
    }
    ;

declarator:
    pointer direct_declarator
    {
        typeNode* t = new typeNode(PTR);
        t->next = $2->type;
        $2->update(t,$2->initial_value,$2->nested_table);
        $$ = $2;
    }
    |direct_declarator
    {
    }
    ;

direct_declarator:
    IDENTIFIER
    {
        $1.loc = cur_symbol_table->lookup(($1.var));
        $1.loc->update(new typeNode(cur_type), $1.loc->initial_value, $1.loc->nested_table);
        $$ = $1.loc;
        cur_symbol_entry = $$;
    }
    |IDENTIFIER SQBLT INTEGER_CONST SQBRT{
        $1.loc = cur_symbol_table->lookup(($1.var));
        $1.loc->update(new typeNode(cur_type), $1.loc->initial_value, $1.loc->nested_table);

        typeNode *t = new typeNode(ARRAY,$1.loc->type,$3);
        $1.loc->update(t,$1.loc->initial_value, $1.loc->nested_table);
        $$ = $1.loc;

        cur_symbol_entry = $$;
    }
    |PRA RDBLT changetable_dec parameter_list RDBRT
    {
        $1.loc = global_symbol_table->lookup(($1.var));
        // $1.loc->update(new typeNode(cur_type), $1.loc->initial_value, $1.loc->nested_table);

        SymbolTableEntry* ret =  cur_symbol_table->lookup("retVal");
        ret->update(new typeNode($1.loc->type->type),ret->initial_value, ret->nested_table);
    
        cur_symbol_table->parent = global_symbol_table;
        $1.loc->update(new typeNode(FUNCTION),$1.loc->initial_value,cur_symbol_table);
        $1.loc->type->next = copyType(ret->type);
        $1.loc->type->parameters = $4;
        cur_symbol_table = global_symbol_table;

        $$ = $1.loc;
        cur_symbol_entry = $$;

    }
    |PRA RDBLT changetable_dec RDBRT
    {
        $1.loc = global_symbol_table->lookup(($1.var));
        // $1.loc->update(new typeNode(cur_type), $1.loc->initial_value, $1.loc->nested_table);
        
        SymbolTableEntry* ret =  cur_symbol_table->lookup("retVal");
        ret->update(new typeNode($1.loc->type->type),ret->initial_value, ret->nested_table);


        cur_symbol_table->parent = global_symbol_table;
        $1.loc->update(new typeNode(FUNCTION),$1.loc->initial_value,cur_symbol_table);
        $1.loc->type->next = copyType(ret->type);
        // $1.loc->type->parameters = $4;
        cur_symbol_table = global_symbol_table;


        cur_symbol_entry = $$;
    }
    ;

PRA: IDENTIFIER{
    $1.loc = global_symbol_table->lookup(($1.var));
    $1.loc->update(new typeNode(cur_type), $1.loc->initial_value, $1.loc->nested_table);

    cur_symbol_entry = $1.loc;
    $$ = $1;
};

pointer:
    MULT
    ;

parameter_list:
    parameter_declaration {
        $$ = $1;
    }
    |parameter_list COMMA parameter_declaration 
    {
        typeNode *tm = $1;
        while(tm->next){
            tm = tm->next;
        }
        tm->next = $3;
        $$ = $1;
    }
    ;

parameter_declaration:
    type_specifier pointer IDENTIFIER
    {
        $3.loc = cur_symbol_table->lookup(($3.var));
        $3.loc->update(new typeNode(cur_type), $3.loc->initial_value, $3.loc->nested_table);     

        typeNode* t = new typeNode(PTR);
        t->next = $3.loc->type;

        $$ = new typeNode(PTR);
        $$->next = new typeNode(cur_type);
        $$->next->next = new typeNode(DEFLT);
        $3.loc->update(t,$3.loc->initial_value,$3.loc->nested_table);
    }
    |type_specifier IDENTIFIER
    {
        $$ = new typeNode(cur_type);
        $$->next = new typeNode(DEFLT);
        $2.loc = cur_symbol_table->lookup(($2.var));

        $2.loc->update(new typeNode(cur_type), $2.loc->initial_value, $2.loc->nested_table);
    }
    |type_specifier pointer
    {
        $$ = new typeNode(PTR);
        $$->next = new typeNode(cur_type);
        $$->next->next = new typeNode(DEFLT);
    }
    |type_specifier
    {
        $$ = new typeNode(cur_type);
        $$->next = new typeNode(DEFLT);        
    }
    ;

initializer:
    assignment_expression
    {
        $$ = $1->loc;
    }
    ;

statement:
    compound_statement 
    {
        $$ = $1;
    }
    |expression_statement
    {
        $$ = new Statement();
        $$->nextlist = $1->nextlist;
    }
    |selection_statement
    {
        $$ = $1;
    }
    |iteration_statement
    {
        $$ = $1;
    }
    |jump_statement
    {
        $$ = $1;
    }
    ;

compound_statement:
    CRBLT block_item_list_opt CRBRT
    {
        $$ = $2;
    }
    ;

block_item_list:
    block_item
    {
        $$ = $1;
    }
    |block_item_list M block_item
    {
        $$ = $3;
        backpatch($1->nextlist,$2);
    }
    ;
    
block_item_list_opt:
    block_item_list
    {
        $$ = $1;
    }
    |
    {
        $$ = new Statement();;
    }
    ;

block_item:
    declaration
    {
        $$ = new Statement();
    }
    |statement
    {
        $$ = $1;
    }
    ;

expression_statement:
    expression SCOLN
    {
        $$=$1;
    }
    |
    SCOLN
    {
        $$ = new Expression();
    }
    ;

selection_statement:
    IF RDBLT expression N RDBRT M statement N %prec "then"
    {
        backpatch($4->nextlist,quad_table->quadArray.size());
        conv2Bool($3);

        $$ = new Statement();
        backpatch($3->truelist, $6);
        list<int> temp = merge($3->falselist, $7->nextlist);
        $$->nextlist = merge($8->nextlist,temp);
    }
    |IF RDBLT expression N RDBRT M statement N ELSE M statement
    {
        backpatch($4->nextlist,quad_table->quadArray.size());
        conv2Bool($3);

        $$ = new Statement();
        backpatch($3->truelist, $6);
        backpatch($3->falselist, $10);
        list<int> temp = merge($7->nextlist, $8->nextlist);
        $$->nextlist = merge($11->nextlist,temp);
    }
    ;

iteration_statement:
    FOR RDBLT expression_statement M expression_statement RDBRT M statement
    {
        $$ = new Statement();
        conv2Bool($5);
        backpatch($5->truelist, $7);
        backpatch($8->nextlist, $4);
        quadTableEntry* q = new quadTableEntry("","",to_string($4),GOTO,0,0,0);
        quad_table->emit(q);
        $$->nextlist = $5->falselist;
    }
    |FOR RDBLT expression_statement M expression_statement M expression N RDBRT M statement
    {
        $$ = new Statement();
        conv2Bool($5);
        backpatch($5->truelist, $10);
        backpatch($8->nextlist, $4);
        backpatch($11->nextlist, $6);
        quadTableEntry* q = new quadTableEntry("","",to_string($6),GOTO,0,0,0);
        quad_table->emit(q);
        $$->nextlist = $5->falselist;
    }
	;

jump_statement:
    RETURN expression SCOLN
    {
        $$ = new Statement();
        quadTableEntry* q = new quadTableEntry($2->loc->name,"","",RETURN_EXPN,$2->loc,0,0);
        quad_table->emit(q);
    }
    |
    RETURN SCOLN
    {
        $$ = new Statement();
        quadTableEntry* q = new quadTableEntry("","","",RETURN_,0,0,0);
        quad_table->emit(q);
    }
    ;

translation_unit:
    external_declaration {}
    |translation_unit  external_declaration{}
    ;

external_declaration:
    function_definition {}
	|declaration {}
	;

function_definition:
    type_specifier declarator changetable_def compound_statement
    {
        cur_symbol_table = global_symbol_table;
    }
    ;

changetable_dec:
    {
        if(cur_symbol_entry->nested_table == nullptr){
            SymbolTable *s = new SymbolTable(cur_symbol_entry->name);
            cur_symbol_table = s;
        }
        else{
            cur_symbol_table = cur_symbol_entry->nested_table;
            // quad_table->emit(new quadTableEntry(cur_symbol_table->STName,"","",FUCN,cur_symbol_entry,nullptr, nullptr));
        }
    }
    ;

changetable_def:
    {
        cur_symbol_table = cur_symbol_entry->nested_table;
        quad_table->emit(new quadTableEntry(cur_symbol_table->STName,"","",FUCN,cur_symbol_entry,nullptr, nullptr));
    }
    ;

%%

int yyerror(char const *s) {
    // printf("error at %d",yylineno);
    return 0;
}


