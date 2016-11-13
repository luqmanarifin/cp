#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8;

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int from, int to, int cap, int flow, int cost) :
    from(from), to(to), cap(cap), flow(flow), cost(cost) {}
  
};

struct MCMF {
  int n, s, t;
  vector<vector<int>> adj;
  vector<int> par;
  vector<Edge> vEdge;
  vector<long long> dist;

  MCMF(int _n, int _s, int _t) : n(_n), adj(n), s(_s), t(_t) {
  }

  void addEdge(int from, int to, int cap, int cost) {
    adj[from].push_back(vEdge.size());
    adj[to].push_back(vEdge.size());
    vEdge.push_back(Edge(from, to, cap, 0, cost));
  }

  long long augment(int v, int minflow = inf) {
    if (v == s) return minflow;
    if (par[v] < 0) return 0;
    long long flow;
    Edge& e = vEdge[par[v]];
    if (v == e.from) {
      flow = augment(e.to, min(minflow, e.flow));
      e.flow -= flow;
    } else {
      flow = augment(e.from, min(minflow, e.cap - e.flow));
      e.flow += flow;
    }
    return flow;
  }

  long long findingPath() {
    //dijkstra
    set< pair< long long , int > > st;
    dist.assign(n, inf);
    par.assign(n, -1);
    dist[s] = 0;
    st.insert(make_pair(dist[s], s));
    while(!st.empty()) {
      set< pair< long long, int > >::iterator begin = st.begin();
      int v = begin->second;
      st.erase(begin);
      for(int i = 0; i<adj[v].size(); i++) {
        Edge &e = vEdge[adj[v][i]];
        if(e.from == v) {
          if(e.cap > e.flow && dist[e.to] > dist[v] + e.cost) {
            st.erase(make_pair(dist[e.to], e.to));
            dist[e.to] = dist[v] + e.cost;
            st.insert(make_pair(dist[e.to], e.to));
            par[e.to] = adj[v][i];
          }
        }
        else {
          if(e.flow > 0 && dist[e.from] > dist[v] - e.cost) {
            st.erase(make_pair(dist[e.from], e.from));
            dist[e.from] = dist[v] - e.cost;
            st.insert(make_pair(dist[e.from], e.from));
            par[e.from] = adj[v][i];
          }
        }
      }
    }
    return augment(t, inf);
  }

  pair<int, int> EdmondKarp() {
    long long maxflow = 0, mincost = 0;
    long long flow;
    while (flow = findingPath()) {
      maxflow += flow;
      mincost += flow * dist[t];
    }
    return make_pair(mincost, maxflow);
  }

};

vector<int> can[505];
int n, m, rust, t, k;
int done[505];

int main() {
  freopen("contest.in", "r", stdin);
  freopen("contest.out", "w", stdout);
  scanf("%d %d %d %d %d", &n, &m, &rust, &t, &k);
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    can[u].push_back(v);
  }
  MCMF mcmf(n + m + 2, 0, n + m + 1);
  for (int i = 0; i < n; i++) {
    int pol = min(t / rust, (int) can[i].size());
    for (int j = 1; j <= pol; j++) {
      mcmf.addEdge(0, i + 1, 1, j);
    }
    for (int it : can[i]) {
      mcmf.addEdge(i + 1, n + 1 + it, 1, 0);
    }
  }
  for (int i = 0; i < m; i++) {
    mcmf.addEdge(n + 1 + i, n + m + 1, 1, 0);
  }
  pair<int, int> ret = mcmf.EdmondKarp();
  printf("%d %lld\n", ret.second, 1LL * ret.first * rust);
  for (Edge it : mcmf.vEdge) {
    if (it.from <= n && it.to > n && it.flow == 1) {
      printf("%d %d %d\n", it.from, it.to - n, done[it.from] * rust);
      done[it.from]++;
    }
  }

  return 0;
}