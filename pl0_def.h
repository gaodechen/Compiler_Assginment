/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Fundamental definitions for PL/0
 * @LastEditTime: 2020-04-18 19:46:19
 * @Date: 2020-04-18 18:22:13
 */

#include <string>

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
    "ifsym", "whilesym", "dosym", "thensym", "beginsym", "endsym", "callsym",
    "varsym", "constsym", "proceduresym",
    "readsym", "writesym", "oddsym",
    "lparen", "rparen", "comma", "semicolon", "perio",
    "plus", "minus", "times", "slash", "becomes",
    "neq", "lss", "leq", "gtr", "geq", "eql",
};

// characters should be filtered out
const char filter_ch[] = {' ', '\n', '\r', '\t'};

const char lower_ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const char upper_ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const char number_ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

const char operator_ch[] = {'+', '-', '*', '/', '=', '<', '>', ':', '(', ')', ',', ';', '.'};