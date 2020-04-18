/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Types of errors
 * @LastEditTime: 2020-04-18 23:40:18
 * @Date: 2020-04-18 23:04:27
 */

#include <cstring>

const int NUM_ERRORS = 10;
const int ERROR_LEN = 50;

enum ErrorTypes
{
    UNDEFINED_TYPE,
    UNKNOWN_ERROR,
};

struct Error
{
    ErrorTypes err_type;
    char err_msg[ERROR_LEN];
};

Error errors[NUM_ERRORS] = {
    {UNDEFINED_TYPE, "Undefined type."},
    {UNKNOWN_ERROR, "Unknown exception."},
};
