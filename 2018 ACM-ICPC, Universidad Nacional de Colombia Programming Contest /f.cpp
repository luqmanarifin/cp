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

int cnt[105][26];
char s[100];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%s", s);
      int len = strlen(s);
      for (int k = 0; k < len; k++) {
        cnt[i][s[k] - 'A']++;
      }
    }
  }
  int k;
  scanf("%d", &k);

  Dinic dinic(n + 28);
  int s = 0, t = n + 27;
  for (int i = 1; i <= n; i++) {
    dinic.AddEdge(0, i, 1);
  }
  for (int i = 1; i <= 26; i++) {
    dinic.AddEdge(n + i, t, k);
  }
  for (int i = 0; i < n; i++) {
    int mx = -1;
    for (int j = 0; j < 26; j++) mx = max(mx, cnt[i][j]);
    for (int j = 0; j < 26; j++) {
      if (cnt[i][j] == mx) {
        dinic.AddEdge(1 + i, 1 + n + j, 1);
      }
    }
  }
  cout << dinic.GetMaxFlow(s, t) << endl;
  return 0;
}
