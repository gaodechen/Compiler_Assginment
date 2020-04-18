/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: File Content
 * @LastEditTime: 2020-04-19 00:35:51
 * @Date: 2020-04-18 15:51:42
 */

#include <map>
#include <string>
#include <vector>

#ifndef INC_SYM_TOKEN
#include "sym_token.h"
#define INC_SYM_TOKEN
#endif

#include "lex_table.h"

class Lexer
{
private:
    // Vocabulary size for PL/0
    const static int m_VOCAB_SIZE = 29;
    // Vocabulary words of PL/0
    const static std::string m_vocab_words[m_VOCAB_SIZE];
    // Corresponding types for vocabulary words
    const static std::string m_vocab_words_types[m_VOCAB_SIZE];
    // Map vocabulary words to SymToken(int, string)
    std::map<std::string, SymToken> m_words_mapping;

    // Table of interpreted symbols
    std::map<std::string, int> m_symbols_table;
    // Table of constants
    std::map<std::string, int> m_constants_table;

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
