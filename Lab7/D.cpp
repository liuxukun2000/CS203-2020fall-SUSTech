#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
int T, n, pre[1300], in[1300];
inline int find(int root, int f, int e)
{
    for (int i = f; i <= e; ++i)
    {
        if (in[i] == root)
        {
            return i;
        }  
    }
}
void built(int pl, int pr, int il, int ir)
{
    int root, pos;
    if (pr == pl)
    {
        printf("%d ", pre[pl]);
        return;
    }
    root = pre[pl];
    pos = find(root, il, ir);
    if (pos - il)
    {
        built(pl + 1, pl + pos - il, il, pos - 1);
    }
    if (ir - pos)
    {
        built(pr - ir + pos + 1, pr, pos + 1, ir);
    }
    printf("%d ", root);
}
inline void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &in[i]);
    }
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        init();
        built(0, n - 1, 0, n - 1);
        puts("");
    }
}
/**************************************************************
    Problem: 1279
    User: 11912823
    Language: C++
    Result: 正确
    Time:0 ms
    Memory:2032 kb
****************************************************************/
