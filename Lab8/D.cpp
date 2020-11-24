#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int a[1300], s, size, t, k;
inline int getDigits(int x)
{
    int sum = x;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
inline void insert1(int x)
{
    int pos = 1, s = 2;
    if (x <= a[1])
        return;
    while (s <= size)
    {
        if (s < size && a[s + 1] < a[s])
        {
            s++;
        }
        if (x < a[s])
        {
            break;
        }
        a[pos] = a[s];
        pos = s;
        s = pos << 1;
    }
    a[pos] = x;
}
inline void insert2(int x)
{
    int tmp = ++size;
    while (tmp != 1 && x < a[tmp >> 1])
    {
        a[tmp] = a[tmp >> 1];
        tmp >>= 1;
    }
    a[tmp] = x;
}
signed main()
{
    scanf("%lld%lld%lld", &t, &k, &s);
    t = t / 100 * 100;
    for (int i = 1; i <= t; i++)
    {
        size < k ? insert2(getDigits(i + s)) : insert1(getDigits(i + s));
        if ((i % 100) == 0)
        {
            s = a[1];
            printf("%lld ", s);
        }
    }
    puts("");
}
 
/**************************************************************
    Problem: 1285
    User: 11912823
    Language: C++
    Result: 正确
    Time:104 ms
    Memory:2032 kb
****************************************************************/
