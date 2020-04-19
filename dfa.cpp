/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Deterministic Finite Automaton
 * @LastEditTime: 2020-04-19 11:40:46
 * @Date: 2020-04-18 17:20:34
 */


#include "dfa.h"

// fill states for ASCII characters
void DFA::FillTransState(DFAState src_state, DFAState dst_state)
{
    for (int i = 0; i < DFA_VOCAB_SIZE; i++)
    {
        m_mat[src_state][i] = dst_state;
    }
}

// fill states for characters in ch_table
void DFA::FillTransState(DFAState src_state, DFAState dst_state, const char *ch_table)
{
    int len = strlen(ch_table);
    for (int i = 0; i < len; i++)
    {
        m_mat[src_state][(int) ch_table[i]] = dst_state;
    }
}

// fill states for ch only
void DFA::FillTransState(DFAState src_state, DFAState dst_state, const char &ch)
{
    m_mat[src_state][(int) ch] = dst_state;
}

void DFA::InitTransMat()
{
    memset(m_mat, -1, sizeof(m_mat));

    // State 0
    FillTransState(0, 0, filter_ch);
    FillTransState(0, 1, lower_ch);
    FillTransState(0, 1, upper_ch);
    FillTransState(0, 3, number_ch);
    for (int i = 5; i < 18; i++)
        FillTransState(0, i, operator_ch[i - 5]);

    // State 1
    for (int i = 0; i < DFA_VOCAB_SIZE; i++)
        FillTransState(1, 2, i);

    FillTransState(1, 1, lower_ch);
    FillTransState(1, 1, upper_ch);
    FillTransState(1, 1, number_ch);

    // State 3
    FillTransState(3, 3, number_ch);
    FillTransState(3, 4);

    // State 10
    FillTransState(10, 18, '>');
    FillTransState(10, 19, '=');
    FillTransState(10, 20);

    // State 11
    FillTransState(11, 21, '=');
    FillTransState(14, 22);

    // State 12
    FillTransState(12, 23, '=');
}

// Initialize types of states
void DFA::InitStatesTypes()
{
    for (int i = 0; i < DFA_NUM_STATES; i++)
        m_states_types[i] = TERMINAL_STATE;

    int non_terminal_states_len = sizeof(non_terminal_states) / sizeof(int);
    for (int i = 0; i < non_terminal_states_len; i++)
        m_states_types[non_terminal_states[i]] = NON_TERMINAL_STATE;

    int backtrace_states_len = sizeof(backtrace_states) / sizeof(int);
    for (int i = 0; i < backtrace_states_len; i++)
        m_states_types[backtrace_states[i]] = BACKTRACE_STATE;
}

// Initialize DFA
DFA::DFA()
{
    InitTransMat();
    InitStatesTypes();
    curState = NON_STATE;
}

// Get current state
DFAState DFA::GetCurState()
{
    return curState;
}

// Get next state with character ch starting from curState
DFAState DFA::GetNextState(const char &ch)
{
    return m_mat[curState][ch];
}

// Get type of given state
int DFA::GetStateType(const int &state)
{
    return m_states_types[state];
}

void DFA::SetState(const int &state)
{
    curState = state;
}

// Move to the next state with ch
int DFA::GotoNextState(const char &ch)
{
    curState = m_mat[curState][ch];
    return curState;
}