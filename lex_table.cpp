/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical table
 * @LastEditTime: 2020-04-19 15:52:25
 * @Date: 2020-04-18 22:16:02
 */

#include "lex_table.h"

void LexTable::AddItem(std::string _token, SymToken _sym_token)
{
    lex_table.push_back(LexTableItem(_token, _sym_token));
}

std::ostream &operator<<(std::ostream &out, LexTable &obj)
{
    int table_size = obj.lex_table.size();
    for (int i = 0; i < table_size; i++)
    {
        out << obj.lex_table[i];
    }
}