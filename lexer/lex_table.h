/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical Table
 * @LastEditTime: 2020-04-25 17:09:43
 * @Date: 2020-04-18 22:16:06
 */

#define INC_LEX_TABLE

#include <iostream>
#include <string>
#include <vector>

#ifndef INC_LEX_ITEM
#include "../lexer/lex_item.h"
#endif

class LexTable
{
private:
    int m_buf_idx;
    std::vector<LexItem> m_lex_table;

public:
    LexTable();
    void Append(std::string _token, int _type);
    LexItem GetSymbol();

    friend std::ostream &operator<<(std::ostream &out, LexTable &obj);
};
