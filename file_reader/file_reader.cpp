/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: File Reader
 * @LastEditTime: 2020-04-28 21:20:59
 * @Date: 2020-04-18 17:58:11
 */

#ifndef INC_FILE_READER
#include "../file_reader/file_reader.h"
#endif

FileReader::FileReader(const std::string &filepath)
{
    num_lines = 0;
    // freopen(filepath.c_str(), "r", stdin);
    file_stm.open(filepath.c_str(), std::ios::in);
}

FileReader::~FileReader()
{
    Close();
}

void FileReader::Close()
{
    file_stm.close();
}

void FileReader::GetChar(char &ch)
{
    eof = ((ch = file_stm.get()) == EOF);
    if (ch == '\n')
    {
        num_lines++;
    }
}

// to skip over blanks
void FileReader::FilterCh(char &ch)
{
    GetChar(ch);
    while (!eof && IsBlank(ch))
        GetChar(ch);
}

// Returns eof mark
bool FileReader::IsEOF()
{
    return eof;
}

int FileReader::GetNumLines()
{
    return num_lines;
}
