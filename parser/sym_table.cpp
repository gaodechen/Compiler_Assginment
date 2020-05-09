/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbols Table
 * @LastEditTime: 2020-05-01 23:30:02
 * @Date: 2020-04-25 21:35:31
 */

#include "sym_table.h"

SymTable::SymTable()
{
    m_size = 0;
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

Symbol& SymTable::operator [] (const int &idx)
{
    if (idx > m_size)
    {
        m_size = idx;
    }
    return sym_table[idx];
}

std::ostream &operator<<(std::ostream &out, SymTable &obj)
{
    for (int i = 0; i <= obj.m_size; i++)
    {
        out << obj.sym_table[i];
    }
}