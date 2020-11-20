
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
char a[510000], b[510000], c[510000], Hash[299], op;
int l,L, Next[510000];
inline void get_next(char *tmp, int len)
{
    Next[0] = -1;
    for (int i = 1, j; i < len; ++i)
    {
        j = Next[i - 1];
        while (j >= 0 && tmp[j + 1] != tmp[i])
        {
            j = Next[j];
        }
        tmp[j + 1] == tmp[i] ? Next[i] = j + 1 : Next[i] = -1;
    }
}
inline int kmp(char *s, char *pat)
{
    int l1 = strlen(s), l2 = strlen(pat);
    get_next(pat, l2);
    int pos1 = 0, pos2 = 0;
    while (pos1 < l1 && pos2 < l2)
    {
        if (pat[pos2] == s[pos1])
        {
            ++pos1;
            ++pos2;
        }
        else if (pos2 > 0)
        {
            pos2 = Next[pos2 - 1] + 1;
        }
        else
        {
            ++pos1;
        }
    }
    return pos2;
}
int main()
{
    //freopen("in.in","r",stdin);
    for (int i = 0; i < 26; ++i)
    {
        scanf(" %c", &op);
        Hash[op] = 'a' + i;
    }
    scanf("%s", a);
    L = strlen(a);
    for (int i = 0; i < L; ++i)
    {
        b[i] = Hash[a[i]];
    }
    l = L / 2;
    if (L & 1)
    {
        ++l;
    }
    int cnt = 0;
    for (int i = l; i < L;++i)
    {
        c[cnt++] = a[i];
    }
    printf("%d\n", L - kmp(c, b));
}
/**************************************************************
    Problem: 1375
    User: 11912823
    Language: C++
    Result: 正确
    Time:8 ms
    Memory:5508 kb
****************************************************************/
