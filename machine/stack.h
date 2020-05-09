/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description:  Stack
 * @LastEditTime: 2020-05-03 10:36:09
 * @Date: 2020-05-02 11:26:12
 */

#include <cstring>

class Stack
{
private:
    static const int STACK_SIZE = 1000;
    int m_buf[STACK_SIZE];
    int m_top;

public:
    Stack();
    void Push(int);
    int Pop();
    int Top();
    int TopIndex();
    void MoveTop(int);
    int& operator [] (const int &idx);
};