/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Types of errors
 * @LastEditTime: 2020-04-28 21:31:54
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
    MISSING_END_CLAUSE_ERROR,
    MISSING_LPAREN_ERROR,
    MISSING_LOGIC_OPT_ERROR,
    SYNTAX_OR_TYPE_ERROR,
    UNKNOWN_ERROR,
};

struct GlobalErrors
{
    static char errors_description[NUM_ERRORS][ERROR_LEN];

    static void CatchError(ErrorTypes err, int line_num = 0);
};