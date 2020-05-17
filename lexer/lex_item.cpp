/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Item in Lex
 * @LastEditTime: 2020-05-17 12:32:25
 * @Date: 2020-04-18 22:16:13
 */

#include "../lexer/lex_item.h"

LexItem::LexItem()
{
    m_token = "";
    m_type = -1;
}

LexItem::LexItem(std::string &_token, int &_type)
{
    m_token = _token;
    m_type = _type;
}

std::string LexItem::GetStrType()
{
    if (m_type >= 0)
    {
        return VocabTypes::vocab_types[m_type];
    }
    return "";
}

std::ostream &operator<<(std::ostream &out, LexItem &obj)
{
    out << "<";
    out.width(10);
    out << obj.GetStrType();
    out << ",";
    out.width(12);
    out << obj.m_token;
    out << ">" << std::endl;
    return out;
}

int LexItem::GetType()
{
    return m_type;
}

std::string LexItem::GetToken()
{
    return m_token;
}

void LexItem::SetType(int _type)
{
    m_type = _type;
}

void LexItem::SetToken(std::string _token)
{
    m_token = _token;
}