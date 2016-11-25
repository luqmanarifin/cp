#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

#define INF 2e9 + 1e8
#define MAXN 2010

struct Edge
{
    int t, c, w, r;
    Edge(int _t, int _c, int _w, int _r): t(_t), c(_c), w(_w), r(_r) {};
};


int pot[MAXN+5], prv[MAXN+5], dist[MAXN+5], vis[MAXN+5];
vector<Edge> edge[MAXN+5];

pair<int, int> mcmf(int n, int s, int t)
{
    fill(pot, pot+n, 0);
    for (int it = 0; it < n; it++) {
      for (int i = 0; i < n; i++) {
        for (auto e : edge[i]) {
          int u = e.t;
          if (e.c == 0) continue;
          int ndist = dist[i] + e.w + pot[i]-pot[u];
          if (ndist < dist[u]) {
            dist[u] = ndist;
            prv[u] = e.r;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) pot[i] = dist[i];
    int mf = 0, mc = 0;
    while (true) {
        priority_queue<pair<int, int> > pq;
        fill(dist, dist+n, INF);
        fill(vis, vis+n, 0);
        pq.push(make_pair(0, s));
        dist[s] = 0;
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int v = top.second, c = -top.first;
            if (vis[v]) continue;
            vis[v] = 1;
            for (int i = 0; i < edge[v].size(); ++i) {
                Edge &e = edge[v][i];
                int u = e.t;
                if (e.c == 0) continue;
                int ndist = dist[v] + e.w + pot[v]-pot[u];
                if (ndist < dist[u]) {
                    dist[u] = ndist;
                    prv[u] = e.r;
                    pq.push(make_pair(-ndist, u));
                }
            }
        }
        int v = t;
        if (dist[t] == INF) break;
        int flow = INF;
        for (int i = 0; i < n; ++i) pot[i] += dist[i];
        while (v != s) {
            Edge &r = edge[v][prv[v]], &e = edge[r.t][r.r];
            flow = min(flow, e.c);
            v = r.t;
        }
        mf += flow;
        v = t;
        while (v != s) {
            Edge &r = edge[v][prv[v]], &e = edge[r.t][r.r];
            e.c -= flow;
            r.c += flow;
            mc += e.w * flow;
            v = r.t;
        }
    }
    return make_pair(mf, mc);
}            

void addEdge(int from, int to, int cap, int cost) {
  Edge u(to, cap, cost, edge[from].size());
  Edge v(from, 0, -cost, edge[to].size());
  edge[from].push_back(u);
  edge[to].push_back(v);
}

int p[N], u[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    int v, w;
    scanf("%d.%d", &v, &w);
    p[i] = v * 1000000 + w * 1000;
  }
  for (int i = 1; i <= n; i++) {
    int v, w;
    scanf("%d.%d", &v, &w);
    u[i] = v * 1000000 + w * 1000;
  }
  addEdge(0, n + 1, a, 0);
  addEdge(0, n + 2, b, 0);
  for (int i = 1; i <= n; i++) {
    addEdge(n + 1, i, 1, p[i]);
    addEdge(n + 2, i, 1, u[i]);
    addEdge(i, n + 3, 1, 0);
    addEdge(i, n + 3, 1, (int) (1LL * p[i] * u[i] / 1000000));
  }
  int ans = -mcmf(n + 4, 0, n + 3).second;
  printf("%d.%.6d\n", ans / 1000000, ans % 1000000);
  return 0;
}
