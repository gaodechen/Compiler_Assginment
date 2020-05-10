/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Entrance for PL/0 Compiler
 * @LastEditTime: 2020-05-09 19:33:37
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
    std::string dir_path = "./test_data/";
    std::string file_path = "PL0_code0";
    std::string file_ext = ".in";

    for (int idx = 1; idx < argc; idx++)
    {
        std::string arg(argv[idx]);
        if (arg == "-f")
        {
            file_path = std::string(argv[++idx]);
        }
        else if (arg == "-e")
        {
            exec = true;
        }
        else if (arg == "-p")
        {
            std::string print_obj(argv[++idx]);
            print_lex = (print_obj == "lex");
            print_ins = (print_obj == "ins");
        }
        else
        {
            file_path = file_path + arg;
        }
    }
    std::string full_path = dir_path + file_path + file_ext;

    Lexer lexer;
    LexTable lex = lexer.Analyze(full_path);
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
        mac.Intepret();
    }

    return 0;
}
