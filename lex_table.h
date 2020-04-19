/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical Table
 * @LastEditTime: 2020-04-19 00:32:17
 * @Date: 2020-04-18 22:16:06
 */

#include <iostream>
#include <string>
#include <vector>

#include "lex_item.h"

class LexTable
{
private:

    std::vector<LexItem> lex_table;

public:
    void AddItem(std::string _token, std::string _type);

    friend std::ostream &operator<<(std::ostream &out, LexTable &obj);
};
