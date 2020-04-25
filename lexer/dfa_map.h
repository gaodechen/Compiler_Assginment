/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: DFA Mapping Config
 * @LastEditTime: 2020-04-25 16:21:12
 * @Date: 2020-04-25 12:34:50
 */

/**
 * @description: DFA states definition
 * @param {type} 
 * @return: 
 */

#define INC_DFA_MAP

#include <string>

// Maximum number of states
const int DFA_NUM_STATES = 24;
// ASCII maximum index
const int DFA_VOCAB_SIZE = 128;

// characters should be filtered out
const char filter_ch[] = {' ', '\n', '\r', '\t'};

const char lower_ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const char upper_ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const char number_ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

const char operator_ch[] = {'+', '-', '*', '/', '=', '<', '>', ':', '(', ')', ',', ';', '.'};

const int terminal_states[] = {5, 6, 7, 8, 9, 13, 14, 15, 16, 17, 18, 19, 21, 23};
const int non_terminal_states[] = {0, 1, 3, 10, 11, 12};
const int backtrace_states[] = {2, 4, 20, 22};

// Special states
const int ILLEGAL_STATE = -1;
const int NON_STATE = 0;
const int IDENTIFIER_STATE = 2;
const int NUMBER_STATE = 4;
