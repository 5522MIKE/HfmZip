#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

//����������չʾ������Ϣ
int ShowHelp()
{
    cout << "This is a [HfmZip|unHfmZip] project" << endl;
    cout << "you can use \"[HfmZip|unHfmZip] filename.txt filename.hfmzip \" to use this project!" << endl;
    cout << "use HfmZip -> zip sourcefile to destfile" << endl;
    cout << "use unHfmZip -> extract sourcefile to destfile." << endl;
    return 0;
}
