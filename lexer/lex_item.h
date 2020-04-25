/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical item in table
 * @LastEditTime: 2020-04-25 17:57:54
 * @Date: 2020-04-18 22:16:10
 */

#define INC_LEX_ITEM

#include <iostream>
#include <string>

class LexItem
{
private:
    std::string token;
    int type;

public:
    LexItem();
    LexItem(std::string &_token, int &_type);

    int GetType();
    std::string GetToken();

    void SetType(int _type);
    void SetToken(std::string _token);

    friend std::ostream &operator<<(std::ostream &out, LexItem &obj);
};