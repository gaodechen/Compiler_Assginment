/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Parser
 * @LastEditTime: 2020-04-26 00:03:19
 * @Date: 2020-04-22 22:31:22
 */

#define INC_PARSER

#include "../common/utils.h"
#include "../lexer/lexer.h"
#include "../parser/opt_table.h"
#include "../parser/stdfunc.h"
#include "../parser/sym_table.h"
#include "../common/compile_errors.h"

class Parser
{
private:
    static const int DX_OFFSET = 3;
    OptTable m_opt_table;
    SymTable m_sym_table;
    LexTable *m_lex_table;
    LexItem m_cur_lex;

    // Update curSymbol
    void GetLexSymbol();

    void ParseStatement(int level, int index);

    int _const(int index);
    int _var(int level, int index);
    int _procedure(int level, int index);

    void _if(int level, int index);
    void _while(int level, int index);
    void _call(int level, int index);
    void _read(int level, int index);
    void _write(int level, int index);
    void _begin(int level, int index);
    void _odd(int level, int index);
    void _assign(int level, int index);

    int expr_condition(int level, int index);

public:
    Parser(LexTable *_m_lex_table);
    int Parse(int level, int idx);
};