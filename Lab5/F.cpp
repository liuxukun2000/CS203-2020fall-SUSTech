?
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
#include <iostream>
#include <cstring>
#include <cstdio>
#include <list>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define int long long
int a[5100000], n, k,ans=1,Max[5100000],Min[5100000],l1=1,r1=1,l2=1,r2=1,tmp;
signed main()
{
    scanf("%lld%lld", &k, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        while(l1<r1&&a[Max[r1-1]]<a[i])
        {
            r1--;
        }
        while(l2<r2&&a[Min[r2-1]]>a[i])
        {
            r2--;
        }
        Max[r1]=i;
        Min[r2]=i;
        r1++;
        r2++;
        while(l1<r1&&l2<r2&&a[Max[l1]]-a[Min[l2]]>k)
        {
            if(Max[l1]<Min[l2])
            {
                tmp=Max[l1];
                l1++;
            }
            else
            {
                tmp=Min[l2];
                l2++;
            }
        }
        if(l1<r1&&l2<r2) ans=max(ans,i-tmp);
    }
    printf("%lld\n",ans);
}
/*
3 9
5 1 3 5 8 6 6 9 10
*/
 
/**************************************************************
    Problem: 1376
    User: 11912823
    Language: C++
    Result: 正确
    Time:476 ms
    Memory:121556 kb
****************************************************************/
