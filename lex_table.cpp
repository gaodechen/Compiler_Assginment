/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical table
 * @LastEditTime: 2020-04-19 00:31:40
 * @Date: 2020-04-18 22:16:02
 */

#include <iostream>

#include "lex_table.h"

void LexTable::AddItem(std::string _token, std::string _type)
{
    lex_table.push_back(LexItem(_token, _type));
}

std::ostream &operator<<(std::ostream &out, LexTable &obj)
{
    int table_size = obj.lex_table.size();
    for (int i = 0; i < table_size; i++)
    {
        out << obj.lex_table[i];
    }
}