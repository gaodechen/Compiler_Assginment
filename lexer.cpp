/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical Analysis for PL/0
 * @LastEditTime: 2020-04-19 18:07:42
 * @Date: 2020-04-15 23:02:24
 */

#include "lexer.h"
// #include "errors.h"

void Lexer::Init()
{
    for (int i = 0; i < VOCAB_SIZE; ++i)
    {
        m_words_mapping[vocab_words[i]] = SymToken(i, vocab_words_types[i]);
    }
}

// Get mapping results
SymToken Lexer::MapToken(std::string token, DFAState dfaState)
{
    if (m_words_mapping.count(token))
    {
        return m_words_mapping[token];
    }
    if (dfaState == IDENTIFIER_STATE)
    {
        return SymToken(IDENTIFIER_VOCAB);
    }
    if (dfaState == NUMBER_STATE)
    {
        return SymToken(NUMBER_VOCAB);
    }
    return SymToken(ILLEGAL_VOCAB);
}

LexTable Lexer::Analyze(const std::string &filepath)
{
    DFA dfa;
    LexTable lex_ret;
    FileReader file_reader(filepath);

    char ch = ' ';
    std::string token = "";

    file_reader.FilterCh(ch);
    dfa.SetState(NON_STATE);

    while (dfa.GetNextState(ch) != ILLEGAL_STATE)
    {
        // There would be one last token before '\0'
        if (file_reader.IsEOF())
        {
            ch = '\0';
        }
        DFAState curState = dfa.GotoNextState(ch);
        int curStateType = dfa.GetStateType(curState);
        // Token should be terminal added ch
        if (curStateType == TERMINAL_STATE)
        {
            token = token + std::string(1, ch);
            lex_ret.AddItem(token, MapToken(token, curState));
            token = "";
            dfa.SetState(NON_STATE);
            file_reader.FilterCh(ch);
        }
        // Continue the analysis process with next character
        else if (curStateType == BACKTRACE_STATE)
        {
            lex_ret.AddItem(token, MapToken(token, curState));
            token = "";
            dfa.SetState(NON_STATE);
            if (IsBlank(ch))
            {
                file_reader.FilterCh(ch);
            }
        }
        // Continue to read character
        else if (curStateType == NON_TERMINAL_STATE)
        {
            token = token + std::string(1, ch);
            file_reader.GetChar(ch);
        }
        // Finish analysis
        if (ch == '\0')
        {
            break;
        }
    }
    return lex_ret;
}