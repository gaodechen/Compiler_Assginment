/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Vocab Definition
 * @LastEditTime: 2020-04-25 17:31:35
 * @Date: 2020-04-25 13:18:03
 */

#ifndef INC_VOCAB
#include "../lexer/vocab.h"
#endif

std::string vocab_words[VOCAB_RESERVED_SIZE] = {
    "if",
    "while",
    "do",
    "then",
    "begin",
    "end",
    "call",
    "var",
    "const",
    "procedure",
    "read",
    "write",
    "odd",
    "(",
    ")",
    ",",
    ";",
    ".",
    "+",
    "-",
    "*",
    "/",
    ":=",
    "<>",
    "<",
    "<=",
    ">",
    ">=",
    "=",
};

// tyeps for vocabulary list
std::string vocab_types[VOCAB_RESERVED_SIZE] = {
    // used to control processing stream
    "cp_if",
    "cp_while",
    "cp_do",
    "cp_then",
    "cp_begin",
    "cp_end",
    "cp_call",
    // used for definition
    "d_var",
    "d_const",
    "d_proc",
    // ordinary functions
    "f_read",
    "f_write",
    "f_odd",
    // separate characters
    "ch_lparen",
    "ch_rparen",
    "ch_comma",
    "ch_semi",
    "ch_perio",
    // arithmetic operators & assignment
    "aop_plus",
    "aop_minus",
    "aop_times",
    "aop_slash",
    "aop_assign",
    // logic operators
    "lop_neq",
    "lop_lss",
    "lop_leq",
    "lop_gtr",
    "lop_geq",
    "lop_eql",
};

Vocab::Vocab()
{
    m_vocab_words = vocab_words;
    m_vocab_types = vocab_types;
    for (int i = 0; i < VOCAB_RESERVED_SIZE; ++i)
    {
        m_words_mapping[m_vocab_words[i]] = i;
    }
}

/**
 * @description: Given string token, returns type of the token
 * @param {type} 
 * @return: 
 */
int Vocab::GetType(std::string str)
{
    if (m_words_mapping.count(str))
    {
        return (int) m_words_mapping[str];
    }
    return (int) VocabTypes::ILLEGAL_TYPE;
}

/**
 * @description: Given type, returns string symbol of the type
 * @param {type} 
 * @return: 
 */
std::string Vocab::GetStrType(int type)
{
    return m_vocab_types[type];
}