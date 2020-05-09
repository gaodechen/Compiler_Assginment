/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbols Table
 * @LastEditTime: 2020-04-26 17:24:44
 * @Date: 2020-04-25 21:35:25
 */

#include <vector>
#include <string>
#include <iostream>

#ifndef INC_SYMBOL
#include "../parser/symbol.h"
#endif

class SymTable
{
private:
    static const int TABLE_SIZE = 1000;
    Symbol sym_table[TABLE_SIZE];
    int m_size;

public:
    SymTable();
    int Find(std::string token, int src_idx, int dst_idx);
    Symbol& operator [] (const int &idx);
    friend std::ostream &operator<<(std::ostream &out, SymTable &obj);
};