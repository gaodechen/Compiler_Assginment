/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: Entrance for PL/0 Compiler
 * @LastEditTime: 2020-04-25 22:10:17
 * @Date: 2020-04-18 15:42:05
 */

#include "./lexer/lexer.h"
#include "./parser/parser.h"

int main(int argc, char **argv)
{
    std::string dir_path = "./test_data/";
    std::string file_path = "PL0_code";
    std::string file_ext = ".in";
    if (argc == 2)
    {
        file_path = file_path + std::string(argv[1]);
    }
    else if (argc == 3)
    {
        if (std::string(argv[2]) == "-f")
        {
            file_path = std::string(argv[2]);
        }
    }
    std::string full_path = dir_path + file_path + file_ext;

    Lexer lexer;
    LexTable lex = lexer.Analyze(full_path);
    Parser parser(&lex);

    return 0;
}
