#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

//如果输入错误，展示报错信息
int ShowHelp()
{
    cout << "This is a [Zip|unZip] project" << endl;
    cout << "you can use \"[Zip|unZip] filename.txt filename.hfmzip \" to use this project!" << endl;
    cout << "use HfmZip -> zip sourcefile to destfile" << endl;
    cout << "use unHfmZip -> extract sourcefile to destfile." << endl;
    return 0;
}
