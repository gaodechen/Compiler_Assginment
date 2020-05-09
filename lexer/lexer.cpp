/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Lexical Analysis for PL/0
 * @LastEditTime: 2020-04-28 21:32:48
 * @Date: 2020-04-15 23:02:24
 */

#ifndef INC_LEXER
#include "../lexer/lexer.h"
#endif

#ifndef INC_COMPILE_ERRORS
#include "../common/compile_errors.h"
#endif

#ifndef INC_VOCAB
#include "../lexer/vocab.h"
#endif

Lexer::Lexer()
{
    vocab = new Vocab();
}

int Lexer::GetTokenType(std::string token, int cur_state)
{
    int type = vocab->GetType(token);
    if (type != VocabTypes::ILLEGAL_TYPE)
        return type;
    switch (cur_state)
    {
    case IDENTIFIER_STATE:
        type = VocabTypes::IDENTIFIER_DATA_TYPE;
        break;
    case NUMBER_STATE:
        type = VocabTypes::CONST_DATA_TYPE;
        break;
    }
    return type;
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
        DFAState cur_state = dfa.GotoNextState(ch);
        int cur_stateType = dfa.GetStateType(cur_state);
        int line_num = file_reader.GetNumLines() + 1;
        // Token should be terminal added ch
        if (cur_stateType == TERMINAL_STATE)
        {
            token = token + std::string(1, ch);
            lex_ret.Append(token, GetTokenType(token, cur_state), line_num);
            token = "";
            dfa.SetState(NON_STATE);
            file_reader.FilterCh(ch);
        }
        // Continue the analysis process with next character
        else if (cur_stateType == BACKTRACE_STATE)
        {
            lex_ret.Append(token, GetTokenType(token, cur_state), line_num);
            token = "";
            dfa.SetState(NON_STATE);
            if (IsBlank(ch))
            {
                file_reader.FilterCh(ch);
            }
        }
        // Continue to read character
        else if (cur_stateType == NON_TERMINAL_STATE)
        {
            token = token + std::string(1, ch);
            file_reader.GetChar(ch);
        }
        // Errors occur
        else if (ch != '\0')
        {
            GlobalErrors::CatchError(UNDEFINED_IDENTIFIER_ERROR, line_num);
        }
        else
        {
            break;
        }
    }
    return lex_ret;
}