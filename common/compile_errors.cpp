/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Deal with errors
 * @LastEditTime: 2020-04-28 21:31:41
 * @Date: 2020-04-19 11:55:40
 */

#ifndef INC_COMPILE_ERRORS
#include "../common/compile_errors.h"
#endif

char GlobalErrors::errors_description[NUM_ERRORS][ERROR_LEN] = {
    "UNDEFINED_IDENTIFIER_ERROR",
    "MUTIPLE_IDENTIFIER_DEFINITION_ERROR",
    "MISSING_IDENTIFIER_ERROR",
    "MISSING_ASSIGNMENT_OPERATOR_ERROR",
    "MISSING_ASSIGNMENT_RHS_ERROR",
    "MISSING_END_CHARACTER",
    "MISSING_THEN_CLAUSE_ERROR",
    "MISSING_DO_CLAUSE_ERROR",
    "MISSING_END_CLAUSE_ERROR",
    "MISSING_LPAREN_ERROR",
    "MISSING_LOGIC_OPT_ERROR",
    "SYNTAX_OR_TYPE_ERROR",
    "UNKNOWN_ERROR",
};

void GlobalErrors::CatchError(ErrorTypes err, int line_num)
{
    std::cout << "Line " << line_num << ": " << errors_description[err] << std::endl;
}
