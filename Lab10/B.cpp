#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, cnt1, cnt2, u, v;
bool vis[210000];
vector<int> to[210000];
vector<int> To[210000];
void dfs1(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    cnt1++;
    int l=to[x].size();
    for (int i = 0; i < l; i++)
    {
        dfs1(to[x][i]);
    }
}
void dfs2(int x)
{
    if (vis[x])
        return;
    vis[x] = true;
    ++cnt2;
    int l=To[x].size();
    for (int i = 0; i < l; i++)
    {
        dfs2(To[x][i]);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        to[u].push_back(v);
        To[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    dfs1(1);
    memset(vis, 0, sizeof(vis));
    dfs2(1);
    if (cnt1 == n && cnt2 == n)
        puts("Bravo");
    else
        puts("wawawa");
}
