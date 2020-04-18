/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbolic Token
 * @LastEditTime: 2020-04-19 00:33:49
 * @Date: 2020-04-18 17:49:52
 */

#include <string>

class SymToken
{
private:
    int m_idx;
    std::string m_sym_type;

public:
    SymToken();
    SymToken(int _m_idx, std::string _m_sym_type);

    int GetIdx();

    std::string GetType();
};
