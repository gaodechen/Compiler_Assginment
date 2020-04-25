/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbols Table
 * @LastEditTime: 2020-04-25 22:13:52
 * @Date: 2020-04-25 21:35:31
 */

#include "sym_table.h"

void SymTable::Append(Symbol symbol)
{
    sym_table.push_back(symbol);
}

void Insert(int idx, Symbol symbol)
{
}

int SymTable::GetSize()
{
    return sym_table.size();
}

int SymTable::Find(std::string token, int src_idx, int dst_idx)
{
    for (int i = src_idx; i < dst_idx; i++)
    {
        if (sym_table[i].GetToken() == token)
        {
            return i;
        }
    }
    return -1;
}