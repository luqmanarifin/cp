#include <bits/stdc++.h>

using namespace std;

const int maxnodes = 2017, inf = 2e9 + 9;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

struct Edge {
  int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s, int t, int cap, int cost) {
  Edge a = {t, 0, cap, cost, graph[t].size()};
  Edge b = {s, 0, 0, -cost, graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}

typedef long long ll;

pair<int, int> minCostFlow(int s, int t, int maxf) {
  int flow = 0;
  int flowCost = 0;
  while (flow < maxf) {
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(s);
    fill(prio, prio+nodes, inf);
    prio[s] = 0;
    curflow[s] = inf;
    while (!q.empty()) {
      ll cur = q.top();
      q.pop();
      int d = cur >> 32;
      int u = cur;
      if (d != prio[u]) continue;
      for (int i = 0; i < (int)graph[u].size(); i++) {
        Edge & e = graph[u][i];
        int v = e.to;
        if (e.cap <= e.f) continue;
        int nprio = prio[u] + e.cost;
        if (prio[v] > nprio) {
          prio[v] = nprio;
          q.push(((ll) nprio << 32) + v);
          prevnode[v] = u;
          prevedge[v] = i;
          curflow[v] = min(curflow[u], e.cap - e.f);
        }
      }
    }
    if (prio[t] == inf) break;
    int df = min(curflow[t], maxf - flow);
    flow += df;
    for (int v = t; v != s; v = prevnode[v]) {
      Edge & e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += df * e.cost;
    }
  }
  return make_pair(flow, flowCost);
}
int to[maxnodes];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int st = 2 * n, en = st + 1;
    nodes = en + 1;
    for (int i = 0; i < nodes; i++) {
      graph[i].clear();
    }
    for (int i = 0; i < n; i++) {
      int cost;
      scanf("%d", &cost);
      addEdge(i << 1, (i << 1) + 1, 1, cost);
      addEdge(st, i << 1, 1, 0);
      addEdge((i << 1) + 1, en, 1, 0);
    }
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      u--; v--;
      addEdge(u << 1, (v << 1) + 1, 1, w);
    }
    pair<int, int> res = minCostFlow(st, en, nodes);
    vector<vector<int> > cycles;
    for (int i = 0; i < n; i++) {
      for (Edge & e : graph[i << 1]) {
        if ((e.to & 1) == 0) continue;
        int nx = e.to/2;
        if (nx >= n) continue;
        if (e.f <= 0) continue;
        to[i] = nx;
      }
    }
    for (int i = 0; i < n; i++) {
      int now = i;
      vector<int> cur;
      while (now != -1) {
        int nx = to[now];
        to[now] = -1;
        now = nx;
        if (now != -1)
          cur.push_back(now);
      }
      if (cur.size() > 1)
        cycles.push_back(cur);
    }
    printf("%d %d\n", res.second, cycles.size());
    for (auto c : cycles) {
      printf("%d", c.size());
      for (int v : c)
        printf(" %d", v+1);
      printf("\n");
    }
  }

  return 0;
}