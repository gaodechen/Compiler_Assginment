/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Parser
 * @LastEditTime: 2020-04-26 00:02:47
 * @Date: 2020-04-22 22:31:19
 */

#include "../parser/parser.h"

Parser::Parser(LexTable *_m_lex_table)
{
    m_lex_table = _m_lex_table;
    GetLexSymbol();
}

void Parser::GetLexSymbol()
{
    m_cur_lex = m_lex_table->GetSymbol();
}

int Parser::Parse(int level = 0, int index = 0)
{
    int count = 0;
    int dx = 0;
    bool flag = false;
    int tpc = m_opt_table.GetPC();

    m_opt_table.Generate(JMP_OP);

    switch (m_cur_lex.GetType())
    {
    case VocabTypes::D_CONST:
        count += _const(index + count);
        break;
    case VocabTypes::D_VAR:
        GetLexSymbol();
        dx = _var(level, index + count);
        count += dx;
        break;
    case VocabTypes::D_PROC:
        flag = true;
        GetLexSymbol();
        count += _procedure(level + 1, count + index);
        break;
    }

    if (!flag)
    {
        m_opt_table.DecPC();
    }
    else
    {
        m_opt_table[tpc].offset = m_opt_table.GetPC();
    }
    m_opt_table.Generate(INT_OP, 0, DX_OFFSET + dx);
    ParseStatement(level, index);
    m_opt_table.Generate(OPR_OP, 0, OP_RET);
    return count;
}


int Parser::_const(int index)
{
    int count = 0;
    Symbol symbol;
    symbol.SetType(VocabTypes::CONST_DATA_TYPE);
    do
    {
        if (m_cur_lex.GetType() != VocabTypes::IDENTIFIER_DATA_TYPE)
        {
            GlobalErrors::CatchError(MISSING_IDENTIFIER_ERROR);
        }
        if (m_sym_table.Find(m_cur_lex.GetToken(), 0, index + count) >= 0)
        {
            GlobalErrors::CatchError(MUTIPLE_IDENTIFIER_DEFINITION_ERROR);
        }
        symbol.SetToken(m_cur_lex.GetToken());
        GetLexSymbol();
        if (m_cur_lex.GetType() != VocabTypes::AOP_ASSIGN)
        {
            GlobalErrors::CatchError(MISSING_ASSIGNMENT_OPERATOR_ERROR);
        }
        GetLexSymbol();
        if (m_cur_lex.GetType() != VocabTypes::CONST_DATA_TYPE)
        {
            GlobalErrors::CatchError(MISSING_ASSIGNMENT_RHS_ERROR);
        }
        symbol.SetValue(Str2Int(m_cur_lex.GetToken()));
        m_sym_table.Insert(index + count, symbol);
        count++;
        GetLexSymbol();
        if (!(m_cur_lex.GetType() == VocabTypes::CH_COMMA || m_cur_lex.GetType() == VocabTypes::CH_SEMI))
        {
            GlobalErrors::CatchError(MISSING_END_CHARACTER);
        }
    } while (m_cur_lex.GetType() != VocabTypes::CH_SEMI);
    GetLexSymbol();
    return count;
}

int Parser::_var(int level, int index)
{
    int count = 0;
    Symbol symbol;
    LexItem prev_lex = m_cur_lex;
    symbol.SetType(VocabTypes::VAR_DEF_TYPE);
    symbol.SetLevel(level);
    symbol.SetAddress(0);
    do
    {
        if (m_cur_lex.GetType() != VocabTypes::IDENTIFIER_DATA_TYPE)
        {
            GlobalErrors::CatchError(MISSING_IDENTIFIER_ERROR);
        }
        if (m_sym_table.Find(m_cur_lex.GetToken(), 0, index + count) >= 0)
        {
            GlobalErrors::CatchError(MUTIPLE_IDENTIFIER_DEFINITION_ERROR);
        }
        symbol.SetToken(m_cur_lex.GetToken());
        m_sym_table.Insert(index + count, symbol);
        symbol.SetAddress(symbol.GetAddress() + 1);
        GetLexSymbol();
        if (!(m_cur_lex.GetType() == VocabTypes::CH_COMMA || m_cur_lex.GetType() == VocabTypes::CH_SEMI))
        {
            GlobalErrors::CatchError(MISSING_END_CHARACTER);
        }
        prev_lex = m_cur_lex;
        GetLexSymbol();
    } while (prev_lex.GetType() != VocabTypes::CH_SEMI);
    return count;
}

int Parser::_procedure(int level, int index)
{
    int count = 0;
    if (m_cur_lex.GetType() != VocabTypes::IDENTIFIER_DATA_TYPE)
    {
        GlobalErrors::CatchError(MISSING_IDENTIFIER_ERROR);
    }
    Symbol symbol;
    symbol.SetToken(m_cur_lex.GetToken());
    symbol.SetType(VocabTypes::PROCEDURE_DEF_TYPE);
    symbol.SetLevel(level - 1);
    symbol.SetAddress(m_pc);
    m_sym_table.Insert(index + count, symbol);
    GetLexSymbol();
    if (m_cur_lex.GetType() != VocabTypes::CH_SEMI)
    {
        GlobalErrors::CatchError(MISSING_END_CHARACTER);
    }
    GetLexSymbol();
    Parse(level, index + count);
    if (m_cur_lex.GetType() != VocabTypes::CH_SEMI)
    {
        GlobalErrors::CatchError(MISSING_END_CHARACTER);
    }
    GetLexSymbol();
    if (m_cur_lex.GetType() == VocabTypes::D_PROC)
    {
        GetLexSymbol();
        count += _procedure(level, index + count);
    }
    return count + 1;
}

void Parser::ParseStatement(int level, int index)
{
    switch (m_cur_lex.GetType())
    {
    case VocabTypes::CP_IF:
        GetLexSymbol();
        _if(level, index);
        break;
    case VocabTypes::CP_WHILE:
        GetLexSymbol();
        _while(level, index);
        break;
    case VocabTypes::CP_CALL:
        GetLexSymbol();
        _call(level, index);
        break;
    case VocabTypes::F_WRITE:
        GetLexSymbol();
        _write(level, index);
        break;
    case VocabTypes::F_READ:
        GetLexSymbol();
        _read(level, index);
        break;
    case VocabTypes::CP_BEGIN:
        GetLexSymbol();
        _begin(level, index);
        break;
    case VocabTypes::AOP_ASSIGN:
        GetLexSymbol();
        _assign(level, index);
        break;
    }
}

void Parser::_if(int level, int index)
{
    expr_condition(level, index);
    int cpc = m_opt_table.GetPC();
    m_opt_table.Generate(JPC_OP);
    if (m_cur_lex.GetType() != VocabTypes::CP_THEN)
    {
        GlobalErrors::CatchError(MISSING_THEN_CLAUSE_ERROR);
    }
    GetLexSymbol();
    ParseStatement(level, index);
    m_opt_table[cpc].offset = m_opt_table.GetPC();
}