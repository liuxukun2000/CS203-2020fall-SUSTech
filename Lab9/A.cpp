#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
int T, n, m, u, v;
int Map[3000][3000];
inline void init()
{
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        Map[u][v]++;
    }
}
inline void out()
{
    for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ", Map[i][j]);
            }
            puts("");
        }
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(Map, 0, sizeof(Map));
        scanf("%d%d", &n, &m);
        init();
        out();
         
    }
}
