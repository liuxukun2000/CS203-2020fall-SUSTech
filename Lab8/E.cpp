#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, K, m, cnt = 0, a[201000], b[210000], ROOT[210000], sum[8010000], L[8010000], R[8010000];
inline int build(int l, int r)
{
    cnt++;
    int root = cnt;
    sum[root] = 0;
    if (l < r)
    {
        L[root] = build(l, (l + r) / 2);
        R[root] = build((l + r) / 2 + 1, r);
    }
    return root;
}
inline int update(int pre, int l, int r, int x)
{
    cnt++;
    int root = cnt;
    L[root] = L[pre];
    R[root] = R[pre];
    sum[root] = sum[pre] + 1;
    if (l < r)
    {
        if (x <= (l + r) / 2)
            L[root] = update(L[pre], l, (l + r) / 2, x);
        else
            R[root] = update(R[pre], (l + r) / 2 + 1, r, x);
    }
    return root;
}
 
inline int query(int u, int v, int l, int r, int k)
{
    if (l >= r)
        return l;
    int x = sum[L[v]] - sum[L[u]];
    if (x >= k)
        return query(L[u], L[v], l, (l + r) / 2, k);
    else
        return query(R[u], R[v], (l + r) / 2 + 1, r, k - x);
}
inline void init()
{
    scanf("%d%d", &m, &K);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + m);
    n = unique(b + 1, b + 1 + m) - b - 1;
    ROOT[0] = build(1, n);
    for (int i = 1; i <= m; i++)
    {
        int t = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        ROOT[i] = update(ROOT[i - 1], 1, n, t);
    }
}
int main()
{
    init();
    int x = 0, y, z, pos;
    for (int i = 1; i <= n-K + 1; i++)
    {
        y = x++ + K;
        scanf("%d", &z);
        pos = query(ROOT[x - 1], ROOT[y], 1, n, z);
        printf("%d\n", b[pos]);
    }
    return 0;
}
/**************************************************************
    Problem: 1203
    User: 11912823
    Language: C++
    Result: 正确
    Time:224 ms
    Memory:98320 kb
****************************************************************/
