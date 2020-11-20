#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int t, n, top;
char stack[31000];
string s;
inline void push(char x)
{
    stack[top++] = x;
}
inline void pop()
{
    if (top ) top--;
}
char query()
{
    if (top > 0)
        return stack[top - 1];
    return 0;
}
inline bool judge()
{
    char tmp, topc;
    int L=s.size();
    for (int i = 0; i < L; ++i)
    {
        tmp=s[i];
        if (tmp == '(' || tmp == '[' || tmp == '{')
        {
            push(tmp);
            continue;
        }
        if (top == 0)
            return false;
        topc = query();
        if (abs(tmp - topc) > 3)
            return false;
        pop();
    }
    return top ? false:true;
}
 
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        top = 0;
        scanf("%d",&n);
        cin>>s;
        //cout<<s<<endl;
        if(n&1) 
        {
            puts("NO");
            continue;
        }
        judge() ? puts("YES"):puts("NO");
             
    }
}
 
/**************************************************************
    Problem: 1357
    User: 11912823
    Language: C++
    Result: 正确
    Time:4 ms
    Memory:2188 kb
****************************************************************/
