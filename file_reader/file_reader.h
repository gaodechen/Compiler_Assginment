/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: File Reader
 * @LastEditTime: 2020-04-28 21:21:10
 * @Date: 2020-04-18 17:58:11
 */

#define INC_FILE_READER

#include <cstdio>
#include <string>
#include <fstream>

#ifndef INC_UTILS
#include "../common/utils.h"
#endif

class FileReader
{
private:
    // Set true when file pointer points to the ending
    bool eof;
    int num_lines;
    std::ifstream file_stm;
public:
    FileReader(const std::string &filepath);

    ~FileReader();

    void Close();

    // Read one character from file
    void GetChar(char &ch);

    // To skip over blanks
    void FilterCh(char &ch);

    // Returns eof mark
    bool IsEOF();

    // Get number of lines
    int GetNumLines();
};
