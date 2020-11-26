#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include<vector>
#define int long long
using namespace std;
int val[110000],T,n,f[110000],ans;
struct Node
{
    int val,to;
    Node (int x,int y)
    {
        val=x;
        to=y;
    }
    bool operator<(const Node&b)
    {
        if(val==b.val) return to<b.to;
        else return val<b.val;
    }
};
vector<Node> son[110000];
int getDeep(int root)
{
    if (!son[root].size())
        return 1;
    int l=son[root].size();
    for (int i = 0; i < l; i++)
    {
        son[root][i].val = getDeep(son[root][i].to);
    }
    sort(son[root].begin(), son[root].end());
    return son[root].back().val + 1;
}
int dfs(int root, int deep, int v)
{
    val[root] = v;
    if (!son[root].size())
        return 1;
    int tmp = v,l=son[root].size();
    for (int i = 0; i < l; i++)
    {
        tmp = min(deep, dfs(son[root][i].to, deep + 1, tmp + 1));
    }
    return tmp + 1;
}
signed main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            son[i].clear();
        }   
        for (int i = 2; i <= n; i++)
        {
            scanf("%lld", &f[i]);
            son[f[i]].push_back(Node(0,i));
        }
        getDeep(1);
        dfs(1, 0, 0);
        ans=0;
        for (int i = 1; i <= n; i++)
        {
            if (!son[i].size())
            {
                ans += val[i];
            }
        }   
        printf("%lld\n", ans);
    }
}
