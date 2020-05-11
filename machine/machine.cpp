/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Interpreter
 * @LastEditTime: 2020-05-09 19:06:49
 * @Date: 2020-05-02 10:22:49
 */

#ifndef INC_MACHINE
#include "../machine/machine.h"
#endif

Machine::Machine(InsTable _m_ins_table)
{
    m_pc = 1;
    m_base = 0;
    m_ins_table = _m_ins_table;
    m_terminal = false;
    // Instruction pointers to functions
    m_ins_func[LIT_INS] = &Machine::_LIT;
    m_ins_func[LOD_INS] = &Machine::_LOD;
    m_ins_func[STO_INS] = &Machine::_STO;
    m_ins_func[CAL_INS] = &Machine::_CAL;
    m_ins_func[INT_INS] = &Machine::_INT;
    m_ins_func[JMP_INS] = &Machine::_JMP;
    m_ins_func[JPC_INS] = &Machine::_JPC;
    m_ins_func[OPR_INS] = &Machine::_OPR;
    // Operations pointers to functions
    m_opt_func[RET_OP] = &Machine::_RET_OP;
    m_opt_func[ADD_OP] = &Machine::_ADD_OP;
    m_opt_func[MINUS_OP] = &Machine::_MINUS_OP;
    m_opt_func[TIMES_OP] = &Machine::_TIMES_OP;
    m_opt_func[DIV_OP] = &Machine::_DIV_OP;
    m_opt_func[LE_OP] = &Machine::_LE_OP;
    m_opt_func[LSS_OP] = &Machine::_LSS_OP;
    m_opt_func[EQ_OP] = &Machine::_EQ_OP;
    m_opt_func[NEQ_OP] = &Machine::_NEQ_OP;
    m_opt_func[GT_OP] = &Machine::_GT_OP;
    m_opt_func[GE_OP] = &Machine::_GE_OP;
    m_opt_func[ODD_OP] = &Machine::_ODD_OP;
    m_opt_func[WRITE_LINE_OP] = &Machine::_WRITE_LINE_OP;
    m_opt_func[WRITE_OP] = &Machine::_WRITE_OP;
    m_opt_func[READ_OP] = &Machine::_READ_OP;
}

int &Machine::GetData(int base, int level, int offset)
{
    while (level)
    {
        // Outer procedure base addr
        base = m_stack[base + STATIC_LINK_OFFSET];
        level--;
    }
    return m_stack[base + offset];
}

void Machine::Intepret()
{
    while (!m_terminal)
    {
        Instruction ins = m_ins_table[m_pc++];
        (this->*m_ins_func[ins.opt])(ins);
    }
}

// Operators of relation computation
void Machine::_OPR(const Instruction &ins)
{
    (this->*m_opt_func[ins.offset])(ins);
}

// Push constants to top of stack
void Machine::_LIT(const Instruction &ins)
{
    m_stack.Push(ins.offset);
}

// Load value of one variable to the top of stack
void Machine::_LOD(const Instruction &ins)
{
    int var = GetData(m_base, ins.level, ins.offset);
    m_stack.Push(var);
}

// Store the value of the top of stack into one variable
void Machine::_STO(const Instruction &ins)
{
    GetData(m_base, ins.level, ins.offset) = m_stack.Pop();
}

// Call procedure
void Machine::_CAL(const Instruction &ins)
{
    int top = m_stack.TopIndex();
    m_stack[top + STATIC_LINK_OFFSET] = GetData(m_base, ins.level, ins.offset);
    m_stack[top + DYNAMIC_LINK_OFFSET] = m_base;
    m_stack[top + RET_ADDR_OFFSET] = m_pc;
    m_pc = ins.offset;
    m_base = top;
}

// Allocate spaces for called procedure
void Machine::_INT(const Instruction &ins)
{
    for (int i = 0; i < ins.offset; i++)
    {
        m_stack.PushNull();
    }
}

// Jump directly
void Machine::_JMP(const Instruction &ins)
{
    m_pc = ins.offset;
}

// Jump when the top of stack is zero
void Machine::_JPC(const Instruction &ins)
{
    if (m_stack.Top() == 0)
    {
        m_pc = ins.offset;
    }
}

void Machine::_RET_OP(const Instruction &ins)
{
    if (m_base == 0)
    {
        m_terminal = true;
    }
    else
    {
        // return to the breakpoint
        m_pc = m_stack[m_base + RET_ADDR_OFFSET];
        // redirect to the base addr of the outer process
        m_base = m_stack[m_base + DYNAMIC_LINK_OFFSET];
    }
}

void Machine::_ADD_OP(const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs + rhs);
}

void Machine::_MINUS_OP(const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs - rhs);
}

void Machine::_TIMES_OP(const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs * rhs);
}

void Machine::_DIV_OP(const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs / rhs);
}

void Machine::_LE_OP(const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs <= rhs);
}

void Machine::_LSS_OP(const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs < rhs);
}

void Machine::_EQ_OP(const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs == rhs);
}

void Machine::_NEQ_OP(const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs != rhs);
}

void Machine::_GT_OP (const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs > rhs);
}

void Machine::_GE_OP (const Instruction &ins)
{
    int rhs = m_stack.Pop();
    int lhs = m_stack.Pop();
    m_stack.Push(lhs >= rhs);
}

void Machine::_ODD_OP (const Instruction &ins)
{
    int var = m_stack.Pop();
    m_stack.Push(var & 1);
}

void Machine::_WRITE_LINE_OP (const Instruction &ins)
{
    std::cout << std::endl;
}

void Machine::_WRITE_OP (const Instruction &ins)
{
    std::cout << m_stack.Top();
}

void Machine::_READ_OP (const Instruction &ins)
{
    int value;
    std::cin >> value;
    m_stack.Push(value);
}
