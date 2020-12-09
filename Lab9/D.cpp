#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, num, u, v, w, l, deep[811111], ans = -1, op = 0;
vector<int> to[811111];
queue<int> q;
inline void init()
{
    to[0].push_back(1);
    num = n + 1;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        w == 1 ? to[u].push_back(v) : to[u].push_back(num), to[num++].push_back(v);
    }
    memset(deep, -1, sizeof(deep));
    q.push(0);
}
int main()
{
    scanf("%d%d", &n, &m);
    init();
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        l = to[u].size();
        for (int i = 0; i < l; i++)
        {
            v = to[u][i];
            if (deep[v] != -1)
            {
                continue;
            }    
            deep[v] = deep[u] + 1;
            if (v == n)
            {
                ans = deep[v];
                op = 1;
                break;
            }
            q.push(v);
        }
        if (op)
            break;
    }
    printf("%d\n", ans);
}
