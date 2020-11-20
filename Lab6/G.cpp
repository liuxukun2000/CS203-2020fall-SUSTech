#include <iostream>
#include <cmath>
#include <cstring>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#define HASH 131
#define int unsigned long long
using namespace std;
map<int, int> Pre;
string str[110000];
int n, Next[1100000], subpre[1100000],tmp, val, ans, l,mod=998244353;
inline void getHash(string &s, int pos)
{
    tmp = 1;
    val = 0;
    for ( signed i = s.size() - 1; i >= 0; i--)
    {
        val += s[i] * tmp;
        tmp *= 131;
        Pre[val] += pos;
    }
}
inline void getNext(string &s)
{
    Next[0] = -1;
    int i = 0, j = -1,tt=s.size();
    while (i < tt)
    {
        if (j == -1 || s[j] == s[i])
        {
            j++;
            i++;
            Next[i] = j;
        }
        else
        {
            j = Next[j];
        }
    }
}
inline void init(int pos)
{
    val = 0;
    for ( signed j = 0; j < l; ++j)
    {
        val = val * HASH + str[pos][j];
        subpre[j + 1] = Pre[val];
    }
}
inline void change()
{
    for ( signed j = 1; j <= l; ++j)
    {
        subpre[Next[j]] -= subpre[j];
    }
}
signed main()
{
    //freopen("in.in","r",stdin);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for ( signed i = 0; i < n; ++i)
    {
        cin >> str[i];
        //cout<<str[i]<<endl;
        getHash(str[i], i + 1);
    }
    for ( signed i = 0; i < n; ++i)
    {
        l = str[i].size();
        init(i);
        getNext(str[i]);
        change();
        for ( signed j = 1; j <= l; ++j)
        {
            ans += (j * subpre[j] % mod) * (i + 1) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}
/**************************************************************
    Problem: 1339
    User: 11912823
    Language: C++
    Result: 正确
    Time:1640 ms
    Memory:149052 kb
****************************************************************/
