/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Parser
 * @LastEditTime: 2020-05-03 21:51:07
 * @Date: 2020-04-22 22:31:22
 */

#define INC_PARSER

#include <stack>

#include "../common/utils.h"
#include "../parser/ins_table.h"
#include "../parser/sym_table.h"
#include "../common/compile_errors.h"
#include "../parser/astree.h"

#ifndef INC_LEXER
#include "../lexer/lexer.h"
#endif

class Parser
{
private:
    static const int DATA_OFFSET = 3;
    ASTree m_ast;
    InsTable m_ins_table;
    SymTable m_sym_table;
    LexTable *m_lex_table;
    int m_cur_line;
    LexItem m_cur_lex;

    bool IsType(int type);

    // Update current symbol
    void GetNextSymbol();
    void GetPrevSymbol();

    // Parse with recursion
    int Parse(int level, int index);

    // Check symbol with required type
    void TypeTest(int vocab_type);
    // Check if there is multiple definition
    void MultiDefTest(int offset);
    // Check if there is type error with the statment
    int DefTypeTest(int offset, int req_type);
    // Check if there are separate characters
    void SepChTest(int, int);
    // Check if there is logical operators
    void LopChTest();

    // Parse conditional exprs
    void _condition(int level, int index);
    // Parse statements
    void _statement(int level, int index);
    // Parse expression
    void _expression(int level, int index);
    // Parse poly items
    void _factor(int level, int index);

    int _const(int level, int index);
    int _var(int level, int index);
    int _procedure(int level, int index);

    void _if(int level, int index);
    void _while(int level, int index);
    void _call(int level, int index);
    void _read(int level, int index);
    void _write(int level, int index);
    void _assign(int level, int index);
    void _begin(int level, int index);
    void _end(int level, int index);
    void _term(int level, int index);

public:
    Parser(LexTable *_m_lex_table);
    InsTable Analyze();
};