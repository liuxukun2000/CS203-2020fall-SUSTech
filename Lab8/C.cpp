#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int size, n, op, T, l, r, pos, ans,tim;
struct Node
{
    int val, pos;
    bool operator<(const Node &b)
    {
        return val < b.val;
    }
    bool operator>(const Node &b)
    {
        return val > b.val;
    }
} a[100010], b[110000];
void judge(int p)
{
    int m = p;
    if (a[p] < a[p << 1] && (p << 1) <= size)
    {
        m = p << 1;
    }
    if (a[m] < a[(p << 1) + 1] && (p << 1) <= size - 1)
    {
        m = (p << 1) + 1;
    }
    if (p != m)
    {
        swap(a[p], a[m]);
        judge(m);
    }
}
void insert(Node x)
{
    size++;
    a[size] = x;
    int p = size;
    while (p >= 1 && a[p >> 1] < a[p])
    {
        swap(a[p], a[p >> 1]);
        p = p >> 1;
    }
}
void del()
{
    swap(a[1], a[size]);
    size--;
    judge(1);
}
inline Node getMax()
{
    Node tmp;
    tmp.val = 0;
    if (size)
    {
        tmp = a[1];
        del();
    }
    return tmp;
}
inline bool cmp(Node a,Node b)
{
    return a.pos>b.pos;
}
signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        size = 0;
        tim=0;
        a[0].val = 1e15 + 7;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &b[i].val);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &b[i].pos);
            tim=max(tim,b[i].pos);
        }
        sort(b+1,b+n+1,cmp);
        pos = 1;
        ans = 0;
        for (int i = tim; i>=1; i--)
        {
            while(pos<=n&&b[pos].pos>=i)
            {
                insert(b[pos]);
                pos++;
            }
            ans+=(getMax().val);
        }
        printf("%lld\n", ans);
    }
}
/**************************************************************
    Problem: 1387
    User: 11912823
    Language: C++
    Result: 正确
    Time:504 ms
    Memory:5308 kb
****************************************************************/
