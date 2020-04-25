/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbol Structure
 * @LastEditTime: 2020-04-25 21:56:03
 * @Date: 2020-04-25 21:18:06
 */

#include "../parser/symbol.h"

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