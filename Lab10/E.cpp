#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include<cmath>
using namespace std;
int n,m,u,v,t,head[110010],Next[250010],cnt=1,to[250010],dnf[210010],low[210010],s[210010],top,cir[210010],num,out[210010];
int sum[210010],d[110000];
vector<int> edg[210000];
inline void add(int x,int y)
{
    to[++cnt]=y;
    Next[cnt]=head[x];
    head[x]=cnt;
}
void Tarjan(int x)
{
    low[x]=dnf[x]=cnt++;
    s[++top]=x;
    for(int i=head[x];i;i=Next[i])
    {
        int y=to[i];
        if(!dnf[y])
        {
            Tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(!cir[y])
        {
            low[x]=min(low[x],dnf[y]);
        }
    }
    if(low[x]==dnf[x])
    {
        cir[x]=++num;
        sum[num]++;
        while(s[top]!=x)
        {
            cir[s[top]]=num;
            //cout<<s[top]<<" ";
            top--;
            sum[num]++;
        }
        //cout<<x<<endl;
        top--;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&u,&v);
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&d[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<edg[i].size();j++)
        {
            if(d[i]+1==d[edg[i][j]]||abs(d[i]+1-d[edg[i][j]])%t==0)
            {
                add(i,edg[i][j]);
            }
        }
    }
    memset(low,0x3f3f3f3f,sizeof(low));
    cnt=1;
    for(int i=1;i<=m;i++)
    {
        if(!dnf[i]) Tarjan(i);
    }
    for(int i=1;i<=m;i++)
    {
        if(!out[cir[i]])
        {
            for(int j=head[i];j;j=Next[j])
            {
                int y=to[j]; 
                if(cir[y]!=cir[i])
                {
                    out[cir[i]]++;
                    break;
                }
            }
        }
    }
    int ans=m;
    for(int i=1;i<=num;i++)
    {
        if(out[i]==0)
        {
            ans=min(ans,sum[i]);
        }
    }
    cout<<ans;
    /*getchar();
    getchar();*/
}
/*
6 8
1 3
1 2
2 4
3 4
3 5
4 1
4 6
5 6
*/
/**************************************************************
    Problem: 1395
    User: 11912823
    Language: C++
    Result: 正确
    Time:88 ms
    Memory:17456 kb
****************************************************************/