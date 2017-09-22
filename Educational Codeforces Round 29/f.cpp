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
  vector< vector< int > > adj;
  vector< int > par;
  vector< Edge > vEdge;
  vector< long long > dist;
  MCMF(int _n, int _s, int _t) : n(_n), adj(n), s(_s), t(_t) {
  }
  void addEdge(int from, int to, int cap, int cost) {
    adj[from].push_back(vEdge.size());
    adj[to].push_back(vEdge.size());
    vEdge.push_back(Edge(from, to, cap, 0, cost));
  }
  long long augment(int v, int minflow = inf) {
    if(v == s) {
      return minflow;
    }
    if(par[v] < 0) {
      return 0;
    }
    long long flow;
    Edge &e = vEdge[par[v]];
    if(v == e.from) {
      flow = augment(e.to, min(minflow, e.flow));
      e.flow -= flow;
    }
    else {
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
  pair< long long, long long > EdmondKarp() {
    long long maxflow = 0, mincost = 0;
    long long flow;
    while(flow = findingPath()) {
      maxflow += flow;
      mincost += flow * dist[t];
    }
    return make_pair(mincost, maxflow);
  }
};

const int N = 55;

set<int> s[N];
int to[N][N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      s[i].insert(j);
    }
  }

  for (int i = 0; i < q; i++) {
    int t, l, r, v;
    scanf("%d %d %d %d", &t, &l, &r, &v);
    if (t == 1) {
      for (int j = l; j <= r; j++) {
        for (int k = 1; k < v; k++) {
          s[j].erase(k);
        }
      }
    } else {
      for (int j = l; j <= r; j++) {
        for (int k = v + 1; k <= n; k++) {
          s[j].erase(k);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s[i].empty()) {
      puts("-1");
      return 0;
    }
  }
  int now = n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      now++;
      to[i][j] = now;
    }
  }
  MCMF mcmf(now + 2, 0, now + 1);
  for (int i = 1; i <= n; i++) {
    mcmf.addEdge(0, i, 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      mcmf.addEdge(to[i][j], now + 1, 1, j * 2 - 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto it : s[i]) {
      for (int k = 1; k <= n; k++) {
        mcmf.addEdge(i, to[it][k], 1, 0);
      }
    }
  }
  cout << mcmf.EdmondKarp().first << endl;
  return 0;
}