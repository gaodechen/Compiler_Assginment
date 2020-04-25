/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbols Table
 * @LastEditTime: 2020-04-25 22:06:28
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
    std::vector<Symbol> sym_table;

public:
    void Append(Symbol symbol);
    void Insert(int idx, Symbol symbol);
    int GetSize();
    int Find(std::string token, int src_idx, int dst_idx);
};