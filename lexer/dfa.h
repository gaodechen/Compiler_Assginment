/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Deterministic Finite Automaton
 * @LastEditTime: 2020-05-12 10:30:16
 * @Date: 2020-04-18 17:20:31
 */

#define INC_DFA

#include <map>
#include <bitset>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#ifndef INC_DFA_MAP
#include "../lexer/dfa_map.h"
#endif

typedef int DFAState;

// Class all states into 3 types
enum StateTypes {
    // current character should put into next token
    BACKTRACE_STATE,
    // token is still not terminal
    NON_TERMINAL_STATE,
    // token is terminal with current charater
    TERMINAL_STATE,
};

class DFA
{
private:
    // [i, j] means positioned at i and get j as input
    int m_mat[DFA_NUM_STATES][DFA_VOCAB_SIZE];
    // Types of states
    int m_states_types[DFA_NUM_STATES];
    // Current state of DFA
    DFAState m_curState;

    void SetStateTypes(const int *states, int len, int type);
    // fill states for ASCII characters
    void SetMat(DFAState src_state, DFAState dst_state);
    // fill states for characters in ch_table
    void SetMat(DFAState src_state, DFAState dst_state, const char *ch_table);
    // fill states for ch only
    void SetMat(DFAState src_state, DFAState dst_state, const char &ch);

    // Initialize transition matrix
    void InitMat();

    // Initialize states types
    void InitStatesTypes();
public:
    DFA();

    // Get current state
    DFAState GetCurState();

    // Get next state with character ch starting from curState
    DFAState GetNextState(const char &ch);

    // Get type of given state
    int GetStateType(const int &state);

    // Set state
    void SetState(const int &state);

    // Move to the next state with ch
    int GotoNextState(const char &ch);
};