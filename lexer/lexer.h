/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: File Content
 * @LastEditTime: 2020-04-28 21:39:35
 * @Date: 2020-04-18 15:51:42
 */

#define INC_LEXER

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

#include "../common/utils.h"

#ifndef INC_FILE_READER
#include "../file_reader/file_reader.h"
#endif

#ifndef INC_VOCAB
#include "../lexer/vocab.h"
#endif

#ifndef INC_DFA
#include "../lexer/dfa.h"
#endif

#ifndef INC_LEX_TABLE
#include "../lexer/lex_table.h"
#endif

class Lexer
{
private:
    // Map vocabulary words to symbol
    Vocab *vocab;

    // Map token to type
    int GetTokenType(std::string token, int curState);

public:
    Lexer();

    // Lexical analysis from file
    LexTable Analyze(const std::string &filepath);
};
