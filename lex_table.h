/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical Table
 * @LastEditTime: 2020-04-19 16:26:35
 * @Date: 2020-04-18 22:16:06
 */

#include <iostream>
#include <string>
#include <vector>

#include "lex_table_item.h"

class LexTable
{
private:
    std::vector<LexTableItem> lex_table;

public:
    void AddItem(std::string _token, SymToken _sym_token);

    friend std::ostream &operator<<(std::ostream &out, LexTable &obj);
};
