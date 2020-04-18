/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical Analysis for PL/0
 * @LastEditTime: 2020-04-19 00:35:20
 * @Date: 2020-04-15 23:02:24
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

#include "lexer.h"
#include "dfa.h"
#include "pl0_def.h"
#include "file_reader.h"
#include "utils.h"

#ifndef INC_SYM_TOKEN
#include "sym_token.h"
#define INC_SYM_TOKEN
#endif

void Lexer::Init()
{
    for (int i = 0; i < m_VOCAB_SIZE; ++i)
    {
        m_words_mapping[vocab_words[i]] = SymToken(i, vocab_words_types[i]);
    }
}

// Get mapping results
SymToken Lexer::MapToken(std::string token, int dfaState)
{
    if (m_words_mapping.count(token))
        return m_words_mapping[token];
    else if (dfaState == 2)
        return SymToken(0, "identifier");
    else
        return SymToken(0, "number");
    return SymToken(0, "undefined");
}

void InsertToken(std::map<std::string, int> &table, const std::string &token)
{
    table[token] = table.size() + 1;
}

LexTable Lexer::Analyze(const std::string &filepath)
{
    DFA dfa;
    LexTable lex_ret;
    FileReader file_reader(filepath);

    char ch = ' ';
    std::string token = "";

    file_reader.FilterCh(ch);

    while (~dfa.GetNextState(ch))
    {
        if (file_reader.IsEOF())
            ch = '\0';
        int curState = dfa.SetState(ch);
        int curStateType = dfa.GetStateType(curState);
        if (curStateType == TERMINAL_STATE)
        {
            token = token + std::string(1, ch);
            file_reader.FilterCh(ch);
            dfa.SetState(0);
            token = "";
        }
        else if (curStateType != NON_TERMINAL_STATE)
        {
            token = Concat(token, ch);
            file_reader.GetChar(ch);
        }
        // Continue the analysis process with next character
        else if (curStateType == BACKTRACE_STATE)
        {
            lex_ret.AddItem(token, MapToken(token, curState).GetType());
            token = "";
            dfa.SetState(0);
            if (IsBlank(ch))
                file_reader.FilterCh(ch);
        }
        else
        {
            std::cout << "error!" << std::endl;
            break;
        }
        if (ch == '\0')
            break;
    }
    return lex_ret;
}