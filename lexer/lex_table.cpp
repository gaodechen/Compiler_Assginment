/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical table
 * @LastEditTime: 2020-04-28 21:29:15
 * @Date: 2020-04-18 22:16:02
 */

#ifndef INC_LEX_TABLE
#include "../lexer/lex_table.h"
#endif

LexTable::LexTable()
{
    m_size = 0;
    m_buf_idx = 0;
}

LexItem LexTable::GetNextSymbol()
{
    // check m_buf_idx
    return m_lex_table[m_buf_idx++];
}

LexItem LexTable::GetPrevSymbol()
{
    // check m_buf_idx
    if (m_buf_idx - 1)
    {
        return m_lex_table[m_buf_idx--];
    }
    return m_lex_table[m_buf_idx];
}

void LexTable::Append(std::string _token, int _type, int line_num)
{
    m_lex_lines[m_size] = line_num;
    m_lex_table[m_size++] = LexItem(_token, _type);
}

std::ostream &operator<<(std::ostream &out, LexTable &obj)
{
    for (int i = 0; i < obj.m_size; i++)
    {
        out << obj.m_lex_table[i];
    }
    return out;
}

int LexTable::GetLineNum()
{
    return m_lex_lines[m_buf_idx];
}