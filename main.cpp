/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Entrance for PL/0 Compiler
 * @LastEditTime: 2020-04-19 00:02:20
 * @Date: 2020-04-18 15:42:05
 */

#include "lexer.h"

int main(int argc, char **argv)
{
    std::string dir_path = "./test_data/";
    std::string file_path = "PL0_code";
    std::string file_ext = ".in";
    if (argc == 2)
    {
        file_path = file_path + std::string(argv[1]);
    }

    Lexer lexer;
    lexer.Init();
    LexTable lex_ret = lexer.Analyze(dir_path + file_path + file_ext);

    return 0;
}
