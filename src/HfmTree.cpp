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
int Select(vector<Hfm> T,int &m,int &n)
{
    m=-1,n=-2;
    for(int i=0;i < T.size();i++)
    {
        if(T[i].parent==-1)
        {
            if(m==-1||T[m].val>T[i].val)
            {
                n=m;
                m=i;
            }
            else if(n==-1||T[n].val>T[i].val)
            {
                n=i;
            }
        }
    }
    return 0;
}

//通过节点构建树
int CreatTree(map<char,int> arr,vector<Hfm> &T)
{
    int len=arr.size();
    map<char,int>::iterator iter;
	for (iter = arr.begin(); iter != arr.end(); iter++) {
        Hfm tt;
        tt.name=iter->first;
        tt.val=iter->second;
        tt.parent=-1;
        tt.lchild=-1;
        tt.rchild=-1;
        T.push_back(tt);
	}
    for(int i=0;i<len-1;i++)
    {
        int m,n;
        Select(T,m,n);
        Hfm tt;
        tt.name=-1;
        tt.val=T[m].val+T[n].val;
        tt.parent=-1;
        tt.lchild=m;
        tt.rchild=n;
        T.push_back(tt);
        //T.push_back(Hfm(-1,T[m].val+T[n].val,-1,m,n));
        T[m].parent=T.size()-1;
        T[n].parent=T.size()-1;
    }
    return 0;
}

//将树转化为哈夫曼树
int Hfmcode(vector<Hfm> T,map<char,string> &Code)
{
    for(int i=0;i < T.size();i++)
    {
        string s;
        stack<char> c;
        if(T[i].lchild==-1&&T[i].rchild==-1)
        {
            int j=i;
            while(T[j].parent>=0){
                    int temp=j;
            j=T[j].parent;
            if(T[j].lchild==temp)
            {
                c.push('0');
            }
            else c.push('1');
            }
        }
        else break;
        while(!c.empty())
        {
            s=s+c.top();
            c.pop();
        }
        Code[T[i].name]=s;
    }
    return 0;
}

//将01二进制数转换成字符
string Str(string s)
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
    unsigned char c;//由于大小问题，此处一定要用unsign
    int n=0;
    string t;
    for(int i=0;i < s.size();i++)
    {
        if(i%8==0 && i!=0)
        {
            c=n;
            t+=c;
            n=0;
        }
        if(s[i]=='1')
            n+=change[i%8];
    }
    c=n;
    t+=c;
    return t;
}

//压缩
int Compresses(vector<Hfm> T,string s,char *file)
{
    cout<<"Zipping..."<<endl;
    ofstream out(file,ios::out|ios::binary);
    int num=T.size();
    out.write((char*)&num,sizeof(int));//树的大小
    out.write((char*)&T[0],T.size()*sizeof(Hfm));//哈夫曼树
    int num2=s.size();
    out.write((char*)&num2,sizeof(int));//文件的大小
    out<<Str(s);//哈夫曼编码
    cout<<"Zipped!"<<endl;
    out.close();
    return 0;
}
