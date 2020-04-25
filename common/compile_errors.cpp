/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Deal with errors
 * @LastEditTime: 2020-04-25 23:27:17
 * @Date: 2020-04-19 11:55:40
 */

#ifndef INC_COMPILE_ERRORS
#include "../common/compile_errors.h"
#endif

char *GlobalErrors::errors_description[ERROR_LEN] = {
    "UNDEFINED_IDENTIFIER_ERROR",
    "MUTIPLE_IDENTIFIER_DEFINITION_ERROR",
    "MISSING_IDENTIFIER_ERROR",
    "MISSING_ASSIGNMENT_OPERATOR_ERROR",
    "MISSING_ASSIGNMENT_RHS_ERROR",
    "MISSING_END_CHARACTER",
    "MISSING_THEN_CLAUSE_ERROR",
    "MISSING_DO_CLAUSE_ERROR",
    "UNKNOWN_ERROR",
};

void GlobalErrors::CatchError(ErrorTypes err)
{
    std::cout << errors_description[err] << std::endl;
}
