#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<int> q;
vector<int> to[110000];
int T, n,u,v,l;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            to[i].clear();
        }
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&v);
            to[v].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            sort(to[i].begin(),to[i].end());
        }
        q.push(1);
        printf("1 ");
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            l=to[u].size();
            for(int i=0;i<l;i++)
            {
                printf("%d ",to[u][i]);
                q.push(to[u][i]);
            }
        }
        puts("");
    }
}
 
/**************************************************************
    Problem: 1383
    User: 11912823
    Language: C++
    Result: 正确
    Time:436 ms
    Memory:7248 kb
****************************************************************/
