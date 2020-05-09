/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbol Structure
 * @LastEditTime: 2020-04-28 21:49:35
 * @Date: 2020-04-25 21:18:06
 */

#ifndef INC_SYMBOL
#include "../parser/symbol.h"
#endif

Symbol::Symbol()
{
    token = "";
    type = -1;
    value = 0;
    address = 0;
}

void Symbol::SetToken(std::string _token)
{
    token = _token;
}

void Symbol::SetType(int _type)
{
    type = _type;
}

void Symbol::SetValue(int _value)
{
    value = _value;
}

void Symbol::SetLevel(int _level)
{
    level = _level;
}

void Symbol::SetAddress(int _address)
{
    address = _address;
}

std::string Symbol::GetToken()
{
    return token;
}

int Symbol::GetType()
{
    return type;
}

int Symbol::GetValue()
{
    return value;
}

int Symbol::GetLevel()
{
    return level;
}

int Symbol::GetAddress()
{
    return address;
}

std::ostream &operator<<(std::ostream &out, Symbol &obj)
{
    out << '|';
    out.width(10);
    out << obj.token;
    out << '|';
    out.width(10);
    out << VocabTypes::m_def_str[obj.type];
    out << '|';
    out.width(5);
    out << obj.value;
    out << '|';
    out.width(5);
    out << obj.address;
    out << '|';
    out << std::endl;
}