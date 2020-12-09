#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
struct Edge
{
    int v, w;
    Edge(int vv, int ww)
    {
        v = vv;
        w = ww;
    }
    bool operator<(const Edge &b) const
    {
        return w < b.w;
    }
};
struct Node
{
    int u, v, pos, w;
    Node(int uu, int vv, int poss, int ww)
    {
        u = uu;
        v = vv;
        pos = poss;
        w = ww;
    }
    bool operator<(const Node &b) const
    {
        return w > b.w;
    }
};
int T, n, m,k, Q, Max, ask[51000], ans[51000];
vector<Edge> to[51000];
priority_queue<Node> q;
signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &n, &m, &Q);
        Max = 0;
        k=0;
        for (int i = 0; i <= n; i++)
        {
            to[i].clear();
        }
        for (int i = 0, u, v, w; i < m; i++)
        {
            scanf("%lld%lld%lld", &u, &v, &w);
            to[u].push_back(Edge(v, w));
        }
        for (int i = 0; i < Q; i++)
        {
            scanf("%lld", &ask[i]);
            Max = max(Max, ask[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            sort(to[i].begin(), to[i].end());
            if (to[i].size())
            {
                q.push(Node(i, to[i][0].v, 0, to[i][0].w));
            }
        }
        while (!q.empty())
        {
            Node tmp = q.top();
            q.pop();
            ans[++k] = tmp.w;
            if (k == Max)
            {
                while (!q.empty())
                {
                    q.pop();
                }
                break;
            }
            if (to[tmp.v].size())
            {
                q.push(Node(tmp.v, to[tmp.v][0].v, 0, tmp.w + to[tmp.v][0].w));
            }
            if (tmp.pos + 1 < to[tmp.u].size())
            {
                q.push(Node(tmp.u, to[tmp.u][tmp.pos + 1].v, tmp.pos + 1, tmp.w - to[tmp.u][tmp.pos].w + to[tmp.u][tmp.pos + 1].w));
            }
        }
        for (int i = 0; i < Q; i++)
        {
            printf("%lld\n", ans[ask[i]]);
        }
    }
}
