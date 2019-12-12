#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<stack>

#include"HfmTree.h"
#include"ShowHelp.h"
#include"UnCode.h"
using namespace std;

//程序主入口
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        ShowHelp();
    }
    else if(strcmp(argv[1],"zip")==0)
    {

    //文件输入，以二进制形式
    ifstream infile(argv[2],ios::in|ios::binary);

    //判断文件是否打开
    if(!infile) {
        cout<<"false open "<<argv[2]<<endl;
        return 0;
    }

    //文件以string的形式写入
    string s;
    map<char,int> arr;
    char ch;
    while(infile.get(ch))
    {
        arr[ch]++;
        s+=ch;
    }
    //关闭文件
    infile.close();

    //建树
    vector<Hfm> T;
    map<char,string> Code;
    CreatTree(arr,T);
    Hfmcode(T,Code);

    //
    string Zip;
    for(int i=0;i<s.size();i++)
    {
        Zip+=Code[s[i]];
    }
    //压缩
    Compresses(T,Zip,argv[3]);
    }

    //解压缩
    else if(strcmp(argv[1],"unzip")==0)
    {
        cout<<"Unzipping..."<<endl;
        Uncode2(argv[2],argv[3]);
    }

    //报错
    else ShowHelp();
    return 0;
}
