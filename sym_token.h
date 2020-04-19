/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbolic Token
 * @LastEditTime: 2020-04-19 10:05:48
 * @Date: 2020-04-18 17:49:52
 */

#define INC_SYM_TOKEN

#include <string>

class SymToken
{
private:
    int m_idx;
    std::string m_sym_type;

public:
    SymToken();
    SymToken(std::string _m_sym_type);
    SymToken(int _m_idx, std::string _m_sym_type);

    int GetIdx();

    std::string GetType();
};
