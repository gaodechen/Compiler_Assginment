/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Item in Lex
 * @LastEditTime: 2020-04-25 17:57:26
 * @Date: 2020-04-18 22:16:13
 */

#include "../lexer/lex_item.h"

LexItem::LexItem(std::string &_token, int &_type)
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
int LexItem::GetType()
{
    return type;
}

std::string LexItem::GetToken()
{
    return token;
}

void LexItem::SetType(int _type)
{
    type = _type;
}

void LexItem::SetToken(std::string _token)
{
    token = _token;
}