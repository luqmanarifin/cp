#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int INF = 1e9;

struct Edge {
  int from, to, cap, flow, index, st;
  Edge(int from, int to, int cap, int flow, int index, int st) :
    from(from), to(to), cap(cap), flow(flow), index(index), st(st) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
 
  void AddEdge(int from, int to, int cap, int st) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size(), st));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1, st));
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

char a[N][10], b[N][10];
int pa[N], sa[N], pb[N], sb[N];

//#define LOCAL

int main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i]);
    for (int j = 0; j < 3; j++) pa[i] += a[i][j] - '0';
    for (int j = 3; j < 6; j++) sa[i] += a[i][j] - '0';
  }
  for (int i = 1; i <= m; i++) {
    scanf("%s", b[i]);
    for (int j = 0; j < 3; j++) pb[i] += b[i][j] - '0';
    for (int j = 3; j < 6; j++) sb[i] += b[i][j] - '0';
  }
  int nodes = n + m + 2;
  Dinic dinic(nodes);
  for (int i = 1; i <= n; i++) {
    dinic.AddEdge(0, i, 1, 0);
  }
  for (int i = 1; i <= m; i++) {
    dinic.AddEdge(n + i, nodes - 1, 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (pa[i] == sb[j]) {
        //printf("0 %d %d\n", i, j);
        dinic.AddEdge(i, n + j, 1, 0);
      }
      if (pb[j] == sa[i]) {
        //printf("1 %d %d\n", i, j);
        dinic.AddEdge(i, n + j, 1, 1);
      }      
    }
  }
  int ans = dinic.GetMaxFlow(0, nodes - 1);
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (auto e : dinic.G[i]) {
      if (n < e.to && e.to < nodes - 1 && e.flow > 0) {
        if (e.st == 0) {
          printf("AT %s %s\n", a[i], b[e.to - n]);
        } else {
          printf("TA %s %s\n", b[e.to - n], a[i]);
        }
      }
    }
  }
  return 0;
}
