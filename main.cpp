/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Entrance for PL/0 Compiler
 * @LastEditTime: 2020-05-12 22:03:07
 * @Date: 2020-04-18 15:42:05
 */

#include "./lexer/lexer.h"
#include "./parser/parser.h"
#include "./machine/machine.h"

int main(int argc, char **argv)
{
    bool exec = true;
    bool print_lex = false;
    bool print_ins = false;
    std::string file_path = "";

    for (int idx = 1; idx < argc; idx++)
    {
        std::string arg(argv[idx]);
        if (arg == "-e")
        {
            // Do not execute
            exec = false;
        }
        else if (arg == "-p")
        {
            std::string print_obj(argv[++idx]);
            // Display lexical or instruction table
            print_lex = (print_obj == "lex");
            print_ins = (print_obj == "ins");
        }
        else
        {
            // Given filepath
            file_path = arg;
        }
    }

    if (file_path == "")
    {
        GlobalErrors::CatchError(ILLEGAL_FILE_PATH);
        return -1;
    }

    Lexer lexer;
    LexTable lex = lexer.Analyze(file_path);
    Parser parser(&lex);
    InsTable ins = parser.Analyze();

    if (print_lex)
    {
        std::cout << lex;
    }
    if (print_ins)
    {
        std::cout << ins;
    }
    if (exec)
    {
        Machine mac(ins);
        mac.Interpret();
    }

    return 0;
}
