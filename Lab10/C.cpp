#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include<cmath>
using namespace std;
struct Node
{
    int x, y;
    double t,v;
    Node(int x, int y, double v, double t)
    {
        this->x = x;
        this->y = y;
        this->v = v;
        this->t = t;
    }
    bool operator<(const Node &b) const
    {
        if (t != b.t)
            return t > b.t;
        else
            return v < b.v;
    }
};
int n, m, u, v, h[310][310];
double t[310][310];
bool vis[310][310];
priority_queue<Node> Q;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &h[i][j]);
            t[i][j]=0x3f3f3f3f;
        }
    }
    memset(vis, 0, sizeof(vis));
    t[1][1] = 0;
    Node tmp(1, 1, 1, 0);
    Q.push(tmp);
    while (!Q.empty())
    {
        Node tmp = Q.top();
        Q.pop();
        if (vis[tmp.x][tmp.y])
            continue;
        vis[tmp.x][tmp.y] = true;
        for (int i = -1; i <= 1; i += 1)
        {
            for (int j = -1; j <= 1; j += 1)
            {
                if (i*j!=0||tmp.x + i < 1 || tmp.y + j < 1 || tmp.x + i > n || tmp.y + j > m)
                    continue;
                //cout<<t[tmp.x][tmp.y]<<endl;

                if (t[tmp.x][tmp.y] < 0x3f3f3f3f && tmp.t +double(1)/(double)tmp.v< t[tmp.x + i][tmp.y + j])
                {
                    t[tmp.x + i][tmp.y + j]=tmp.t +double(1)/(double)tmp.v;
                    Q.push(Node(tmp.x + i,tmp.y+j,tmp.v*pow(2,h[tmp.x][tmp.y]-h[tmp.x+i][tmp.y+j]),t[tmp.x + i][tmp.y + j]));
                    //cout<<tmp.v*pow(2,h[tmp.x][tmp.y]-h[tmp.x+i][tmp.y+j])<<endl;
                }
            }
        }
    }
    printf("%.2f\n",t[n][m]);
}