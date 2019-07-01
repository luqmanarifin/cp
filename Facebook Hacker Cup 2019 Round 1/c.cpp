#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
 
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
    Edge &e = G[x][i];
    if (!dad[e.to] && e.cap - e.flow > 0) {
      dad[e.to] = &G[x][i];
      Q[tail++] = e.to;
    }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    if (!e) { amt = 0; break; }
    amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    e->flow += amt;
    G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

set<int> s;

bool neighbor(int x, int y) {
  if (x == y) return 0;
  if (x > y) swap(x, y);
  assert(s.size() >= 2);
  auto it = s.lower_bound(x);
  it++;
  return *it == y;
}

int intersect(int a, int b, int c, int d) {
  if (a > c) {
    swap(a, c);
    swap(b, d);
  }
  if (b < c) return -1;
  return b - c;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    s.clear();

    int n, h;
    scanf("%d %d", &n, &h);
    vector<tuple<int, int, int>> v;
    vector<int> d;
    d.push_back(0);
    d.push_back(h);
    for (int i = 1; i <= n; i++) {
      int x, a, b;
      scanf("%d %d %d", &x, &a, &b);
      v.emplace_back(x, a, b);
      s.insert(x);
      d.push_back(a);
      d.push_back(b);
    }
    sort(v.begin(), v.end());
    Dinic dinic(n + 2);
    for (int i = 0; i < n; i++) {
      int x, a, b;
      tie(x, a, b) = v[i];
      if (a == 0) {
        dinic.AddEdge(0, i + 1, INF);
      }
      if (b == h) {
        dinic.AddEdge(i + 1, n + 1, INF);
      }
    }

    sort(d.begin(), d.end());
    d.resize(distance(d.begin(), unique(d.begin(), d.end())));
    for (int it = 1; it < d.size(); it++) {
      vector<int> num;
      for (int i = 0; i < n; i++) {
        int x, a, b;
        tie(x, a, b) = v[i];
        if (intersect(d[it-1], d[it], a, b) > 0) {
          num.push_back(i + 1);
        }
      }
      for (int i = 1; i < num.size(); i++) {
        dinic.AddEdge(num[i-1], num[i], d[it] - d[it-1]);
        dinic.AddEdge(num[i], num[i-1], d[it] - d[it-1]);
      }
    }

    int ans = dinic.GetMaxFlow(0, n + 1);
    if (ans >= INF) ans = -1;
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
