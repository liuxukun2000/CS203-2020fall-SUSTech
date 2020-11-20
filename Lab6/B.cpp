#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int Next[1100000],n,m,j,pos=-1;
char b[1100000];
inline void getnext()
{
    Next[0]=-1;
    for(int i=1;i<=m;i)
    {
        if(pos==-1||b[pos+1]==b[i])
        {
               
            Next[i]=++pos;
            ++i;
        }
        else pos=Next[pos];
    }
}
int main()
{
    scanf("%s",b+1);
    m=strlen(b+1);
    getnext();
    for(int i=1;i<=m;++i)
    {
        printf("%d\n",Next[i]);
    }
}
/**************************************************************
    Problem: 1377
    User: 11912823
    Language: C++
    Result: 正确
    Time:112 ms
    Memory:7392 kb
****************************************************************/
