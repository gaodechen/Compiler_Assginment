/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Deterministic Finite Automaton
 * @LastEditTime: 2020-05-12 10:20:19
 * @Date: 2020-04-18 17:20:34
 */


#ifndef INC_DFA
#include "../lexer/dfa.h"
#endif

void DFA::SetStateTypes(const int *states, int len, int type)
{
    for (int i = 0; i < len; i++)
        m_states_types[states[i]] = type;
}

// fill states for ASCII characters
void DFA::SetMat(DFAState src_state, DFAState dst_state)
{
    for (int i = 0; i < DFA_VOCAB_SIZE; i++)
    {
        m_mat[src_state][i] = dst_state;
    }
}

// fill states for characters in ch_table
void DFA::SetMat(DFAState src_state, DFAState dst_state, const char *ch_table)
{
    int len = strlen(ch_table);
    for (int i = 0; i < len; i++)
    {
        m_mat[src_state][(int) ch_table[i]] = dst_state;
    }
}

// fill states for ch only
void DFA::SetMat(DFAState src_state, DFAState dst_state, const char &ch)
{
    m_mat[src_state][(int) ch] = dst_state;
}

void DFA::InitMat()
{
    std::fill(m_mat[0], m_mat[0] + DFA_NUM_STATES * DFA_VOCAB_SIZE, ILLEGAL_STATE);
    // State 0
    SetMat(0, 0, filter_ch);
    SetMat(0, 1, lower_ch);
    SetMat(0, 1, upper_ch);
    SetMat(0, 3, number_ch);
    for (int i = 5; i < 18; i++)
        SetMat(0, i, operator_ch[i - 5]);

    // State 1
    SetMat(1, 2);
    SetMat(1, 1, lower_ch);
    SetMat(1, 1, upper_ch);
    SetMat(1, 1, number_ch);

    // State 3
    SetMat(3, 4);
    SetMat(3, 3, number_ch);

    // State 10
    SetMat(10, 20);
    SetMat(10, 18, '>');
    SetMat(10, 19, '=');

    // State 11
    SetMat(11, 22);
    SetMat(11, 21, '=');

    // State 12
    SetMat(12, 23, '=');
}

// Initialize types of states
void DFA::InitStatesTypes()
{
    SetStateTypes(terminal_states, sizeof(terminal_states) / sizeof(int), TERMINAL_STATE);
    SetStateTypes(non_terminal_states, sizeof(non_terminal_states) / sizeof(int), NON_TERMINAL_STATE);
    SetStateTypes(backtrace_states, sizeof(backtrace_states) / sizeof(int), BACKTRACE_STATE);
}

// Initialize DFA
DFA::DFA()
{
    InitMat();
    InitStatesTypes();
    m_curState = NON_STATE;
}

// Get current state
DFAState DFA::GetCurState()
{
    return m_curState;
}

// Get next state with character ch starting from curState
DFAState DFA::GetNextState(const char &ch)
{
    return m_mat[m_curState][int(ch)];
}

// Get type of given state
int DFA::GetStateType(const int &state)
{
    return m_states_types[state];
}

void DFA::SetState(const int &state)
{
    m_curState = state;
}

// Move to the next state with ch
int DFA::GotoNextState(const char &ch)
{
    m_curState = m_mat[m_curState][int(ch)];
    return m_curState;
}