/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Interpreter
 * @LastEditTime: 2020-05-03 22:33:59
 * @Date: 2020-05-02 10:22:46
 */

#define INC_MACHINE

#ifndef INC_INS_TABLE
#include "../parser/ins_table.h"
#endif

#include "../machine/stack.h"

class Machine
{
private:
    typedef void (Machine::*InsFuncPtr)(const Instruction &);

    // Offsets for three special units
    static const int STATIC_LINK_OFFSET = 0;
    static const int DYNAMIC_LINK_OFFSET = 1;
    static const int RET_ADDR_OFFSET = 2;

    // Table of instructions
    InsTable m_ins_table;
    // PC register
    int m_pc;
    // Base Addr register
    int m_base;
    // Data stack
    Stack m_stack;
    // Addr stack
    Stack m_p_stack;

    // Push constants to top of stack
    void _LIT(const Instruction &ins);
    // Load value of one variable to the top of stack
    void _LOD(const Instruction &ins);
    // Store the value of the top of stack into one variable
    void _STO(const Instruction &ins);
    // Call procedure
    void _CAL(const Instruction &ins);
    // Allocate spaces for called procedure
    void _INT(const Instruction &ins);
    // Jump directly
    void _JMP(const Instruction &ins);
    // Jump when the top of stack is not true
    void _JPC(const Instruction &ins);
    // Operators of relation computation
    void _OPR(const Instruction &ins);

    void _RET_OP(const Instruction &ins);
    void _ADD_OP(const Instruction &ins);
    void _MINUS_OP(const Instruction &ins);
    void _TIMES_OP(const Instruction &ins);
    void _DIV_OP(const Instruction &ins);
    void _LE_OP(const Instruction &ins);
    void _LSS_OP(const Instruction &ins);
    void _EQ_OP(const Instruction &ins);
    void _NEQ_OP(const Instruction &ins);
    void _GT_OP (const Instruction &ins);
    void _GE_OP (const Instruction &ins);
    void _WRITE_LINE_OP (const Instruction &ins);
    void _WRITE_OP (const Instruction &ins);
    void _READ_OP (const Instruction &ins);

    InsFuncPtr m_ins_func[Instruction::INS_NUM];
    InsFuncPtr m_opt_func[Instruction::OPT_NUM];

public:
    Machine(InsTable _m_ins_table);
    int &GetData(int base, int level, int offset);
    void Intepret();
};