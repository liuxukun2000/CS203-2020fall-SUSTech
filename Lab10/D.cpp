#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define int long long
using namespace std;
const int Hash[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct Node
{
    int pos, dis;
    Node(int poss, int diss)
    {
        pos = poss;
        dis = diss;
    }
    bool operator<(const Node &b) const
    {
        return dis < b.dis;
    }
};
int n, m, val[51000], dis[51000], x, y,sum;
bool vis[51000];
priority_queue<Node> Q;
inline int getpos(int x, int y)
{
    return x * m + y;
}
inline int getx(int pos)
{
    return pos / m;
}
inline int gety(int pos)
{
    return pos % m;
}
inline void init()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &x);
            val[getpos(i, j)] = x;
            dis[getpos(i, j)] = 0;
        }
    }
    Q.push(Node(0, 0));
}
signed main()
{
    init();
    while (!Q.empty())
    {
        Node tmp = Q.top();
        Q.pop();
        if (vis[tmp.pos])
            continue;
        sum += dis[tmp.pos];
        vis[tmp.pos] = true;
        for (int i = 0; i < 4; i++)
        {
            x = getx(tmp.pos) + Hash[i][0];
            y = gety(tmp.pos) + Hash[i][1];
            int pos = getpos(x, y);
            if (0 <= x && x < n && 0 <= y && y < m && !vis[pos] &&
                val[tmp.pos] * val[pos] > dis[pos])
            {
                dis[pos] = val[tmp.pos] * val[pos];
                Q.push(Node(pos, dis[pos]));
            }
        }
    }
    printf("%lld", sum);
}
