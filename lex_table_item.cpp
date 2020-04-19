/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Item in LexTable
 * @LastEditTime: 2020-04-19 15:42:40
 * @Date: 2020-04-18 22:16:13
 */

#include "lex_table_item.h"

LexTableItem::LexTableItem(std::string &_token, SymToken &_sym_token)
{
    token = _token;
    sym_token = _sym_token;
}

std::ostream &operator<<(std::ostream &out, LexTableItem &obj)
{
    out << "<";
    out.width(10);
    out << obj.sym_token.GetType();
    out << ",";
    out.width(12);
    out << obj.token;
    out << ">" << std::endl;
}