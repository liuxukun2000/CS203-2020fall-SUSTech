#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define int long long
using namespace std; 
int t, n, x, y, sum,tmp;
priority_queue<int, std::vector<int>, std::greater<int> > q;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld",&tmp);
            q.push(tmp);
        }
        sum=0;
        while(true)
        {
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();
            x+=y;
            sum += x;
            if(q.empty()) break;
            q.push(x);
        }
        printf("%lld\n",sum);
    }
}
  
/**************************************************************
    Problem: 1280
    User: 11912823
    Language: C++
    Result: 正确
    Time:24 ms
    Memory:2032 kb
****************************************************************/
