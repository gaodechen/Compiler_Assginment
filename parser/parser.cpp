/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Parser
 * @LastEditTime: 2020-05-17 18:12:34
 * @Date: 2020-04-22 22:31:19
 */

#include "../parser/parser.h"

Parser::Parser(LexTable *_m_lex_table)
{
    m_lex_table = _m_lex_table;
}

bool Parser::IsType(int type)
{
    return m_cur_lex.GetType() == type;
}

void Parser::GetNextSymbol()
{
    m_cur_lex = m_lex_table->GetNextSymbol();
    m_cur_line = m_lex_table->GetLineNum();
}

void Parser::GetPrevSymbol()
{
    m_cur_lex = m_lex_table->GetPrevSymbol();
    m_cur_line = m_lex_table->GetLineNum();
}

InsTable Parser::Analyze(bool display_tree)
{
    GetNextSymbol();
    Parse(0, 0);
    if (display_tree)
    {
        m_ast.Display();
    }
    return m_ins_table;
}

int Parser::Parse(int level, int index)
{
    m_ast.Forward("process");
    int jmp_addr = m_ins_table.GetPC();
    int offset = 0;
    int num_vars = 0;
    bool def_proc = false;

    m_ins_table.Generate(JMP_INS);

    while (true)
    {
        if (IsType(VocabTypes::D_CONST))
        {
            offset += _const(level, index + offset);
        }
        else if (IsType(VocabTypes::D_VAR))
        {
            num_vars += _var(level, index + offset);
            offset += num_vars;
        }
        else if (IsType(VocabTypes::D_PROC))
        {
            offset += _procedure(level + 1, index + offset);
            def_proc = true;
        }
        else
        {
            break;
        }
    }

    if (def_proc)
    {
        m_ins_table[jmp_addr].offset = m_ins_table.GetPC();
    }
    else
    {
        m_ins_table.DecPC();
    }
    

    m_ins_table.Generate(INT_INS, 0, DATA_OFFSET + num_vars);
    _statement(level, index + offset);
    m_ins_table.Generate(OPR_INS, 0, RET_OP);

    m_ast.Backward();

    return offset;
}

void Parser::TypeTest(int vocab_type)
{
    if (IsType(vocab_type))
    {
        return;
    }
    ErrorTypes error_type;
    switch (vocab_type)
    {
        case VocabTypes::IDENTIFIER_DATA_TYPE:
            error_type = MISSING_IDENTIFIER_ERROR;
            break;
        case VocabTypes::AOP_ASSIGN:
            error_type = MISSING_ASSIGNMENT_OPERATOR_ERROR;
            break;
        case VocabTypes::LOP_EQL:
            error_type = MISSING_ASSIGNMENT_OPERATOR_ERROR;
            break;
        case VocabTypes::CONST_DATA_TYPE:
            error_type = MISSING_ASSIGNMENT_RHS_ERROR;
            break;
        case VocabTypes::CH_SEMI:
            error_type = MISSING_END_CHARACTER;
            break;
        case VocabTypes::CP_THEN:
            error_type = MISSING_THEN_CLAUSE_ERROR;
            break;
        case VocabTypes::CP_END:
            error_type = MISSING_END_CLAUSE_ERROR;
            break;
        case VocabTypes::CP_DO:
            error_type = MISSING_DO_CLAUSE_ERROR;
            break;
        case VocabTypes::CH_LPAREN:
            error_type = MISSING_LPAREN_ERROR;
            break;
    }
    GlobalErrors::CatchError(error_type, m_cur_line);
}

void Parser::SepChTest(int req_type_1, int req_type_2)
{
    if (!IsType(req_type_1) && !IsType(req_type_2))
    {
        GlobalErrors::CatchError(MISSING_END_CHARACTER, m_cur_line);
    }
}

void Parser::LopChTest()
{
    int sym_type = m_cur_lex.GetType();
    for (int i = 0; i < VocabTypes::VOCAB_LOP_SIZE; i++)
    {
        if (sym_type == VocabTypes::m_list_LOP[i])
        {
            return;
        }
    }
    GlobalErrors::CatchError(MISSING_LOGIC_OPT_ERROR, m_cur_line);
}

void Parser::MultiDefTest(int index)
{
    int found_index = m_sym_table.Find(m_cur_lex.GetToken(), 0, index);
    if (found_index != -1)
    {
        GlobalErrors::CatchError(MUTIPLE_IDENTIFIER_DEFINITION_ERROR, m_cur_line);
    }
}

int Parser::DefTypeTest(int index, int req_type)
{
    int found_index = m_sym_table.Find(m_cur_lex.GetToken(), 0, index);
    if (found_index == -1)
    {
        GlobalErrors::CatchError(UNDEFINED_IDENTIFIER_ERROR, m_cur_line);
    }
    else if (m_sym_table[found_index].GetType() != req_type)
    {
        GlobalErrors::CatchError(SYNTAX_OR_TYPE_ERROR, m_cur_line);
    }
    return found_index;
}


int Parser::_const(int level, int index)
{
    m_ast.Forward("const");
    int offset = 0;
    // ident -> assign -> const
    Symbol symbol;
    symbol.SetType(VocabTypes::CONST_DEF_TYPE);
    do
    {
        // Get identifier
        GetNextSymbol();
        TypeTest(VocabTypes::IDENTIFIER_DATA_TYPE);
        MultiDefTest(index);
        symbol.SetToken(m_cur_lex.GetToken());
        // Get assignment operator
        GetNextSymbol();
        TypeTest(VocabTypes::LOP_EQL);
        // Get right value
        GetNextSymbol();
        TypeTest(VocabTypes::CONST_DATA_TYPE);
        symbol.SetValue(Str2Int(m_cur_lex.GetToken()));
        // Insert symbol
        m_sym_table[index + offset++] = symbol;
        // Separate characters
        GetNextSymbol();
        SepChTest(VocabTypes::CH_COMMA, VocabTypes::CH_SEMI);
    } while (!IsType(VocabTypes::CH_SEMI));
    GetNextSymbol();
    m_ast.Backward();
    return offset;
}

int Parser::_var(int level, int index)
{
    m_ast.Forward("var");
    int offset = 0;
    Symbol symbol;
    symbol.SetType(VocabTypes::VAR_DEF_TYPE);
    symbol.SetLevel(level);
    symbol.SetAddress(0);
    do
    {
        // Identifier
        GetNextSymbol();
        TypeTest(VocabTypes::IDENTIFIER_DATA_TYPE);
        MultiDefTest(index + offset);
        symbol.SetToken(m_cur_lex.GetToken());
        // Insert symbol
        m_sym_table[index + offset++] = symbol;
        symbol.SetAddress(symbol.GetAddress() + 1);
        // Separate characters
        GetNextSymbol();
        SepChTest(VocabTypes::CH_COMMA, VocabTypes::CH_SEMI);
    } while (!IsType(VocabTypes::CH_SEMI));
    GetNextSymbol();
    m_ast.Backward();
    return offset;
}

int Parser::_procedure(int level, int index)
{
    m_ast.Forward("procedure");
    int offset = 0;
    Symbol symbol;
    // Identifier
    GetNextSymbol();
    TypeTest(VocabTypes::IDENTIFIER_DATA_TYPE);
    // Set up symbol
    symbol.SetToken(m_cur_lex.GetToken());
    symbol.SetType(VocabTypes::PROCEDURE_DEF_TYPE);
    symbol.SetLevel(level - 1);
    symbol.SetAddress(m_ins_table.GetPC());
    m_sym_table[index + offset++] = symbol;
    // Filter semi within definition
    GetNextSymbol();
    TypeTest(VocabTypes::CH_SEMI);
    // Recurse
    GetNextSymbol();
    Parse(level, index + offset);
    // Filter semi in the end of procedure
    TypeTest(VocabTypes::CH_SEMI);
    GetNextSymbol();
    m_ast.Backward();
    return offset;
}

void Parser::_statement(int level, int index)
{
    m_ast.Forward("statement");
    switch (m_cur_lex.GetType())
    {
    case VocabTypes::CP_IF:
        GetNextSymbol();
        _if(level, index);
        break;
    case VocabTypes::CP_WHILE:
        GetNextSymbol();
        _while(level, index);
        break;
    case VocabTypes::CP_CALL:
        GetNextSymbol();
        _call(level, index);
        break;
    case VocabTypes::F_WRITE:
        GetNextSymbol();
        _write(level, index);
        break;
    case VocabTypes::F_READ:
        GetNextSymbol();
        _read(level, index);
        break;
    case VocabTypes::CP_BEGIN:
        GetNextSymbol();
        _begin(level, index);
        break;
    case VocabTypes::IDENTIFIER_DATA_TYPE:
        _assign(level, index);
        break;
    }
    m_ast.Backward();
}

void Parser::_if(int level, int index)
{
    m_ast.Forward("if");
    // condition
    _condition(level, index);
    int cpc = m_ins_table.GetPC();
    m_ins_table.Generate(JPC_INS);
    // Filter then clause
    TypeTest(VocabTypes::CP_THEN);
    GetNextSymbol();
    // if body
    _statement(level, index);
    m_ins_table[cpc].offset = m_ins_table.GetPC();
    m_ast.Backward();
}

void Parser::_while(int level, int index)
{
    m_ast.Forward("while");
    int cpc = m_ins_table.GetPC();
    // condition
    _condition(level, index);
    int jpc = m_ins_table.GetPC();
    m_ins_table.Generate(JPC_INS);
    // Filter do clause
    TypeTest(VocabTypes::CP_DO);
    GetNextSymbol();
    _statement(level, index);
    m_ins_table.Generate(JMP_INS, 0, cpc);
    m_ins_table[jpc].offset = m_ins_table.GetPC();
    m_ast.Backward();
}

void Parser::_call(int level, int index)
{
    m_ast.Forward("call");
    TypeTest(VocabTypes::IDENTIFIER_DATA_TYPE);
    int sym_index = DefTypeTest(index, VocabTypes::PROCEDURE_DEF_TYPE);
    int sym_level = m_sym_table[sym_index].GetLevel();
    int sym_address = m_sym_table[sym_index].GetAddress();
    m_ins_table.Generate(CAL_INS, level - sym_level, sym_address);
    GetNextSymbol();
    m_ast.Backward();
}

void Parser::_read(int level, int index)
{
    m_ast.Forward("read");
    // Filter left paren
    TypeTest(VocabTypes::CH_LPAREN);
    while (!IsType(VocabTypes::CH_RPAREN))
    {
        GetNextSymbol();
        TypeTest(VocabTypes::IDENTIFIER_DATA_TYPE);
        int sym_index = DefTypeTest(index, VocabTypes::VAR_DEF_TYPE);
        int sym_level = m_sym_table[sym_index].GetLevel();
        int sym_address = m_sym_table[sym_index].GetAddress();
        m_ins_table.Generate(OPR_INS, 0, READ_OP);
        m_ins_table.Generate(STO_INS, level - sym_level, DATA_OFFSET + sym_address);
        GetNextSymbol();
        SepChTest(VocabTypes::CH_COMMA, VocabTypes::CH_RPAREN);
    }
    GetNextSymbol();
    m_ast.Backward();
}

void Parser::_write(int level, int index)
{
    m_ast.Forward("write");
    // Filter left paren
    TypeTest(VocabTypes::CH_LPAREN);
    while (!IsType(VocabTypes::CH_RPAREN))
    {
        GetNextSymbol();
        _expression(level, index);
        m_ins_table.Generate(OPR_INS, 0, WRITE_OP);
        m_ins_table.Generate(OPR_INS, 0, WRITE_LINE_OP);
        SepChTest(VocabTypes::CH_COMMA, VocabTypes::CH_RPAREN);
    }
    GetNextSymbol();
    m_ast.Backward();
}

void Parser::_assign(int level, int index)
{
    m_ast.Forward("assign");
    int sym_index = DefTypeTest(index, VocabTypes::VAR_DEF_TYPE);
    int sym_level = m_sym_table[sym_index].GetLevel();
    int sym_address = m_sym_table[sym_index].GetAddress();
    // Filter assignment operator
    GetNextSymbol();
    TypeTest(VocabTypes::AOP_ASSIGN);
    // expression as right value
    GetNextSymbol();
    _expression(level, index);
    m_ins_table.Generate(STO_INS, level - sym_level, DATA_OFFSET + sym_address);
    m_ast.Backward();
}

void Parser::_begin(int level, int index)
{
    m_ast.Forward("begin");
    _statement(level, index);
    while (IsType(VocabTypes::CH_SEMI))
    {
        GetNextSymbol();
        _statement(level, index);
    }
    TypeTest(VocabTypes::CP_END);
    GetNextSymbol();
    m_ast.Backward();
}

void Parser::_expression(int level, int index)
{
    m_ast.Forward("expression");
    if (IsType(VocabTypes::AOP_PLUS) || IsType(VocabTypes::AOP_MINUS))
    {
        GetNextSymbol();
    }
    _factor(level, index);
    if (IsType(VocabTypes::AOP_MINUS))
    {
        m_ins_table.Generate(LIT_INS);
        m_ins_table.Generate(OPR_INS, 0, MINUS_OP);
    }
    do
    {
        int tmp_type = m_cur_lex.GetType();
        if (IsType(VocabTypes::AOP_PLUS) || IsType(VocabTypes::AOP_MINUS))
        {
            GetNextSymbol();
            _factor(level, index);
            if (tmp_type == VocabTypes::AOP_PLUS)
            {
                m_ins_table.Generate(OPR_INS, 0, ADD_OP);
            }
            else
            {
                m_ins_table.Generate(OPR_INS, 0, MINUS_OP);
            }
        }
    } while(IsType(VocabTypes::AOP_PLUS) || IsType(VocabTypes::AOP_MINUS));
    m_ast.Backward();
}

void Parser::_factor(int level, int index)
{
    m_ast.Forward("factor");
    _term(level, index);
    int tmp_type = m_cur_lex.GetType();
    if (!IsType(VocabTypes::AOP_TIMES) && !IsType(VocabTypes::AOP_SLASH))
    {
        m_ast.Backward();
        return;
    }
    do
    {
        GetNextSymbol();
        _term(level, index);
        if (tmp_type == VocabTypes::AOP_TIMES)
        {
            m_ins_table.Generate(OPR_INS, 0, TIMES_OP);
        }
        else
        {
            m_ins_table.Generate(OPR_INS, 0, DIV_OP);
        }
        tmp_type = m_cur_lex.GetType();
    } while (IsType(VocabTypes::AOP_TIMES) || IsType(VocabTypes::AOP_SLASH));
    m_ast.Backward();
}

void Parser::_term(int level, int index)
{
    m_ast.Forward("term");
    if (IsType(VocabTypes::IDENTIFIER_DATA_TYPE))
    {
        int found_index = m_sym_table.Find(m_cur_lex.GetToken(), 0, index);
        if (found_index < 0)
        {
            GlobalErrors::CatchError(UNDEFINED_IDENTIFIER_ERROR, m_cur_line);
        }
        else
        {
            Symbol &symbol = m_sym_table[found_index];
            if (symbol.GetType() == VocabTypes::CONST_DEF_TYPE)
            {
                m_ins_table.Generate(LIT_INS, 0, symbol.GetValue());
            }
            else if (symbol.GetType() == VocabTypes::VAR_DEF_TYPE)
            {
                m_ins_table.Generate(LOD_INS, level - symbol.GetLevel(), DATA_OFFSET + symbol.GetAddress());
            }
            else
            {
                GlobalErrors::CatchError(SYNTAX_OR_TYPE_ERROR, m_cur_line);
            }
        }
        GetNextSymbol();
    }
    else if (IsType(VocabTypes::CONST_DATA_TYPE))
    {
        m_ins_table.Generate(LIT_INS, 0, Str2Int(m_cur_lex.GetToken()));
        GetNextSymbol();
    }
    else if (IsType(VocabTypes::CH_LPAREN))
    {
        GetNextSymbol();
        _expression(level, index);
        // Filter right paren
        TypeTest(VocabTypes::CH_RPAREN);
        GetNextSymbol();
    }
    else
    {
        GlobalErrors::CatchError(SYNTAX_OR_TYPE_ERROR, m_cur_line);
        GetNextSymbol();
    }
    m_ast.Backward();
}

void Parser::_condition(int level, int index)
{
    m_ast.Forward("condition");
    if (IsType(VocabTypes::F_ODD))
    {
        // Check if odd or even
        GetNextSymbol();
        _expression(level, index);
        m_ins_table.Generate(OPR_INS, 0, ODD_OP);
        m_ins_table.Generate(LIT_INS, 0, 1);
        m_ins_table.Generate(OPR_INS, 0, EQ_OP);
    }
    else
    {
        // A opr B
        // left part
        _expression(level, index);
        // logical operator
        LexItem opt = m_cur_lex;
        LopChTest();
        GetNextSymbol();
        // right part
        _expression(level, index);
        int cmd_type;
        switch (opt.GetType())
        {
        case VocabTypes::LOP_NEQ:
            cmd_type = NEQ_OP;
            break;
        case VocabTypes::LOP_EQL:
            cmd_type = EQ_OP;
            break;
        case VocabTypes::LOP_LSS:
            cmd_type = LSS_OP;
            break;
        case VocabTypes::LOP_LEQ:
            cmd_type = LE_OP;
            break;
        case VocabTypes::LOP_GTR:
            cmd_type = GT_OP;
            break;
        case VocabTypes::LOP_GEQ:
            cmd_type = GE_OP;
            break;
        }
        m_ins_table.Generate(OPR_INS, 0, cmd_type);
    }
    m_ast.Backward();
}
