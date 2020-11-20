#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
int n,num;
struct node
{
    int val,cnt,time;
    bool operator<(const node &b)const
    {
        if(cnt==b.cnt)
        {
            return time<b.time;
        }
        else
        {
            return cnt<b.cnt;
        }
         
    }
}tmp,a[500100];
int Hash[500100];
priority_queue<node> q;
inline void push(int x)
{
    tmp.val=x;
    Hash[x]=Hash[x]+1;
    tmp.cnt=Hash[x];
    tmp.time=++num;
    q.push(tmp);
    a[num]=tmp;
}
inline int top()
{
    if(q.empty())
    {
        return -1;
    }
    tmp=q.top();
    Hash[tmp.val]=Hash[tmp.val]-1;
    q.pop();
    return tmp.val;
}
int main()
{
    char op[21];
    while(scanf("%s",op)==1)
    {
        if(op[0]=='p')
        {
            scanf("%d",&n);
            //cout<<"hh"<<n<<endl;
            push(n);
        }
        else if(op[0]=='e')
        {
            int x=top();
            if(x==-1)
            {
                puts("pa");
                continue;
            }
            printf("%d\n",x);
            //sort(a+1,a+num+1);
            /*for(int i=1;i<=num;i++)
            {
                cout<<a[i].val;
            }
            puts("");*/
        }
        else
        {
            return 0;
        }
         
    }
}
/*
p 5
p 1
p 4
p 1
e
p 1
p 4
e
e
e
e
e
e
n
 
p 1
p 1
p 2
p 2
e
p 2
e
p 3
e
e
e
e
e
n
*/
/**************************************************************
    Problem: 1336
    User: 11912823
    Language: C++
    Result: 正确
    Time:416 ms
    Memory:12236 kb
****************************************************************/
