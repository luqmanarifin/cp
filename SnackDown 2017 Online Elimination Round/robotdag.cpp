#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct Edge {
  long long from, to, cap, flow, index;
  Edge(long long from, long long to, long long cap, long long flow, long long index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  long long N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<long long> Q;
  
  vector<vector<int>> ori;
  
  Dinic(long long N) : N(N), G(N), dad(N), Q(N), ori(N) {}
  
  void AddEdge(long long from, long long to, long long cap) {
    ori[from].push_back(G[from].size());
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }
  
  int get_ans(int k) {
    vector<int> edge[N];
    vector<int> back(N);
    vector<vector<long long>> ada(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
      for (auto it : ori[i]) {
        if (G[i][it].flow > 0) {
          edge[i].push_back(G[i][it].to);
          ada[i][G[i][it].to] += G[i][it].flow;
        }
      }
    }
    int last = 0;
    vector<int> vis(N);
    for (int kk = 1; kk <= k; kk++) {
      queue<int> q;
      vis.assign(N, -1);
      q.push(0);
      vis[0] = 0;
      while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto it : edge[now]) {
          if (vis[it] == -1 && ada[now][it]) {
            vis[it] = vis[now] + 1;
            q.push(it);
            back[it] = now;
          }
        }
      }
      last = vis[N - 1] - 1;
      //printf("iter %d: %d\n", kk, last);
      int now = N - 1;
      while (now > 0) {
        ada[back[now]][now]--;
        now = back[now];
      }
    }
    return last;
  }

  long long BlockingFlow(long long s, long long t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    long long head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      long long x = Q[head++];
      for (long long i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (long long i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      long long amt = INF;
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

  long long GetMaxFlow(long long s, long long t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

const int N = 105;
const int inf = 1e9;

vector<int> edge[N];
int d[N], rd[N];
int off[N], range[N];

int code(int u, int t) {
  return off[u] + t - d[u];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      edge[i].clear();
      d[i] = inf;
      rd[i] = -1;
    }
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      edge[u].push_back(v);
    }
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto it : edge[now]) {
        if (d[now] + 1 < d[it]) {
          d[it] = d[now] + 1;
          q.push(it);
        }
      }
    }
    
    rd[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
      int now, cost;
      tie(cost, now) = pq.top();
      cost = -cost;
      pq.pop();
      if (rd[now] != cost) continue;
      for (auto it : edge[now]) {
        if (rd[now] + 1 > rd[it]) {
          rd[it] = rd[now] + 1;
          pq.emplace(-rd[it], it);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      range[i] = (d[i] == inf? 0 : rd[i] - d[i] + 1);
    }
    int all = 0;
    for (int i = 0; i < n; i++) {
      if (i) off[i] = off[i - 1] + range[i-1];
      all += range[i];
      //printf("%d: %d %d\n", i, d[i], rd[i]);
    }
    //printf("node asli %d all %d\n", n, all);
    Dinic dinic(all + 1);
    for (int i = 0; i < n; i++) {
      if (range[i] == 0) continue;
      for (auto it : edge[i]) {
        if (range[it] == 0) continue;
        for (int k = d[i]; k <= rd[i]; k++) {
          if (d[it] <= k + 1 && k + 1 <= rd[it]) {
            int from = code(i, k);
            int to = code(it, k + 1);
            dinic.AddEdge(from, to, 1);
          }
        }
      }
    }
    for (int i = d[n - 1]; i <= rd[n - 1]; i++) {
      int from = code(n - 1, i);
      dinic.AddEdge(from, all, inf);
    }
    
    int maxflow = dinic.GetMaxFlow(0, all);
    if (maxflow < k) {
      puts("-1");
    } else {
      printf("%d\n", dinic.get_ans(k));
    }
  }

  return 0;
}
