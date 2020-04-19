/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Deal with errors
 * @LastEditTime: 2020-04-19 13:02:33
 * @Date: 2020-04-19 11:55:40
 */

#include "errors.h"

std::ostream &operator<<(std::ostream &out, Error &obj)
{
    out << "ERROR occurs: " << obj.err_msg << std::endl;
}

void CatchError(ErrorTypes err)
{
    Error *catched_error;
    switch (err)
    {
    case UNDEFINED_TYPE:
        catched_error = &undefined_type_error;
        break;
    case UNKNOWN_ERROR:
        catched_error = &unknow_error;
        break;
    default:
        catched_error = &unknow_error;
    }
    std::cout << (*catched_error);
}
