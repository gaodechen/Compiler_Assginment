/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical item in table
 * @LastEditTime: 2020-05-12 10:30:55
 * @Date: 2020-04-18 22:16:10
 */

#define INC_LEX_ITEM

#include <iostream>
#include <string>

#ifndef INC_VOCAB
#include "../lexer/vocab.h"
#endif

class LexItem
{
private:
    std::string m_token;
    int m_type;

public:
    LexItem();
    LexItem(std::string &_token, int &_type);

    int GetType();
    std::string GetToken();

    void SetType(int _type);
    void SetToken(std::string _token);

    friend std::ostream &operator<<(std::ostream &out, LexItem &obj);
};