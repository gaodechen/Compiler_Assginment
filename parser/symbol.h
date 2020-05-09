/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbol Structure
 * @LastEditTime: 2020-04-28 21:49:25
 * @Date: 2020-04-25 21:18:03
 */

#define INC_SYMBOL

#include <string>
#include <iostream>

#ifndef INC_VOCAB
#include "../lexer/vocab.h"
#endif

class Symbol
{
private:
    std::string token;
    int type;
    int value;
    int level;
    int address;

public:
    Symbol();
    void SetToken(std::string);
    void SetType(int);
    void SetValue(int);
    void SetLevel(int);
    void SetAddress(int);

    std::string GetToken();
    int GetType();
    int GetValue();
    int GetLevel();
    int GetAddress();

    friend std::ostream &operator<<(std::ostream &out, Symbol &obj);
};