/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Types of errors
 * @LastEditTime: 2020-04-25 23:26:57
 * @Date: 2020-04-18 23:04:27
 */

#define INC_COMPILE_ERRORS

#include <iostream>
#include <cstring>

const int NUM_ERRORS = 30;
const int ERROR_LEN = 50;

enum ErrorTypes
{
    UNDEFINED_IDENTIFIER_ERROR,
    MUTIPLE_IDENTIFIER_DEFINITION_ERROR,
    MISSING_IDENTIFIER_ERROR,
    MISSING_ASSIGNMENT_OPERATOR_ERROR,
    MISSING_ASSIGNMENT_RHS_ERROR,
    MISSING_END_CHARACTER,
    MISSING_THEN_CLAUSE_ERROR,
    MISSING_DO_CLAUSE_ERROR,
    UNKNOWN_ERROR,
};

struct GlobalErrors
{
    static char *errors_description[ERROR_LEN];

    static void CatchError(ErrorTypes err);
};