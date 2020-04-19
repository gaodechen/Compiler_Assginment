/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: utils 
 * @LastEditTime: 2020-04-19 18:07:17
 * @Date: 2020-04-18 16:48:48
 */

#include "utils.h"

bool IsLetter(const char &ch)
{
    if ((ch >= 'a' && ch < 'z') || (ch >= 'A') && (ch <= 'Z'))
        return true;
    return false;
}

bool IsDigital(const char &ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

bool IsBlank(const char &ch)
{
    if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t')
        return true;
    return false;
}
