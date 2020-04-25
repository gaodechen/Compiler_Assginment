/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Target Language for PL/0
 * @LastEditTime: 2020-04-25 23:58:07
 * @Date: 2020-04-25 11:01:40
 */

#define INC_INSTRUCTIONS

// Instructions supported
enum InsCode
{
    LIT_OP,
    LOD_OP,
    STO_OP,
    CAL_OP,
    INT_OP,
    JMP_OP,
    JPC_OP,
    OPR_OP,
};

// Instruction-level operations
enum OptCode
{
    OP_RET = 0,
    OP_ADD = 2,
    OP_MINUS = 3,
    OP_TIMES = 4,
    OP_DIV = 5,
    OP_NEQ = 9,
    OP_EQ = 8,
    OP_LSS = 7,
    OP_LE = 6,
    OP_GT = 10,
    OP_GE = 11,
    OP_READ = 16,
    OP_WRITE = 15,
};

struct Instruction
{
    InsCode opt;
    int level;
    int offset;

    Instruction();
    Instruction(InsCode _opt, int _level = 0, int _offset = 0);
};