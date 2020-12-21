#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define int long long
using namespace std;
struct Edge
{
	int v, dis;
	Edge(){}
	Edge(int vv,int diss)
	{
		v=vv;
		dis=diss;
	}
};
vector<Edge> to[51000];
vector<int> pos[51000];
bool vis[11][51000];
int ans = 0x3f3f3f3f3f, dist[11][51000], n, m, p, k, s, t, u, v, w, dis;
struct Node
{
	int u, v, d;
	Node()
	{}
	Node(int uu,int vv,int dd)
	{
		u=uu;
		v=vv;
		d=dd;
	}
	bool operator<(const Node &b) const
	{
		return d > b.d;
	}
};
priority_queue<Node> q;
signed main()
{
	scanf("%lld%lld%lld%lld", &n, &m, &p, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld%lld%lld", &u, &v, &w);
		to[u].push_back(Edge(v,w));
	}
	for (int i = 1; i <= p; i++)
	{
		scanf("%lld%lld", &u, &v);
		pos[u].push_back(v);
	}
	scanf("%lld%lld", &s, &t);
	for (int i = 0; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = 0x3f3f3f3f3f;
		}
	}
	dist[0][s] = 0;
	Node tmp;
	q.push(Node(0,s,0));
	while (!q.empty())
	{
		tmp = q.top();
		q.pop();
		u = tmp.v;
		if (vis[tmp.u][u])
		{
			continue;
		}
		vis[tmp.u][u] = true;
		int l = to[u].size();
		for (int i = 0; i < l; i++)
		{
			v = to[u][i].v;
			dis = to[u][i].dis;
			if (!vis[tmp.u][v] && dist[tmp.u][v] > dist[tmp.u][u] + dis)
			{
				dist[tmp.u][v] = dist[tmp.u][u] + dis;
				q.push(Node(tmp.u,v,dist[tmp.u][v]));
			}
		}
		if (tmp.u < k)
		{
			l = pos[u].size();
			for (int i = 0; i < l; i++)
			{
				v = pos[u][i];
				if (!vis[tmp.u + 1][v] && dist[tmp.u + 1][v] > dist[tmp.u][u])
				{
					dist[tmp.u + 1][v] = dist[tmp.u][u];
					q.push(Node(tmp.u + 1,v,dist[tmp.u + 1][v]));
				}
			}
		}
	}
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dist[i][t]);
	}
	printf("%lld\n", ans);
}