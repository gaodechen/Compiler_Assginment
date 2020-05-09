/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Target Language for PL/0
 * @LastEditTime: 2020-05-03 21:56:16
 * @Date: 2020-04-25 11:01:40
 */

#define INC_INSTRUCTIONS

#include <iostream>

// Instructions supported
enum InsCode
{
    LIT_INS,
    LOD_INS,
    STO_INS,
    CAL_INS,
    INT_INS,
    JMP_INS,
    JPC_INS,
    OPR_INS,
};

// Instruction-level operations
enum OptCode
{
    RET_OP = 0,
    ADD_OP = 2,
    MINUS_OP = 3,
    TIMES_OP = 4,
    DIV_OP = 5,
    LE_OP = 6,
    LSS_OP = 7,
    EQ_OP = 8,
    NEQ_OP = 9,
    GT_OP = 10,
    GE_OP = 11,
    WRITE_LINE_OP = 14,
    WRITE_OP = 15,
    READ_OP = 16,
};

struct Instruction
{
    static const int INS_NUM = 8;
    static const int INS_STR_LEN = 4;
    static const int OPT_NUM = 14;
    static const char ins_str[INS_NUM][INS_STR_LEN];

    InsCode opt;
    int level;
    int offset;

    Instruction();
    Instruction(InsCode _opt, int _level = 0, int _offset = 0);
    friend std::ostream &operator<<(std::ostream &out, Instruction &obj);
};