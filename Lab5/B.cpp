
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
58
59
60
61
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, queue[20000010], s, e, x;
char op;
inline int query()
{
    return queue[s];
}
 
inline void pop()
{
    if (e > s)
        ++s;
}
 
inline void push(int x)
{
    queue[e++] = x;
}
 
int main()
{
    scanf("%dd", &n);
    s = e = 0;
    for (int i = 0; i < n; ++i)
    {
        op = getchar();
        while (op < 'A' || op > 'Z')
            op = getchar();
        if (op == 'E')
        {
            scanf("%d", &x);
            push(x);
        }
        else if (op == 'D')
        {
            pop();
        }
        else
        {
            if (e > s)
                printf("%d\n", query());
        }
    }
    while (e > s)
    {
        printf("%d ", query());
        pop();
    }
}
 
/**************************************************************
    Problem: 1359
    User: 11912823
    Language: C++
    Result: 正确
    Time:592 ms
    Memory:80148 kb
****************************************************************/
