#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
struct Node
{
    int son[2], isfill, v;
    void clear()
    {
        v = 0;
        son[0] = 0;
        son[1] = 0;
        isfill = 0;
    }
} nod[110000];
bool ans1, ans2;
int T, n, root, tre[110000];
bool build()
{
    tre[1] = root;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        if (tre[i] == 0)
            return false;
        tmp = tre[i];
        if (nod[tmp].son[0] != 0)
        {
            if (i * 2 > n)
            {
                return false;
            }
 
            tre[i * 2] = nod[tmp].son[0];
        }
        if (nod[tmp].son[1] != 0)
        {
            if (i * 2 + 1 > n)
            {
                return false;
            }
            tre[i * 2 + 1] = nod[tmp].son[1];
        }
    }
    return true;
}
inline long long getroot()
{
    return ((long long)n) * (1 + n) / 2;
}
inline bool work()
{
    bool t1 = true, t2;
    int tmp, son;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &tmp, &son);
        if (i == 1)
        {
            t2 = (nod[tmp].v <= nod[son].v);
        }
        else if (t2 != (nod[tmp].v <= nod[son].v))
        {
            t1 = false;
        }
        if (nod[tmp].isfill > 1)
        {
            t1 = false;
            continue;
        }
        if (!t1)
            continue;
        nod[tmp].son[nod[tmp].isfill++] = son;
        root -= son;
    }
    return t1;
}
int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d", &n);
        root = getroot();
        for (int i = 0; i <= n; i++)
        {
            nod[i].clear();
            tre[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &nod[i].v);
        }
        ans1 = work();
        ans2 = build();
        (ans1 && ans2) ? printf("Case #%d: YES\n", t) : printf("Case #%d: NO\n", t);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1282
    User: 11912823
    Language: C++
    Result: 正确
    Time:304 ms
    Memory:4172 kb
****************************************************************/
