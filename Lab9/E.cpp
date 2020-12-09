#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,a,b,u,v,T,vis[210000],op1,op2;
vector<int> to[210000];
long long ans,num[5];
int dfs(int x)
{
    if(x==a)
    {
        op1=1;
        return 0;
    }
    if(x==b)
    {
        op2=1;
        return 0;
    }
    int y,l=to[x].size(),tmp=1;
    vis[x]=1;
    for(int i=0;i<l;i++)
    {
        y=to[x][i];
        if(!vis[y])
        {
            tmp+=dfs(y);
        }
    }
    return tmp;
}
  
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(i==a||i==b) continue;
        if(!vis[i])
        {
            op1=op2=0;
            T=dfs(i);
            if(op1==1&&op2==0)
            {
                num[1]+=T;
            }
            else if(op1==0&&op2==1)
            {
                num[2]+=T;
            }
        }
    }
    ans=num[1]*num[2];
    printf("%lld",ans);
}
/**************************************************************
    Problem: 1390
    User: 11912823
    Language: C++
    Result: 正确
    Time:68 ms
    Memory:11068 kb
****************************************************************/