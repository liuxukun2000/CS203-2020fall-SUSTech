
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define int long long
using namespace std;
char s1[110000], s2[110000];
int l1, l2, mod = 31452060107;
int Map[110000];
inline int Pow(int a,int b)
{
    int ans=1,tmp=a;
    while(b)
    {
        if(b&1)
        {
            ans*=tmp;
            ans%=mod;
        }
        tmp*=tmp;
        tmp%=mod;
        b>>=1;
    }
    return ans;
}
inline bool check(int w)
{
    int pre=1,hashans=0,num=0;
    for (int i = 0; i < w; ++i)
    {
        pre *= 119;
        hashans = hashans * 119 + s1[i];
    }
    Map[0]= hashans;
    for (int i = w; i < l1; ++i)
    {
        hashans = hashans * 119 + s1[i] - pre * s1[i - w];
        Map[++num]= hashans;
    }
    hashans = 0;
    sort(Map, Map+num+1);
    for (int i = 0; i < w; ++i)
    {
        hashans = hashans * 119 + s2[i];
    }
          
    if (binary_search(Map,Map+num+1, hashans))
    {
        return true;
    }
          
    for (int i = w; i < l2; ++i)
    {
        hashans = hashans * 119 + s2[i] - pre * s2[i - w];
        if (binary_search(Map,Map+num+1, hashans))
        {
            return true;
        }
    }
    return false;
}
  
signed main()
{
    //printf("%lld\n",Pow(2,3));
    scanf("%s%s", s1, s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    if (l1 > l2)
    {
        swap(s1, s2);
    }
    int l = 0, r = l1, mid;
    while (l < r)
    {
        mid = (l + r)>>1;
        if (!check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (r == l1 && check(r))
    {
        printf("%lld\n", r);
    }
    else
    {
        printf("%lld\n", r - 1);
    }
}
/**************************************************************
    Problem: 1374
    User: 11912823
    Language: C++
    Result: 正确
    Time:168 ms
    Memory:3096 kb
****************************************************************/
