/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Target Language for PL/0
 * @LastEditTime: 2020-04-26 13:52:39
 * @Date: 2020-04-25 11:01:36
 */

#ifndef INC_INSTRUCTIONS
#include "instructions.h"
#endif

Instruction::Instruction()
{
    level = 0;
    offset = 0;
}

Instruction::Instruction(InsCode _opt, int _level, int _offset)
{
    opt = _opt;
    level = _level;
    offset = _offset;
}

std::ostream &operator<<(std::ostream &out, Instruction &obj)
{
    out << Instruction::ins_str[obj.opt] << " " << obj.level << " " << obj.offset << std::endl;
}

const char Instruction::ins_str[INS_NUM][INS_STR_LEN] = {
    "LIT",
    "LOD",
    "STO",
    "CAL",
    "INT",
    "JMP",
    "JPC",
    "OPR",
};