/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical item in table
 * @LastEditTime: 2020-04-18 23:05:00
 * @Date: 2020-04-18 22:16:10
 */

#include <iostream>
#include <string>

struct LexItem
{
    std::string token;
    std::string type;

    LexItem(std::string &_token, std::string &_type);

    friend std::ostream &operator<<(std::ostream &out, LexItem &obj);
};