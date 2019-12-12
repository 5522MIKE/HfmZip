#ifndef UNCODE_H_INCLUDED
#define UNCODE_H_INCLUDED

#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<stack>
using namespace std;

//将0-256的数转换成8位二进制
string Bin(string t,int n);

int Uncode(vector<Hfm> T,string t,int sur,char *file);

int Uncode2(char *file1,char *file2);

#endif // UNCODE_H_INCLUDED
