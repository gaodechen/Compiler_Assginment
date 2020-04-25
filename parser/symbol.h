/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Symbol Structure
 * @LastEditTime: 2020-04-25 21:53:57
 * @Date: 2020-04-25 21:18:03
 */

#define INC_SYMBOL

#include <string>

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
};