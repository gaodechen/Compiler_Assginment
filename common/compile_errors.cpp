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
    "ILLEGAL FILE PATH",
    "UNDEFINED IDENTIFIER ERROR",
    "MUTIPLE IDENTIFIER DEFINITION ERROR",
    "MISSING IDENTIFIER ERROR",
    "MISSING ASSIGNMENT OPERATOR ERROR",
    "MISSING ASSIGNMENT RHS ERROR",
    "MISSING END CHARACTER",
    "MISSING THEN CLAUSE ERROR",
    "MISSING DO CLAUSE ERROR",
    "MISSING END CLAUSE ERROR",
    "MISSING LPAREN ERROR",
    "MISSING LOGIC OPT ERROR",
    "SYNTAX OR TYPE ERROR",
    "UNKNOWN ERROR",
};

void GlobalErrors::CatchError(ErrorTypes err, int line_num)
{
    std::cout << "Line " << line_num << ": " << errors_description[err] << std::endl;
}
