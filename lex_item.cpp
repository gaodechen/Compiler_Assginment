/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Item in LexTable
 * @LastEditTime: 2020-04-19 12:06:58
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
    out << "<";
    out.width(10);
    out << obj.type;
    out << ",";
    out.width(12);
    out << obj.token;
    out << ">" << std::endl;
}