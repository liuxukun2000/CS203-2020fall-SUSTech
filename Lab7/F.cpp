#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
int T, n, q, m, l, x, y, ans, pos;
vector<int> v;
struct Edge
{
    int to, Next, val;
    void push(int a, int b)
    {
        to = a;
        Next = b;
        val = 1;
    }
} edge[210000];
int w[110000], head[110000], cnt, lg[210000], dfn[110000], dep[110000], tot, f[210000][20];
void get_lcainit()
{
    cnt = 0;
    tot = 0;
    memset(head, 0, sizeof(head));
    memset(dep,0,sizeof(dep));
    memset(w, 0, sizeof(w));
}
void add(int u, int v)
{
    edge[++cnt].push(v, head[u]);
    head[u] = cnt;
}
void dfs(int u, int fa)
{
    f[++tot][0] = u;
    dfn[u] = tot;
    dep[u] = dep[fa] + 1;
    for (signed i = head[u]; i; i = edge[i].Next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        w[v] = w[u] + edge[i].val;
        dfs(v, u);
        f[++tot][0] = u;
    }
}
void getf()
{
    lg[1] = 0;
    for (signed i = 2; i <= tot; i++)
        lg[i] = lg[i >> 1] + 1;
    for (signed j = 1; j <= 19; j++)
    {
        for (signed i = 1; i + (1 << j) - 1 <= tot; i++)
        {
            dep[f[i][j - 1]] < dep[f[i + (1 << j - 1)][j - 1]] ? f[i][j] = f[i][j - 1] : f[i][j] = f[i + (1 << j - 1)][j - 1];
        }
    }
}
int get_lca(int u, int v)
{
    u = dfn[u];
    v = dfn[v];
    if (u > v)
        swap(u, v);
    int len = lg[v - u + 1];
    if (dep[f[u][len]] < dep[f[v - (1 << len) + 1][len]])
    {
        return f[u][len];
    }
    else
    {
        return f[v - (1 << len) + 1][len];
    }
}
int get_dis(int u, int v)
{
    int tmp = get_lca(u, v);
    return w[u] + w[v] - w[tmp] - w[tmp];
}
inline void init()
{
    scanf("%lld%lld", &n, &m);
    get_lcainit();
    for (int i = 1; i < n; i++)
    {
        scanf("%lld%lld", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    getf();
    pos = 0;
    ans = 0;
    v.clear();
}
void work()
{
    init();
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &x);
        v.push_back(x);
        if (pos==0||dep[pos] < dep[x])
        {
            pos = x;
        }
    }
    l = v.size();
    for (int i = 0; i < l; i++)
    {
        x = v[i];
        ans = max(ans, (get_dis(x, pos) + (long long)1) / (long long)2);
    }
    printf("%lld\n", ans);
}
signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        work();
    }
}
/*
2
4 2
1 2
2 4
2 3
1 3
4 2
1 2
2 4
2 3
1 1
*/
 
/**************************************************************
    Problem: 1240
    User: 11912823
    Language: C++
    Result: 正确
    Time:260 ms
    Memory:45688 kb
****************************************************************/
