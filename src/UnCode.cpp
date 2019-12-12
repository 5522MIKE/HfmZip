#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<stack>

#include"HfmTree.h"
using namespace std;

string Bin(string t,int n)//将0-256的数转换成8位二进制
{
    map<int,int> change;
    change[7]=1;
    change[6]=2;
    change[5]=4;
    change[4]=8;
    change[3]=16;
    change[2]=32;
    change[1]=64;
    change[0]=128;
    string s;
    for(int j=0;j < t.size();j++)
    {
        unsigned char c=t[j];
        int a=c;
        for(int i=0;i<8;i++)
        {
            if(a>=change[i])
            {
                a-=change[i];
                s+='1';
            }
            else s+='0';
        }
    }
    int sur=8-n%8;
    while(sur--)
    {
        s.erase(s.end()-1);
    }
    return s;
}

int Uncode(vector<Hfm> T,string t,int sur,char *file)
{
    ofstream Un(file,ios::out|ios::binary);
    int r=T.size()-1;
    int temp=r;
    string s=Bin(t,sur);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            temp=T[r].lchild;
            if(T[temp].lchild==-1&&T[temp].rchild==-1)
            {
                Un.put(T[temp].name);
                r=T.size()-1;
            }
            else r=temp;
        }
        else
        {
            temp=T[r].rchild;
            if(T[temp].lchild==-1&&T[temp].rchild==-1)
            {
                Un.put(T[temp].name);
                r=T.size()-1;
            }
            else r=temp;
        }
    }
    Un.close();

    return 0;
}

int Uncode2(char *file1,char *file2)
{
    ifstream ss(file1,ios::in|ios::binary);
    int f;
    ss.read((char*)&f,sizeof(int));
    vector<Hfm> T0(f);
    ss.read((char*)&T0[0],T0.size()*sizeof(Hfm));
    int f2;
    ss.read((char*)&f2,sizeof(int));
    char x;
    string t;
    while(ss.get(x))
    {
        t+=x;
    }
    ss.close();
    Uncode(T0,t,f2,file2);
    cout<<"Unzipped!"<<endl;
    return 0;
}
