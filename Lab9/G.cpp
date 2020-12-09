#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
int T,n,m,u,v,a[110000],b[110000],ans,mod=1e9+7,f[110000];
vector<int> to[110000];
inline int work(int x)
{
    if(f[x]) return f[x];
    int sum=0,l=to[x].size(),y,tmp;
    for(int i=0;i<l;i++)
    {
        y=to[x][i];
        tmp=work(y)%mod;
        if(to[y].size())
        {
            sum+=tmp;
            sum%=mod;
        }
        sum+=b[y];
        sum%=mod;
    }
    return f[x]=sum;
}
signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        ans=0;
        memset(f,0,sizeof(f));
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i],&b[i]);
            a[i]%=mod;
            b[i]%=mod;
            to[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%lld%lld",&u,&v);
            to[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
        {
            ans=(ans+(work(i)*a[i])%mod)%mod;
        }
        printf("%lld\n",ans);
    }
}