#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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

int to[123], tot[123], c[123];

int main() {
  int n, q, s;
  scanf("%d %d %d", &n, &q, &s);
  for (int i = 0; i < s; i++) {
    int x;
    scanf("%d", &x);
    x--;
    to[i] = x;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", c+i);
  }
  int cnt = 2 * q + 1;
  Dinic mf(cnt * n + 2);
  int ss = mf.N - 2, t = mf.N - 1;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int d;
    scanf("%d", &d);
    fill(tot, tot+q, 0);
    for (int j = 0; j < s; j++) {
      int a;
      scanf("%d", &a);
      sum += a;
      tot[to[j]] += a;
    }
    int r = i * cnt + 2 * q;
    mf.AddEdge(r, t, d);
    for (int j = 0; j < q; j++) {
      mf.AddEdge(ss, i * cnt + j, tot[j]);
      mf.AddEdge(i * cnt + j, i * cnt + q + j, c[j]);
      mf.AddEdge(i * cnt + q + j, r, INF);
    }
    if (i) {
      for (int j = 0; j < q; j++) {
        mf.AddEdge(i * cnt - q - 1 + j, i * cnt + j, c[j]);
      }
    }
  }
  long long res = mf.GetMaxFlow(ss, t);
  puts((res == sum) ? "possible": "impossible");
  return 0;
}
