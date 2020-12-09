#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include<algorithm>
using namespace std;
int  n, m, u, v,vis[110000],ans=0;
vector<int> to[110000];
struct Node
{
    int x,y;
    Node(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
    bool operator<(const Node &b)
    {
        return x<b.x;
    }
};
vector<Node> test;
void dfs(int x,int f)
{
    int y,l;
    l=to[x].size();
    vis[x]=1;
    for(int i=0;i<l;i++)
    {
        y=to[x][i];
        if(y==f) continue;
        if(vis[y]==1)
        {
            ans=1;
            return;
        }
        else if(vis[y]==0)
        {
            dfs(y,x);
            if(ans) return;
        }
    }
    vis[x]=2;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        if(u==v) ans=1;
        to[u].push_back(v);
        to[v].push_back(u);
        test.push_back(Node(min(u,v),max(u,v)));
    }
    sort(test.begin(),test.end());
    for(int i=1;i<m;i++)
    {
        if(test[i].x==test[i-1].x&&test[i].y==test[i-1].y)
        {
            ans=1;
            break;
        }
    }
    dfs(1,0);
    ans ? puts("Bad"):puts("Good");
}
