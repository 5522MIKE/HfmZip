#ifndef HFMTREE_H_INCLUDED
#define HFMTREE_H_INCLUDED

#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

//Hfm的结构
struct Hfm
{
    char name;
    int val;
    int parent,lchild,rchild;
    void Show()
    {
        cout<<name<<" "<<val<<" "<<parent<<" "<<lchild<<" "<<rchild<<endl;
    }
};

//选择两个权值最小的根节点
int Select(vector<Hfm> T,int &m,int &n);

//通过节点构建树
int CreatTree(map<char,int> arr,vector<Hfm> &T);

//将树转化为哈夫曼树
int Hfmcode(vector<Hfm> T,map<char,string> &Code);

//将01二进制数转换成字符
string Str(string s);

//压缩
int Compresses(vector<Hfm> T,string s,char *file);

#endif // HFMTREE_H_INCLUDED
