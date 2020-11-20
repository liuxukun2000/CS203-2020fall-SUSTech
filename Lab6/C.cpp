#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int n,m,x,y,l,len[1002],ans;
char s[1002][1002],op;
inline int judge(int a,int b)
{
    l=min(len[a],len[b]);
    int tmp=0;
    for(int i=0;i<l;i++)
    {
        if(s[a][1+i]==s[b][len[b]-i]) tmp++;
        else break;
    }
    return tmp;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        len[i]=strlen(s[i]+1);
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d %c",&x,&y,&op);
        if(op=='<')
        {
            judge(x,y)<judge(y,x) ? ans++:0;
        }
        else if(op=='>')
        {
            judge(x,y)>judge(y,x) ? ans++:0;
        }
        else
        {
            judge(x,y)==judge(y,x) ? ans++:0;
        }
         
    }
    printf("%d\n",ans);
}
/**************************************************************
    Problem: 1356
    User: 11912823
    Language: C++
    Result: 正确
    Time:16 ms
    Memory:3008 kb
****************************************************************/
