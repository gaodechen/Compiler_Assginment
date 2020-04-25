/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Fundamental definitions for PL/0
 * @LastEditTime: 2020-04-25 22:22:03
 * @Date: 2020-04-18 18:22:13
 */

#define INC_VOCAB

#include <map>
#include <iostream>
#include <string>

const int VOCAB_RESERVED_SIZE = 29;

/**
 * @description: Vocabulary definition
 * @param {type} 
 * @return: 
 */
struct VocabTypes {
    enum IllegalType {
        ILLEGAL_TYPE = -1,
    };
    enum ReservedTypes {
        CP_IF,
        CP_WHILE,
        CP_DO,
        CP_THEN,
        CP_BEGIN,
        CP_END,
        CP_CALL,
        D_VAR,
        D_CONST,
        D_PROC,
        F_READ,
        F_WRITE,
        F_ODD,
        CH_LPAREN,
        CH_RPAREN,
        CH_COMMA,
        CH_SEMI,
        CH_PERIO,
        AOP_PLUS,
        AOP_MINUS,
        AOP_TIMES,
        AOP_SLASH,
        AOP_ASSIGN,
        LOP_NEQ,
        LOP_LSS,
        LOP_LEQ,
        LOP_GTR,
        LOP_GEQ,
        LOP_EQL,
    };
    enum DataTypes {
        IDENTIFIER_DATA_TYPE = VOCAB_RESERVED_SIZE,
        CONST_DATA_TYPE,
    };
    enum DefTypes {
        CONST_DEF_TYPE,
        VAR_DEF_TYPE,
        PROCEDURE_DEF_TYPE,
    }
};

class Vocab
{
private:
    // vocabulary list
    std::string *m_vocab_words;
    std::string *m_vocab_types;
    std::map<std::string, int> m_words_mapping;
public:
    Vocab();
    int GetType(std::string str);
    std::string GetStrType(int type);
};

