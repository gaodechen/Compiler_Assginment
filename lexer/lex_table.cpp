/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical table
 * @LastEditTime: 2020-04-25 17:04:27
 * @Date: 2020-04-18 22:16:02
 */

#include "../lexer/lex_table.h"

LexTable::LexTable()
{
    m_buf_idx = 0;
}

LexItem LexTable::GetSymbol()
{
    // check m_buf_idx
    return m_lex_table[m_buf_idx++];
}

void LexTable::Append(std::string _token, int _type)
{
    m_lex_table.push_back(LexItem(_token, _type));
}

std::ostream &operator<<(std::ostream &out, LexTable &obj)
{
    int table_size = obj.m_lex_table.size();
    for (int i = 0; i < table_size; i++)
    {
        out << obj.m_lex_table[i];
    }
}