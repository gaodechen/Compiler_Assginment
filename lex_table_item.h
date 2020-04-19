/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical item in table
 * @LastEditTime: 2020-04-19 15:43:15
 * @Date: 2020-04-18 22:16:10
 */

#include <iostream>
#include <string>

#ifndef INC_SYM_TOKEN
#include "sym_token.h"
#endif

struct LexTableItem
{
    std::string token;
    SymToken sym_token;

    LexTableItem(std::string &_token, SymToken &_sym_token);

    friend std::ostream &operator<<(std::ostream &out, LexTableItem &obj);
};