/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbolic Token
 * @LastEditTime: 2020-04-19 16:23:52
 * @Date: 2020-04-18 17:50:10
 */

#ifndef INC_SYM_TOKEN
#include "sym_token.h"
#endif

SymToken::SymToken()
{
}

SymToken::SymToken(std::string _m_sym_type)
{
    m_idx = 0;
    m_sym_type = _m_sym_type;
}

SymToken::SymToken(int _m_idx, std::string _m_sym_type)
{
    m_idx = _m_idx;
    m_sym_type = _m_sym_type;
}

int SymToken::GetIdx()
{
    return m_idx;
}

std::string SymToken::GetType()
{
    return m_sym_type;
}