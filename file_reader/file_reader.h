/*
 * @Author: Gao Dechen
 * @LastEditors: Gao Dechen
 * @Description: File Reader
 * @LastEditTime: 2020-04-18 23:53:33
 * @Date: 2020-04-18 17:58:11
 */

#include <cstdio>
#include <string>

class FileReader
{
private:
    // Set true when file pointer points to the ending
    bool eof;
public:
    FileReader(const std::string &filepath);

    ~FileReader();

    // Read one character from file
    void GetChar(char &ch);

    // To skip over blanks
    void FilterCh(char &ch);

    // Returns eof mark
    bool IsEOF();
};