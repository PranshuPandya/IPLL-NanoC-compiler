#include "A6_36.h"
#include "A6_36.tab.h"

string in_file, asm_file;
ActivationRecord *cur_ar;
ofstream asmFile;
map<int, map<int, string>> num_to_reg = {{1, {{1, "dil"}, {4, "edi"}, {8, "rdi"}}}, {2, {{1, "sil"}, {4, "esi"}, {8, "rsi"}}}, {3, {{1, "dl"}, {4, "edx"}, {8, "rdx"}}}, {4, {{1, "cl"}, {4, "ecx"}, {8, "rcx"}}}};

map<char, int> esc_to_ascii = {{'n', 10}, {'t', 9}, {'r', 13}, {'b', 8}, {'f', 12}, {'v', 11}, {'a', 7}, {'0', 0}};

int get_ascii(string cc)
{
    if (cc.length() == 3)
    {
        return (int)cc[1];
    }
    else
    {
        if (esc_to_ascii.find(cc[2]) != esc_to_ascii.end())
        {
            return esc_to_ascii[cc[2]];
        }
        else
        {
            return (int)cc[2];
        }
    }
}

string find_register(string name, int number, int size)
{
    string regis = num_to_reg[number][size];
    return "%" + regis;
}

string stack_location(string name)
{
    if (cur_ar->displacement.count(name))
        return to_string(cur_ar->displacement[name]) + "(%rbp)";
    else
        return name;
}

void storing_paramter(SymbolTableEntry *symbol, int number)
{
    // SymbolTableEntry *symbol = cur_symbol_table->lookup(name);
    string name = symbol->name;
    int size = symbol->size;
    typenode_types type = symbol->type->type;
    string instr = "";
    if (type == ARRAY)
    {
        instr = "leaq";
        size = 8;
    }
    else if (size == 1)
    {
        instr = "movb";
    }
    else if (size == 4)
    {
        instr = "movl";
    }
    else if (size == 8)
    {
        instr = "movq";
    }
    string regis = find_register(name, number, size);
    asmFile << "\t" << setw(8) << instr << stack_location(name) << ", " << regis << "\n";
}

void parameter(string name, int number)
{
    SymbolTableEntry *symbol = cur_symbol_table->lookup(name);
    // string name = symbol->name;
    int size = symbol->size;
    typenode_types type = symbol->type->type;
    string instr = "";
    if (type == ARRAY)
    {
        instr = "movq";
        size = 8;
    }
    else if (size == 1)
    {
        instr = "movb";
    }
    else if (size == 4)
    {
        instr = "movl";
    }
    else if (size == 8)
    {
        instr = "movq";
    }
    string regis = find_register(name, number, size);
    asmFile << "\t" << setw(8) << instr << regis << ", " << stack_location(name) << "\n";
}

void translate()
{
    // cout << "in translate" << "\n";
    asmFile.open(asm_file);
    asmFile << left;
    asmFile << "\t.file\t\"" + in_file + "\"" << "\n";
    asmFile << "\n";
    asmFile << "#\t"
            << "function variables and temp are allocated on the stack:\n"
            << "\n";
    for (auto &symbol : global_symbol_table->stable)
    {
        if (symbol->type->type == FUNCTION)
        {
            asmFile << "#\t" << symbol->name << "\n";
            for (auto &record : symbol->nested_table->activationRecord->displacement)
            {
                asmFile << "#\t" << record.first << ": " << record.second << "\n";
            }
        }
        if (symbol->type->type == PTR && symbol->type->next->type == FUNCTION)
        {
            asmFile << "#\t" << symbol->name << "\n";
            for (auto &record : symbol->nested_table->activationRecord->displacement)
            {
                asmFile << "#\t" << record.first << ": " << record.second << "\n";
            }
        }
    }
    asmFile << "\n";

    if (stringLiterals.size() > 0)
    {
        asmFile << "\t.section\t.rodata" << "\n";
        int i = 0;
        for (auto &stringLiteral : stringLiterals)
        {
            asmFile << ".LC" << i++ << ":" << "\n";
            asmFile << "\t.string\t" << stringLiteral << "\n";
        }
    }
    // set<string> global_in_quad;
    // for (auto &quad : quad_table->quadArray)
    // {
    //     if (quad->res_addr)
    //         global_in_quad.insert(quad->res_addr->name);
    // }
    for (auto &symbol : global_symbol_table->stable)
    {
        if (symbol->initial_value == nullptr && symbol->category == SymbolTableEntry::GLOBAL && global_initialized.find(symbol->name) == global_initialized.end())
        {
            // asmFile << "\t.comm\t" << symbol->name << "," << symbol->size << "," << symbol->size << "\n";
            if (symbol->type->type == INT4)
            {
                asmFile << "\t" << setw(8) << ".globl" << symbol->name << "\n";
                asmFile << "\t" << setw(8) << ".align" << 4 << "\n";
                asmFile << "\t" << setw(8) << ".type" << symbol->name << ", @object" << "\n";
                asmFile << "\t" << setw(8) << ".size" << symbol->name << ", 4" << "\n";
                asmFile << symbol->name << ":" << "\n";
                asmFile << "\t" << setw(8) << ".zero" << 4 << "\n";
            }
            else if (symbol->type->type == CHAR1)
            {
                asmFile << "\t" << setw(8) << ".globl" << symbol->name << "\n";
                asmFile << "\t" << setw(8) << ".type" << symbol->name << ", @object" << "\n";
                asmFile << "\t" << setw(8) << ".size" << symbol->name << ", 1" << "\n";
                asmFile << symbol->name << ":" << "\n";
                asmFile << "\t" << setw(8) << ".zero" << 1 << "\n";
            }
            else if (symbol->type->type == PTR)
            {
                // asmFile << "\t"
                //         << ".section	.data.rel.local" << "\n";
                asmFile << "\t" << setw(8) << ".globl" << symbol->name << "\n";
                asmFile << "\t" << setw(8) << ".align" << 8 << "\n";
                asmFile << "\t" << setw(8) << ".type" << symbol->name << ", @object" << "\n";
                asmFile << "\t" << setw(8) << ".size" << symbol->name << ", 8" << "\n";
                asmFile << symbol->name << ":" << "\n";
                asmFile << "\t" << setw(8) << ".zero" << 8 << "\n";
                // asmFile << "\t" << setw(8) << ".quad" << glb_strtemp << "\n";
            }
            else if (symbol->type->type == ARRAY)
            {
                asmFile << "\t" << setw(8) << ".globl" << symbol->name << "\n";
                asmFile << "\t" << setw(8) << ".bss" << "\n";
                if (symbol->type->next->type == INT4)
                {
                    asmFile << "\t" << setw(8) << ".align" << 16 << "\n";
                }
                else if (symbol->type->next->type == CHAR1)
                {
                    asmFile << "\t" << setw(8) << ".align" << 8 << "\n";
                }
                else if (symbol->type->next->type == PTR)
                {
                    if (symbol->type->next->next->type == INT4)
                    {
                        asmFile << "\t" << setw(8) << ".align" << 16 << "\n";
                    }
                    else if (symbol->type->next->next->type == CHAR1)
                    {
                        asmFile << "\t" << setw(8) << ".align" << 32 << "\n";
                    }
                }

                asmFile << "\t" << setw(8) << ".type" << symbol->name << ", @object" << "\n";
                asmFile << "\t" << setw(8) << ".size" << symbol->name << ", " << symbol->size << "\n";
                asmFile << symbol->name << ":" << "\n";
                asmFile << "\t" << setw(8) << ".zero" << symbol->size << "\n";
            }
        }
    }

    map<int, string> label_map;
    int num_of_quad = 0, labelNum = 0;
    for (auto &quad : quad_table->quadArray)
    {
        if (quad->ops == FUCN)
        {
            label_map[num_of_quad] = ".LFB" + to_string(labelNum);
        }
        else if (quad->ops == FUCNEND)
        {
            label_map[num_of_quad] = ".LFE" + to_string(labelNum);
            labelNum++;
        }
        num_of_quad++;
    }

    for (auto &quad : quad_table->quadArray)
    {
        if (quad->ops == GOTO || quad->ops == GOTOEQL || quad->ops == GOTONEQL || quad->ops == GOTOLT || quad->ops == GOTOGT || quad->ops == GOTOLTE || quad->ops == GOTOGTE)
        {
            int loc = stoi(quad->res);
            if (label_map.find(loc) == label_map.end())
            {
                label_map[loc] = ".L" + to_string(labelNum);
                labelNum++;
            }
        }
    }

    bool txt_spc = false;
    string glb_strtemp;
    int glb_inttemp, glb_chartemp;
    string fun_label;
    stack<SymbolTableEntry *> params;
    num_of_quad = 0;

    for (auto &quad : quad_table->quadArray)
    {
        asmFile << "# ";
        streambuf *coutbuf = cout.rdbuf();
        cout.rdbuf(asmFile.rdbuf());
        quad->printQuad();
        cout.rdbuf(coutbuf);
        if (quad->ops == FUCN)
        {
            if (!txt_spc)
            {
                asmFile << "\t.text" << "\n";
                txt_spc = true;
            }

            cur_symbol_table = global_symbol_table->lookup(quad->arg1)->nested_table;
            cur_ar = cur_symbol_table->activationRecord;

            fun_label = label_map[num_of_quad];
            fun_label[3] = 'E';
            asmFile << "\t" << setw(8) << ".globl" << quad->arg1 << "\n";
            asmFile << "\t" << setw(8) << ".type" << quad->arg1 << ", @function" << "\n";
            asmFile << quad->arg1 << ":" << "\n";
            asmFile << label_map[num_of_quad] << ":" << "\n";
            asmFile << "\t"
                    << ".cfi_startproc" << "\n";
            asmFile << "\t" << setw(8) << "pushq"
                    << "%rbp" << "\n";
            asmFile << "\t.cfi_def_cfa_offset 16" << "\n";
            asmFile << "\t.cfi_offset 6, -16" << "\n";
            asmFile << "\t" << setw(8) << "movq"
                    << "%rsp, %rbp" << "\n";
            asmFile << "\t.cfi_def_cfa_register 6" << "\n";
            asmFile << "\t" << setw(8) << "subq"
                    << "$" << -cur_ar->totalDisplacement << ", %rsp" << "\n";

            int number = 1;
            for (auto param : cur_symbol_table->stable)
            {
                if (param->category == SymbolTableEntry::PARAMETER)
                {
                    parameter(param->name, number);
                    number++;
                }
            }
        }
        else if (quad->ops == FUCNEND)
        {
            asmFile << label_map[num_of_quad] << ":" << "\n";
            asmFile << "\t" << setw(8) << "movq"
                    << "%rbp, %rsp" << "\n";
            asmFile << "\t" << setw(8) << "popq"
                    << "%rbp" << "\n";
            asmFile << "\t"
                    << ".cfi_def_cfa 7, 8" << "\n";
            asmFile << "\t"
                    << "ret" << "\n";
            asmFile << "\t"
                    << ".cfi_endproc" << "\n";
            asmFile << "\t" << setw(8) << ".size" << quad->arg1 << ", .-" << quad->arg1 << "\n";

            txt_spc = false;
        }
        else
        {
            if (txt_spc)
            {
                quad_ops op = quad->ops;
                string result = quad->res;
                string arg1 = quad->arg1;
                string arg2 = quad->arg2;
                SymbolTableEntry *arg1_addr = quad->arg1_addr;
                SymbolTableEntry *arg2_addr = quad->arg2_addr;
                SymbolTableEntry *res_addr = quad->res_addr;

                if (label_map.count(num_of_quad))
                {
                    asmFile << label_map[num_of_quad] << ":" << "\n";
                }

                if (op == ASSIGN)
                {
                    if (isdigit(arg1[0]))
                    {
                        // integer constant
                        asmFile << "\t" << setw(8) << "movl"
                                << "$" << arg1 << ", " << stack_location(result) << "\n";
                    }

                    else
                    {
                        int sz = arg1_addr->size;
                        if (sz == 1)
                        {
                            asmFile << "\t" << setw(8) << "movb" << stack_location(arg1) << ", %al" << "\n";
                            asmFile << "\t" << setw(8) << "movb"
                                    << "%al, " << stack_location(result) << "\n";
                        }
                        else if (sz == 4)
                        {
                            asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", %eax" << "\n";
                            asmFile << "\t" << setw(8) << "movl"
                                    << "%eax, " << stack_location(result) << "\n";
                        }
                        else if (sz == 8)
                        {
                            asmFile << "\t" << setw(8) << "movq" << stack_location(arg1) << ", %rax" << "\n";
                            asmFile << "\t" << setw(8) << "movq"
                                    << "%rax, " << stack_location(result) << "\n";
                        }
                    }
                }
                else if (op == ASSIGN_CHAR)
                {
                    // character constant
                    asmFile << "\t" << setw(8) << "movb"
                            << "$" << arg1 << ", " << stack_location(result) << "\n";
                }
                else if (op == STRING_ASSIGN)
                {
                    asmFile << "\t" << setw(8) << "movq"
                            << "$.LC" << arg1 << ", " << stack_location(result) << "\n";
                }
                else if (op == PARAM)
                {
                    params.push(arg1_addr);
                }
                else if (op == CALL)
                {
                    int paramCount = stoi(arg2);
                    // cout<<params.size()<<" "<< paramCount;
                    while (paramCount)
                    {
                        storing_paramter(params.top(), paramCount);
                        params.pop();
                        paramCount--;
                    }
                    asmFile << "\t" << setw(8) << "call" << arg1 << "\n";
                    int sz = res_addr->size;
                    if (sz == 1)
                    {
                        asmFile << "\t" << setw(8) << "movb"
                                << "%al, " << stack_location(result) << "\n";
                    }
                    else if (sz == 4)
                    {
                        asmFile << "\t" << setw(8) << "movl"
                                << "%eax, " << stack_location(result) << "\n";
                    }
                    else if (sz == 8)
                    {
                        asmFile << "\t" << setw(8) << "movq"
                                << "%rax, " << stack_location(result) << "\n";
                    }
                }
                else if (op == RETURN_)
                {

                    if (quad_table->quadArray[num_of_quad]->ops != FUCNEND)
                        asmFile << "\t" << setw(8) << "jmp" << fun_label << "\n";
                }
                else if (op == RETURN_EXPN)
                {

                    int sz = arg1_addr->size;
                    if (sz == 1)
                    {
                        asmFile << "\t" << setw(8) << "movb" << stack_location(arg1) << ", %al" << "\n";
                    }
                    else if (sz == 4)
                    {
                        asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", %eax" << "\n";
                    }
                    else if (sz == 8)
                    {
                        asmFile << "\t" << setw(8) << "movq" << stack_location(arg1) << ", %rax" << "\n";
                    }
                    if (quad_table->quadArray[num_of_quad]->ops != FUCNEND)
                        asmFile << "\t" << setw(8) << "jmp" << fun_label << "\n";
                }
                else if (op == GOTO)
                {
                    asmFile << "\t" << setw(8) << "jmp" << label_map[stoi(result)] << "\n";
                }
                else if (op == GOTOEQL || op == GOTONEQL || op == GOTOLT || op == GOTOLTE || op == GOTOGT || op == GOTOGTE)
                {
                    int sz = arg1_addr->size;
                    string movins, cmpins, movreg;
                    if (sz == 1)
                    {
                        movins = "movb";
                        cmpins = "cmpb";
                        movreg = "%al";
                    }
                    else if (sz == 4)
                    {
                        movins = "movl";
                        cmpins = "cmpl";
                        movreg = "%eax";
                    }
                    else if (sz == 8)
                    {
                        movins = "movq";
                        cmpins = "cmpq";
                        movreg = "%rax";
                    }
                    asmFile << "\t" << setw(8) << movins << stack_location(arg2) << ", " << movreg << "\n";
                    asmFile << "\t" << setw(8) << cmpins << movreg << ", " << stack_location(arg1) << "\n";
                    if (op == GOTOEQL)
                    {
                        asmFile << "\t" << setw(8) << "je" << label_map[stoi(result)] << "\n";
                    }
                    else if (op == GOTONEQL)
                    {
                        asmFile << "\t" << setw(8) << "jne" << label_map[stoi(result)] << "\n";
                    }
                    else if (op == GOTOLT)
                    {
                        asmFile << "\t" << setw(8) << "jl" << label_map[stoi(result)] << "\n";
                    }
                    else if (op == GOTOLTE)
                    {
                        asmFile << "\t" << setw(8) << "jle" << label_map[stoi(result)] << "\n";
                    }
                    else if (op == GOTOGT)
                    {
                        asmFile << "\t" << setw(8) << "jg" << label_map[stoi(result)] << "\n";
                    }
                    else if (op == GOTOGTE)
                    {
                        asmFile << "\t" << setw(8) << "jge" << label_map[stoi(result)] << "\n";
                    }
                }
                else if (op == PLUS)
                {
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "addl" << stack_location(arg2) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "movl"
                            << "%eax"
                            << ", " << stack_location(result) << "\n";
                }
                else if (op == MINUS)
                {
                    // result = arg1 - arg2

                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "subl" << stack_location(arg2) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "movl"
                            << "%eax"
                            << ", " << stack_location(result) << "\n";
                }
                else if (op == INTO)
                {
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", "
                            << "%eax" << "\n";
                    if (isdigit(arg2[0]))
                    {
                        asmFile << "\t" << setw(8) << "imull"
                                << "$" + stack_location(arg2) << ", "
                                << "%eax" << "\n";
                    }
                    else
                    {
                        asmFile << "\t" << setw(8) << "imull" << stack_location(arg2) << ", "
                                << "%eax" << "\n";
                    }
                    asmFile << "\t" << setw(8) << "movl"
                            << "%eax"
                            << ", " << stack_location(result) << "\n";
                }
                else if (op == DIVISION)
                {
                    // result = arg1  / arg2
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "cdq" << "\n";
                    asmFile << "\t" << setw(8) << "idivl" << stack_location(arg2) << "\n";
                    asmFile << "\t" << setw(8) << "movl"
                            << "%eax"
                            << ", " << stack_location(result) << "\n";
                }
                else if (op == PERCENT)
                {
                    // result = arg1 % arg2
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "cdq" << "\n";
                    asmFile << "\t" << setw(8) << "idivl" << stack_location(arg2) << "\n";
                    asmFile << "\t" << setw(8) << "movl"
                            << "%edx"
                            << ", " << stack_location(result) << "\n";
                }
                else if (op == EQ_BRT)
                {
                    // result = arg1[arg2]
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg2) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "cltq" << "\n";
                    if (arg1_addr->category == SymbolTableEntry::GLOBAL)
                    {
                        asmFile << "\t" << setw(8) << "leaq" << arg1 << "(%rip) , %rdx" << "\n";
                        asmFile << "\t" << setw(8) << "movl"
                                << "(%rax,%rdx)"
                                << ", "
                                << "%eax" << "\n";

                        // leaq	a(%rip) , %rdx
                        // movl    (%rax, %rdx), %eax
                    }
                    else
                    {
                        asmFile << "\t" << setw(8) << "movl" << cur_ar->displacement[arg1] << "(%rbp, %rax, 1)"
                                << ", "
                                << "%eax" << "\n";
                    }
                    asmFile << "\t" << setw(8) << "movl"
                            << "%eax"
                            << ", " << stack_location(result) << "\n";
                }
                else if (op == BRT_EQ)
                {
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "cltq" << "\n";
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg2) << ", "
                            << "%ebx" << "\n";
                    if (res_addr->category == SymbolTableEntry::GLOBAL)
                    {
                        asmFile << "\t" << setw(8) << "leaq" << result << "(%rip) , %rdx" << "\n";
                        asmFile << "\t" << setw(8) << "movl"
                                << "%ebx"
                                << ", "
                                << "(%rax,%rdx)" << "\n";

                        // leaq    a(%rip) , %rdx
                        // movl %ebx, (%rax, %rdx)
                    }
                    else
                    {
                        asmFile << "\t" << setw(8) << "movl"
                                << "%ebx"
                                << ", " << cur_ar->displacement[result] << "(%rbp, %rax,1)" << "\n";
                    }
                }
                else if (op == U_ADDR)
                {
                    // result = &arg1
                    if (arg1_addr->type->type == ARRAY)
                    {
                        if (arg1_addr->category == SymbolTableEntry::GLOBAL)
                        {
                            asmFile << "\t" << setw(8) << "leaq" << arg1 << "(%rip) , %rdx" << "\n";
                            // asmFile << "\t" << setw(8) << "movl" << stack_location(arg2)<< ", %eax" << "\n";
                            asmFile << "\t" << setw(8) << "leaq"
                                    << "(%rax,%rdx)"
                                    << ", "
                                    << "%rax" << "\n";
                        }
                        else
                        {
                            asmFile << "\t" << setw(8) << "movl" << stack_location(arg2) << ", %eax" << "\n";
                            asmFile << "\t" << setw(8) << "leaq" << to_string(cur_ar->displacement[arg1]) << "(%rax,%rbp)"
                                    << ", "
                                    << "%rax" << "\n";
                        }
                        asmFile << "\t" << setw(8) << "movq"
                                << "%rax"
                                << ", " << stack_location(result) << "\n";
                    }
                    else
                    {
                        asmFile << "\t" << setw(8) << "leaq" << stack_location(arg1) << ", "
                                << "%rax" << "\n";
                        asmFile << "\t" << setw(8) << "movq"
                                << "%rax"
                                << ", " << stack_location(result) << "\n";
                    }
                }
                else if (op == U_STAR)
                {
                    // result = *arg1
                    if (arg1_addr->type->type == ARRAY)
                    {
                        asmFile << "\t" << setw(8) << "movl" << stack_location(arg2) << ", %eax" << "\n";
                        asmFile << "\t" << setw(8) << "leaq" << to_string(cur_ar->displacement[arg1]) << "(%rax,%rbp)"
                                << ", "
                                << "%rax" << "\n";
                    }
                    else
                    {
                        asmFile << "\t" << setw(8) << "movq" << stack_location(arg1) << ", "
                                << "%rax" << "\n";
                    }
                    asmFile << "\t" << setw(8) << "movl"
                            << "(%rax)"
                            << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "movl"
                            << "%eax"
                            << ", " << stack_location(result) << "\n";
                }
                else if (op == U_MINUS)
                {
                    // result = -arg1
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "negl"
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "movl"
                            << "%eax"
                            << ", " << stack_location(result) << "\n";
                }
                else if (op == STAR_ASSIGN)
                {
                    // *result = arg1
                    asmFile << "\t" << setw(8) << "movl" << stack_location(arg1) << ", "
                            << "%eax" << "\n";
                    asmFile << "\t" << setw(8) << "movq" << stack_location(result) << ", "
                            << "%rbx" << "\n";
                    asmFile << "\t" << setw(8) << "movl"
                            << "%eax"
                            << ", "
                            << "(%rbx)" << "\n";
                }
            }
            else
            {
                cur_symbol_entry = global_symbol_table->lookup(quad->res);
                if (cur_symbol_entry->category == SymbolTableEntry::TEMPORARY)
                {
                    if (cur_symbol_entry->type->type == INT4)
                    {
                        glb_inttemp = stoi(quad->arg1);
                    }
                    else if (cur_symbol_entry->type->type == CHAR1)
                    {
                        glb_chartemp = stoi(quad->arg1);
                    }
                    else if (cur_symbol_entry->type->type == PTR)
                    {
                        glb_strtemp = ".LC" + quad->arg1;
                    }
                }
                else
                {
                    if (cur_symbol_entry->type->type == INT4)
                    {
                        asmFile << "\t" << setw(8) << ".globl" << cur_symbol_entry->name << "\n";
                        asmFile << "\t" << setw(8) << ".data" << "\n";
                        asmFile << "\t" << setw(8) << ".align" << 4 << "\n";
                        asmFile << "\t" << setw(8) << ".type" << cur_symbol_entry->name << ", @object" << "\n";
                        asmFile << "\t" << setw(8) << ".size" << cur_symbol_entry->name << ", 4" << "\n";
                        asmFile << cur_symbol_entry->name << ":" << "\n";
                        asmFile << "\t" << setw(8) << ".long" << glb_inttemp << "\n";
                    }
                    else if (cur_symbol_entry->type->type == CHAR1)
                    {
                        asmFile << "\t" << setw(8) << ".globl" << cur_symbol_entry->name << "\n";
                        asmFile << "\t" << setw(8) << ".data" << "\n";
                        asmFile << "\t" << setw(8) << ".type" << cur_symbol_entry->name << ", @object" << "\n";
                        asmFile << "\t" << setw(8) << ".size" << cur_symbol_entry->name << ", 1" << "\n";
                        asmFile << cur_symbol_entry->name << ":" << "\n";
                        asmFile << "\t" << setw(8) << ".byte" << glb_chartemp << "\n";
                    }
                    else if (cur_symbol_entry->type->type == PTR)
                    {
                        asmFile << "\t" << setw(8) << ".globl" << cur_symbol_entry->name << "\n";
                        asmFile << "\t"
                                << ".section	.data.rel.local" << "\n";
                        asmFile << "\t" << setw(8) << ".align" << 8 << "\n";
                        asmFile << "\t" << setw(8) << ".type" << cur_symbol_entry->name << ", @object" << "\n";
                        asmFile << "\t" << setw(8) << ".size" << cur_symbol_entry->name << ", 8" << "\n";
                        asmFile << cur_symbol_entry->name << ":" << "\n";
                        asmFile << "\t" << setw(8) << ".quad" << glb_strtemp << "\n";
                    }
                }
            }
        }
        num_of_quad++;
    }
    asmFile.close();
}
int main(int argc, char const *argv[])
{
    // yydebug = 1;
    global_symbol_table = new SymbolTable("Global");
    cur_symbol_table = global_symbol_table;
    quad_table = new quadTable();
    // Welcoming

    cout << "Welcome to the NanoC Compiler Interface developed by Pranshu Pandya and Pranshu Kandoi." << "\n";
    cout << "=======================================================================================" << "\n";
    // int widthname = 20;
    // int widthtype = 35;
    // int widthinitval = 17;
    // int widthsize = 8;
    // int widthoffset = 10;
    // int widthnestedtab = 17;
    // int totalwidth = widthinitval + widthname + widthnestedtab + widthoffset + widthsize + widthtype;
    // cout << setfill('=') << setw(totalwidth) << "=" << "\n";
    // cout << setfill(' ') << left << setw(widthname) << "| Name"
    //      << left << setw(widthtype) << "| Type"
    //      << left << setw(widthinitval) << "| Initial Value"
    //      << left << setw(widthsize) << "| Size"
    //      << left << setw(widthoffset) << "| Offset"
    //      << left << setw(widthnestedtab) << "| Nested Table |" << "\n";
    // cout << setfill('=') << setw(totalwidth) << "=" << "\n";

    // Create a sample row for the table
    // string name = "sample_field";
    // string type = "int";
    // string initial_value = "0";
    // string size = "4";
    // string offset = "0";
    // string nested_table = "";
    // cout << setfill(' ') << left << setw(widthname) << "| " + name
    //      << left << setw(widthtype) << "| " + type
    //      << left << setw(widthinitval) << "| " + initial_value
    //      << left << setw(widthsize) << "| " + size
    //      << left << setw(widthoffset) << "| " + offset
    //      << left << setw(widthnestedtab) << "| " + nested_table << "|" << "\n";

    // // Create the bottom border of the table
    // cout << setfill('=') << setw(totalwidth) << "=" << "\n";

    // return 0;

    in_file = string(argv[1]) + ".c";
    asm_file = string(argv[1]) + ".s";

    yyin = fopen(in_file.c_str(), "r");

    int res = yyparse();
    if (res != 0)
    {
        printf("\nSome Error Occured!\n");
    }
    else
    {
        printf("\nParsing Succesfull.\n");
    }
    finalBackpatch();

    global_symbol_table->update();
    global_symbol_table->printSymbolTable();
    quad_table->printQuadTable();
    // // return 0;
    translate();
    return 0;
}
