#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include<algorithm>
#include<queue>
#define int long long
using namespace std;
struct Edge
{
    int v, w;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
struct Node
{
    int u, d;
    Node(int u, int d)
    {
        this->u = u;
        this->d = d;
    }
    bool operator<(const Node &x) const
    {
        return d > x.d;
    }
};
int n, m, sum, u, v, w, dis[1100];
bool vis[1100];
vector<Edge> to[1100];
priority_queue<Node> Q;
inline void work()
{
    while (!Q.empty())
    {
        Node x = Q.top();
        Q.pop();
        u = x.u;
        if (vis[u])
            continue;
        vis[u] = true;
        sum += dis[u];
        for (int i = 0; i < to[u].size(); i++)
        {
            Edge tmp = to[u][i];
            v = tmp.v;
            if (dis[u] < 0x3f3f3f3f && tmp.w < dis[v])
            {
                dis[v] = tmp.w;
                Q.push(Node(v, dis[v]));
            }
        }
    }
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u, &v, &w);
        to[u].push_back(Edge(v, w));
        to[v].push_back(Edge(u, w));
    }
    dis[1] = 0;
    Q.push(Node(1, dis[1]));
    work();
    printf("%lld\n", sum);
}