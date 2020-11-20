#pragma GCC optimize(2)
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
int n, q, ans, L, R,b[310000], c[310000];
class node
{
public:
    int val, index;
    node(int v=0, int i=0)
    {
        val = v;
        index = i;
    }
    bool operator<(const node &b) const
    {
        return val < b.val;
    }
} RMQ[310000][23];
class Stack
{
public:
    int tp;
    node stack[310000];
    Stack()
    {
        tp = -1;
    }
    void init()
    {
        tp = -1;
    }
    int length()
    {
        return tp + 1;
    }
    void push(node x)
    {
        stack[++tp] = x;
    }
    void pop()
    {
        if (length() > 0)
            --tp;
    }
    node top()
    {
        if (length() > 0)
            return stack[tp];
        return node(0, 0);
    }
} stack;
inline int lowbit(int x)
{
    return x & -x;
}
void add(int x, int op)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        if (op)
            b[i]++;
        else
            c[i]++;
    }
}
long long query(int x, int op)
{
    long long tmp1 = 0, tmp2 = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        tmp1 += b[i];
        tmp2 += c[i];
    }
    return op ? tmp1 : tmp2;
}
 
inline int get(int l, int r)
{
    int t = log2(r - l + 1);
    return max(RMQ[l][t], RMQ[r - (1 << t) + 1][t]).index;
}
inline void init()
{
    stack.init();
    int T = log2(n) + 1;
    for (int j = 1; j < T; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            RMQ[i][j] = max(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        while (stack.length() > 0 && stack.top().val <= RMQ[i][0].val)
        {
            if (stack.top().val == RMQ[i][0].val)
            {
                stack.pop();
                continue;
            }
            add(i, 1);
            stack.pop();
        }
        stack.push(RMQ[i][0]);
    }
    stack.init();
    for (int i = n; i >= 1; i--)
    {
        while (stack.length() > 0 && stack.top().val <= RMQ[i][0].val)
        {
            if (stack.top().val == RMQ[i][0].val)
            {
                stack.pop();
                continue;
            }
            add(n - i + 1, 0);
            stack.pop();
        }
        stack.push(RMQ[i][0]);
    }
}
inline int work()
{
    ans = R - L;
    ans += query(n - L + 1, 0) - query(n - get(L, R) + 1, 0);
    ans += query(R, 1) - query(get(L, R), 1);
    return ans;
}
signed main()
{
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &RMQ[i][0].val);
        RMQ[i][0].index = i;
    }
    init();
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld%lld", &L, &R);
        printf("%lld\n", work());
    }
}
/**************************************************************
    Problem: 1369
    User: 11912823
    Language: C++
    Result: 正确
    Time:320 ms
    Memory:123128 kb
****************************************************************/
