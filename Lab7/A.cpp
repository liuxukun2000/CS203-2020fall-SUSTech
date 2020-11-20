#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define int long long
using namespace std;
int T, n, tmp;
inline int work(int n, int k)
{
    int ans, sum = 1, num = 1, p;
    for (int i = 0; sum < n; i++)
    {
        num *= k;
        sum += num;
    }
    p = sum - n;
    ans = num - p + p / k;
    return ans;
}
 
signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &tmp);
        printf("%lld\n", work(n, tmp));
    }
}
 
/**************************************************************
    Problem: 1277
    User: 11912823
    Language: C++
    Result: 正确
    Time:0 ms
    Memory:2024 kb
****************************************************************/
