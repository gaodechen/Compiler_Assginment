/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Deterministic Finite Automaton
 * @LastEditTime: 2020-04-19 00:29:38
 * @Date: 2020-04-18 17:20:31
 */

#include <map>
#include <string>

#ifndef INC_SYM_TOKEN
#include "sym_token.h"
#define INC_SYM_TOKEN
#endif

typedef int DFAState;

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
    // Maximum number of states
    const static int m_NUM_STATES = 128;
    // ASCII maximum index
    const static int m_VOCAB_SIZE = 128;
    // [i, j] means positioned at i and get j as input
    int m_mat[m_NUM_STATES][m_VOCAB_SIZE];
    // Types of states
    int m_states_types[m_NUM_STATES];
    // Current state of DFA
    DFAState curState;
    // Map string token to vocabulary type
    std::map<std::string, SymToken> m_reserved_words_mapping;

    // fill states for ASCII characters
    void FillTransState(DFAState src_state, DFAState dst_state);
    // fill states for characters in ch_table
    void FillTransState(DFAState src_state, DFAState dst_state, const char *ch_table);
    // fill states for ch only
    void FillTransState(DFAState src_state, DFAState dst_state, const char &ch);

    // Initialize transition matrix
    void InitTransMat();

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

    // Move to the next state with ch
    int SetState(const char &ch);
};