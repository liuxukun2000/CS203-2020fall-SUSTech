#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
using namespace std;
int n, len[1002], l = 3001, ans1, ans2;
char s[1002][1002];
bool op1 = 0, op2 = 0;
signed main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s[i] + 1);
        len[i] = strlen(s[i] + 1);
        l = min(l, len[i]);
    }
    if (n == 1)
    {
        printf("%d\n", l * l);
        return 0;
    }
    for (int j = 1; j <= l; ++j)
    {
        if (!(op1&op2))
        {
            for (int i = 2; i <= n; ++i)
            {
                if(op1&op2) break;
                if (s[i][j] != s[i - 1][j])
                {
                    op1 = 1;
                }
                if (s[i][len[i] - j + 1] != s[i - 1][len[i - 1] - j + 1])
                {
                    op2 = 1;
                }
                if (i == n)
                {
                    if(!op1) ans1++;
                    if(!op2) ans2++;
                }
            }
        }
        else break;
    }
    printf("%d\n", ans1 * ans2);
}
/**************************************************************
    Problem: 1338
    User: 11912823
    Language: C++
    Result: 正确
    Time:8 ms
    Memory:3008 kb
****************************************************************/
