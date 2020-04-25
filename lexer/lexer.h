/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: File Content
 * @LastEditTime: 2020-04-25 17:22:01
 * @Date: 2020-04-18 15:51:42
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

#include "../lexer/dfa.h"
#include "../lexer/lex_table.h"
#include "../common/utils.h"
#include "../file_reader/file_reader.h"

#ifndef INC_VOCAB
#include "../lexer/vocab.h"
#endif

class Lexer
{
private:
    // Map vocabulary words to SymToken(sym_type, string)
    Vocab *vocab;

    // Map token to type
    int GetTokenType(std::string token, int curState);

public:
    Lexer();

    // Lexical analysis from file
    LexTable Analyze(const std::string &filepath);
};
