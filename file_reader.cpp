/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: File Reader
 * @LastEditTime: 2020-04-18 23:55:49
 * @Date: 2020-04-18 17:58:11
 */

#include "file_reader.h"
#include "utils.h"

FileReader::FileReader(const std::string &filepath)
{
    freopen(filepath.c_str(), "r", stdin);
}

FileReader::~FileReader()
{
    fclose(stdin);
}

void FileReader::GetChar(char &ch)
{
    eof = !(~scanf("%c", &ch));
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