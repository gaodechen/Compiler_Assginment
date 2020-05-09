/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical Table
 * @LastEditTime: 2020-04-28 21:29:37
 * @Date: 2020-04-18 22:16:06
 */

#define INC_LEX_TABLE

#include <iostream>
#include <string>

#ifndef INC_LEX_ITEM
#include "../lexer/lex_item.h"
#endif

class LexTable
{
private:
    static const int LEX_TABLE_SIZE = 1000;
    int m_size;
    int m_buf_idx;
    int m_lex_lines[LEX_TABLE_SIZE];
    LexItem m_lex_table[LEX_TABLE_SIZE];

public:
    LexTable();
    void Append(std::string _token, int _type, int line_num);
    void GetLexLines(int index);
    LexItem GetNextSymbol();
    LexItem GetPrevSymbol();
    int GetLineNum();

    friend std::ostream &operator<<(std::ostream &out, LexTable &obj);
};
