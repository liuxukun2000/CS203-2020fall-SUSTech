#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,u,v;
bool vis[110000];

vector<int> to[110000];
struct Node
{
    int pos,num;
    bool operator<(const Node &b) const
    {
        
        return pos>b.pos;
    }
}a[110000];
priority_queue<Node> q;
/*inline bool cmp(Node a,Node b)
{
    return a.num<b.num;
}

void dfs(int x,int deep)
{
    vis[x]=1;
    a[x].num=deep;
    int y,l=to[x].size();
    for(int i=0;i<l;i++)
    {
        y=to[x][i];
        if(!vis[y])
        {
            dfs(y,deep+1);
        }
    }
}*/
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        a[i].pos=i;
        a[i].num=0;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        to[u].push_back(v);
        a[v].num++;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].num==0) q.push(a[i]);
    }
    while(!q.empty())
    {
        Node tmp=q.top();
        int y,l=to[tmp.pos].size();
        q.pop();
        printf("%d ",tmp.pos);
        for(int i=0;i<l;i++)
        {
            y=to[tmp.pos][i];
            a[y].num--;
            if(a[y].num==0) q.push(a[y]);
        }

    }

}