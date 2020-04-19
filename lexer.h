/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: File Content
 * @LastEditTime: 2020-04-19 15:54:36
 * @Date: 2020-04-18 15:51:42
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

#include "dfa.h"
#include "file_reader.h"
#include "lex_table.h"
#include "utils.h"

#ifndef INC_PL0_DEF
#include "pl0_def.h"
#endif

#ifndef INC_SYM_TOKEN
#include "sym_token.h"
#endif

class Lexer
{
private:
    // Map vocabulary words to SymToken(int, string)
    std::map<std::string, SymToken> m_words_mapping;

    // Map token to SymToken struct
    SymToken MapToken(std::string token, int dfaState);

    // Insert token to table
    void InsertToken(std::map<std::string, int> &table, const std::string &token);

public:
    // Initialize from filepath
    void Init();

    // Lexical analysis
    LexTable Analyze(const std::string &filepath);
};
