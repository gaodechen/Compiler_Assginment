/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Deal with errors
 * @LastEditTime: 2020-04-19 11:59:33
 * @Date: 2020-04-19 11:55:40
 */

#include "errors.h"

std::ostream &operator<<(std::ostream &out, Error &obj)
{
    out << "ERROR occurs: " << obj.err_msg << std::endl;
}