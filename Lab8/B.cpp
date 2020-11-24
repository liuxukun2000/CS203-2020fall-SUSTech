#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include<cmath>
using namespace std;
struct Node
{
    int val,pos;
    bool operator<(const Node &b)
    {
        return val<b.val;
    }
    bool operator>(const Node &b)
    {
        return val>b.val;
    }
}a[1000100];
int  size, n, op, T;
void judge(int p)
{
    int m = p;
    if (a[p] > a[p << 1] && (p << 1) <= size)
    {
        m = p << 1;
    }
    if (a[m] > a[(p << 1) + 1] && (p << 1) <= size - 1)
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
void work()
{
    Node x;
    a[0].val=1e9+10;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x.val);
        x.pos=i;
        insert(x);
    }
    scanf("%d",&op);
    for(int i=1;i<=size;i++)
    {
        if(a[i].pos==op)
        {
            op=i;
            break;
        }
    }
    int ans1,ans2;
    ans1=log10(op)/log10(2);
    ans2=op-(1<<ans1);
    printf("%d %d\n",ans1+1,ans2+1);
 
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        size = 0;
        work();
    }
}
/**************************************************************
    Problem: 1385
    User: 11912823
    Language: C++
    Result: 正确
    Time:160 ms
    Memory:9932 kb
****************************************************************/
