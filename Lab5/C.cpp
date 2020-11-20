#include <iostream>
#include <cstring>
#include <cstdio>
#include <list>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,q,op,u,v,w,x;
class deque
{
public:
    list<int> val;
    inline void push_back(int x)
    {
        val.push_back(x);
    }
    inline void push_front(int x)
    {
        val.push_front(x);
    }
    inline int front()
    {
        if(val.size()==0)
        {
            return -1;
        }
        int ans= val.front();
        val.pop_front();
        return ans;
    }
    inline int end()
    {
        if(val.size()==0)
        {
            return -1;
        }
        int ans= val.back();
        val.pop_back();
        return ans;
    }
    inline void Reverse()
    {
        //cout<<val.front()<<" "<<val.back()<<endl;
 
        std::reverse(val.begin(),val.end());
        //cout<<val.front()<<" "<<val.back()<<endl;
    }
    inline void connect(deque &b)
    {
        val.splice(val.end(),b.val);
        //cout<<val.front()<<" "<<val.back()<<endl;
    }
}a[510000];
void work()
{
    int w, u, x;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%d", &u, &w, &x);
            w ? a[u].push_back(x):a[u].push_front(x);
        }
        else if (op == 2)
        {
            scanf("%d%d", &u, &w);
            printf("%d\n",w ? a[u].end():a[u].front());
        }
        else
        {
            scanf("%d%d%d", &u, &v, &w);
            if(a[v].val.size()==0) continue;
            if(w)
            {
                a[v].Reverse();
            }
            a[u].connect(a[v]);
        }
    }
}
int main()
{
    while(scanf("%d%d", &n, &q)==2)
    {
        for(int i=1;i<=n;i++)
        {
            a[i].val.clear();
        }
        work();
    }
}
/*
233 /23
2333 23333
 
->233 /23 23333 2333
*/
/**************************************************************
    Problem: 1342
    User: 11912823
    Language: C++
    Result: 正确
    Time:152 ms
    Memory:14904 kb
****************************************************************/
