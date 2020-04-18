/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Item in LexTable
 * @LastEditTime: 2020-04-18 22:25:27
 * @Date: 2020-04-18 22:16:13
 */

#include "lex_item.h"

LexItem::LexItem(std::string &_token, std::string &_type)
{
    token = _token;
    type = _type;
}

std::ostream &operator<<(std::ostream &out, LexItem &obj)
{
    std::cout << obj.token << " " << obj.type << std::endl;
}