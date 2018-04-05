#include <bits/stdc++.h>

using namespace std;

const string NAME = "ideal";

const int N = 1e6 + 5;
const int inf = 1e9;

vector<pair<int, int>> edge[N];  // kemana - color (0 kalo langsung)
vector<pair<int, int>> ori[N];   // kemana - color
map<int, int> mp[N];
int nodes;
int par[N];

map<int, vector<int>> by_col[N];    // node - color - ke
map<int, bool> done_idx[N];         // node - color

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int get_id_node_warna(int node, int warna) {
  if (!mp[node].count(warna)) {
    mp[node][warna] = ++nodes;
  }
  return mp[node][warna];
}

vector<int> tmp;

void dfs(int node, int col) {
  if (done_idx[node].count(col)) return;
  tmp.push_back(node);
  done_idx[node][col] = 1;
  for (auto it : by_col[node][col]) {
    dfs(it, col);
  }
}

// dijkstra
int dist[N];
vector<pair<int, int>> bt[N];

vector<pair<int, int>> imp[N];
int done[N];

void backtrack(int now) {
  if (done[now]) return;
  done[now] = 1;
  for (auto it : bt[now]) {
    backtrack(it.first);
    imp[it.first].emplace_back(now, it.second);
  }
}

vector<int> ans;

void solve(vector<int> st) {
  map<int, vector<int>> with;
  map<int, bool> done;
  queue<int> q;
  for (auto it : st) {
    if (done[it]) continue;
    q.push(it);
    done[it] = 1;
  }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto it : imp[now]) {
      if (it.second == 0) {
        if (!done[it.first]) {
          done[it.first] = 1;
          q.push(it.first);
        }
      } else {
        with[it.second].push_back(it.first);
      }
    }
  }
  if (with.empty()) return;
  ans.push_back((with.begin())->first);
  solve((with.begin())->second);
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif

  int n, m;
  scanf("%d %d", &n, &m);
  nodes = n;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    edge[u].emplace_back(v, c);
    edge[v].emplace_back(u, c);
  }
  // for (int i = 1; i <= n; i++) {
  //   for (auto it : by_col[i]) printf("node %d warna %d: %d\n", i, it.first, get_id_node_warna(i, it.first));
  // }
  // for (int i = 1; i <= nodes; i++) for (auto it : edge[i]) printf("%d %d: %d\n", i, it.first, it.second);
  fill(dist, dist + N, inf);
  dist[1] = 0;
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, 1);
  while (!pq.empty()) {
    int now, cost;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost;
    if (cost != dist[now]) continue;
    for (auto it : edge[now]) {
      int near = it.first;
      int ncos = cost + (it.second != 0);
      if (dist[near] > ncos) {
        dist[near] = ncos;
        pq.emplace(-dist[near], near);
        bt[near].clear();
        bt[near].emplace_back(now, it.second);
      } else if (dist[near] == ncos) {
        bt[near].emplace_back(now, it.second);
      }
    }
  }
  backtrack(n);
  solve({1});
  //printf("ans %d\n", ans.size());
  assert(ans.size() == dist[n]);
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it); printf("\n");

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
