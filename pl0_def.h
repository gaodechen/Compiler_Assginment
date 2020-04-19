/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Fundamental definitions for PL/0
 * @LastEditTime: 2020-04-19 17:15:29
 * @Date: 2020-04-18 18:22:13
 */

#define INC_PL0_DEF

#include <string>

/**
 * @description: Vocabulary definition
 * @param {type} 
 * @return: 
 */

// Vocabulary words size for PL/0
const int VOCAB_SIZE = 29;

// vocabulary list
const std::string vocab_words[] = {
    "if", "while", "do", "then", "begin", "end", "call",
    "var", "const", "procedure",
    "read", "write", "odd",
    "(", ")", ",", ";", ".",
    "+", "-", "*", "/", ":=",
    "<>", "<", "<=", ">", ">=", "=",
};

// tyeps for vocabulary list
const std::string vocab_words_types[] = {
    // used to control processing stream
    "cp_if", "cp_while", "cp_do", "cp_then", "cp_begin", "cp_end", "cp_call",
    // used for definition
    "d_var", "d_const", "d_proc",
    // ordinary functions
    "f_read", "f_write", "f_odd",
    // separate characters
    "ch_lparen", "ch_rparen", "ch_comma", "ch_semi", "ch_perio",
    // arithmetic operators & assignment
    "aop_plus", "aop_minus", "aop_times", "aop_slash", "aop_assign",
    // logic operators
    "lop_neq", "lop_lss", "lop_leq", "lop_gtr", "lop_geq", "lop_eql",
};

/**
 * @description: DFA states definition
 * @param {type} 
 * @return: 
 */
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

const std::string ILLEGAL_VOCAB = "u_undef";
const std::string IDENTIFIER_VOCAB = "u_id";
const std::string NUMBER_VOCAB = "u_number";