#include <iostream>
#include <cstdlib>
#include<cstring>
#include <cstdio>
#include <vector>
#include<cmath>
using namespace std;
int T;
long long n,one=1,tmp,ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        tmp=2;
        ans=1;
        while(tmp-1<n)
        {
            tmp<<=one;
            ans++;
        }
        printf("%lld\n",ans);
    }
}
/**************************************************************
    Problem: 1384
    User: 11912823
    Language: C++
    Result: 正确
    Time:128 ms
    Memory:2024 kb
****************************************************************/
