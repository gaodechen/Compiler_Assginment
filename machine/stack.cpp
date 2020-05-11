/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Stack
 * @LastEditTime: 2020-05-03 22:16:19
 * @Date: 2020-05-02 11:26:15
 */

#include "../machine/stack.h"

Stack::Stack()
{
    m_top = 0;
    memset(m_buf, 0, sizeof(m_buf));
}

void Stack::Push(int e)
{
    m_buf[m_top++] = e;
}

void Stack::PushNull()
{
    m_top++;
}

int Stack::TopIndex()
{
    return m_top;
}

int Stack::Pop()
{
    return m_buf[--m_top];
}

int& Stack::operator [] (const int &idx)
{
    return m_buf[idx];
}
