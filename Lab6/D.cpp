#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int T, Next[210000], len, tmp, sub;
char s[210000];
inline void getnext()
{
    int j=0;
    for (int i = 1; i < len; ++i)
    {
        while (j && s[i] != s[j])
        {
            j = Next[j - 1];
        }
        if (s[i] == s[j])
        {
            ++j;
        }
        Next[i] = j;
    }
}
  
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        len = strlen(s);
        getnext();
        if (Next[len - 1] == 0)
        {
            printf("%d\n", len);
            continue;
        }
        tmp = len - Next[len - 1];
        sub = ceil((double)len / tmp);
        printf("%d\n", tmp * sub - len);
    }
}
/**************************************************************
    Problem: 1373
    User: 11912823
    Language: C++
    Result: 正确
    Time:64 ms
    Memory:3048 kb
****************************************************************/
