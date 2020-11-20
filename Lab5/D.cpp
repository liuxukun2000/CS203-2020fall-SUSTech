#include <iostream>
#include <cstring>
#include <cstdio>
#include <list>
#include<algorithm>
#include<cstdlib>
using namespace std;
int T,n,x,m;
struct node
{
    int val,pos;
}tmp;
class Stack
{
public:
    int top=0;
    node stack[510000];
    Stack()
    {
        top=0;
    }
    inline void push(node x)
    {
        stack[++top]=x;
    }
    inline node Top()
    {
        return stack[top];
    }
    inline void pop()
    {
        if(top) top--;
    }
    inline bool empty()
    {
        if(top) return false;
        return true;
    }
    inline void clear()
    {
        top=0;
    }
};
int ans[510000];
int main()
{
    scanf("%d",&T);
    Stack a;
    while(T--)
    {
        memset(ans,-1,sizeof(ans));
        while(!a.empty())
        {
            a.pop();
        }
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tmp.val);
            tmp.pos=i;
            while(a.empty()==false&&a.Top().val<tmp.val)
            {
                ans[a.Top().pos]=i-a.Top().pos;
                a.pop();
            }
            a.push(tmp);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x);
            printf("%d\n",ans[x]);
        }
    }
}
/*
1
6
3 2 6 1 1 2
6
3 4 2 1 6 5
*/
 
/**************************************************************
    Problem: 1337
    User: 11912823
    Language: C++
    Result: 正确
    Time:776 ms
    Memory:7880 kb
****************************************************************/
