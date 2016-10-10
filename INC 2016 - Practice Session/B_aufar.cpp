#include <bits/stdc++.h>

using namespace std;

#define INF 100000
#define MAXN 100

int vis[MAXN+5], dist[MAXN+5];
vector<int> edge[MAXN+5], cost[MAXN+5];

int main()
{
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {

        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
          edge[i].clear();
          cost[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int c, d;
            scanf("%d%d", &c, &d);
            edge[c].push_back(d);
            cost[c].push_back(0);
            edge[d].push_back(c);
            cost[d].push_back(1);
        }
        printf("Case #%d:\n", itc);
        int q;
        scanf("%d", &q);
        while (q--) {
            int a, b;
            scanf("%d%d", &a, &b);
            priority_queue<pair<int,int> > PQ;
            PQ.push(make_pair(0, a));
            fill(vis, vis+n+1, false);
            fill(dist, dist+n+1, INF);
            dist[a] = 0;
            while (!PQ.empty()) {
                pair<int,int> top = PQ.top();
                int d = -top.first;
                int v = top.second;
                PQ.pop();
                if(vis[v]) continue;
                vis[v] = true;
                dist[v] = d;
                for (int i = 0; i < edge[v].size(); ++i) {
                    int u = edge[v][i];
                    int c = cost[v][i];
                    if (!vis[u]) PQ.push(make_pair(-(d+c), u));
                }
            }
            if (vis[b]) printf("%d\n", dist[b]);
            else puts("-1");
        }
    }
    return 0;
}
