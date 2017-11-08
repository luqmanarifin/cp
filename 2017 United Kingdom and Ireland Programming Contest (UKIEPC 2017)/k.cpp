#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge {
  int from, to, cap, flow, index, id;
  Edge(int from, int to, int cap, int flow, int index, int id) :
    from(from), to(to), cap(cap), flow(flow), index(index), id(id) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
 
  void AddEdge(int from, int to, int cap, int id) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size(), id));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1, 0));
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

const int N = 405;
const int BIG = 1e6 + 5;

int w[N], l[N];
int t[N];

vector<int> all;
int num[BIG];

vector<int> f[BIG];
vector<int> ans[N];

struct item {
  item() {}
  item(int node, int ke) : node(node), ke(ke) {}
  int node;
  int ke;
};

// ke mana, flow berapa, id
vector<tuple<int, int, int>> edge[N];
item b[N];
int d[N];

int main() {
  int n, m;
  scanf("%d", &n);
  vector<int> all;
  all.push_back(0);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", w + i, l + i);
    all.push_back(w[i]);
    all.push_back(l[i]);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", t + i);
    all.push_back(t[i]);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i < all.size(); i++) num[all[i]] = i;
  for (int i = 1; i <= n; i++) {
    w[i] = num[w[i]];
    l[i] = num[l[i]];
  }
  for (int i = 1; i <= m; i++) {
    t[i] = num[t[i]];
    f[t[i]].push_back(i);
  }
  int nodes = all.size() + 2;
  Dinic dinic(nodes);
  dinic.AddEdge(0, 1, INF, 0);
  for (int i = 1; i <= n; i++) {
    dinic.AddEdge(w[i] + 1, l[i] + 1, 1, i);
  }
  for (int i = 1; i < all.size(); i++) {
    dinic.AddEdge(i + 1, i, INF, 0);
  }
  for (int i = 1; i <= m; i++) {
    dinic.AddEdge(t[i] + 1, nodes - 1, 1, 0);
  }
  int mf = dinic.GetMaxFlow(0, nodes - 1);
  if (mf != m) {
    puts("impossible");
    return 0;
  }
  for (int i = 0; i < nodes; i++) {
    for (auto e : dinic.G[i]) {
      if (e.flow > 0) {
        //printf("%d ke %d flow %d %d\n", i, e.to, e.flow, e.id);
        edge[i].emplace_back(e.to, e.flow, e.id);
      }
    }
  }
  while (1) {
    fill(d, d + N, INF);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int i = 0; i < edge[now].size(); i++) {
        auto it = edge[now][i];
        int to, flow, id;
        tie(to, flow, id) = it;
        if (flow == 0) continue;
        if (d[to] > d[now] + 1) {
          d[to] = d[now] + 1;
          b[to] = item(now, i);
          q.push(to);
        }
      }
    }
    //printf("finish %d\n", d[nodes - 1]);
    if (d[nodes - 1] == INF) break;
    //puts("dapet");
    int at = f[b[nodes - 1].node - 1].back();
    f[b[nodes - 1].node - 1].pop_back();
    
    int now = nodes - 1;
    while (now > 0) {
      int to, flow, id;
      tie(to, flow, id) = edge[b[now].node][b[now].ke];
      int bef = b[now].node;
      //printf("%d %d %d %d\n", now, bef, flow, id);
      edge[b[now].node][b[now].ke] = make_tuple(to, flow - 1, id);
      if (id > 0) {
        ans[at].push_back(id);
      }
      now = bef;
    }
    reverse(ans[at].begin(), ans[at].end());
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      printf("%d%c", ans[i][j], " \n"[j + 1 == ans[i].size()]);
    }
  }
  return 0;
}
