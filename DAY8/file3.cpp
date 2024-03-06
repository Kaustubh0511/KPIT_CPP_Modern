#include <iostream>
using namespace std;
#define line(msg) std::cout << "------------------------"#msg"-------------------------\n";


typedef void (*FPTR)();


void WriteFile()
{
    cout << "Write File\n";
}


void FileClose()
{
    cout << "FileClose\n";
}


FPTR FileOpen()
{
    cout << "FileOpen\n";
    return &FileClose;
}


int main()
{
    FPTR fp = FileOpen();
    WriteFile();
    WriteFile();
    WriteFile();
    fp();

    return 0;
}
