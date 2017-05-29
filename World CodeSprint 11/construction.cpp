#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int magic = 800;

vector<int> edge[N];

vector<int> adj[N], el[N];
int comp[N], from[N];

vector<pair<int, int>> ask[N];
int ans[N];

#define bit unsigned long long
bit dp[N / 2][magic];

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;
 
void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : edge[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    //printf("%d: ", numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      //printf("%d ", u);
      el[numCC].push_back(u);
      comp[u] = numCC;
      if(u == v)
        break;
    }
    //printf("\n");
    ++numCC;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    edge[u].push_back(v);
  }
  int t = 0, q;
  scanf("%d", &q);
  while (q--) {
    int cmd;
    scanf("%d", &cmd);
    if (cmd == 1) {
      int x, d;
      scanf("%d %d", &x, &d);
      x--;
      if (d == 0) {
        edge[x].push_back(n);
      } else {
        edge[n].push_back(x);
      }
      n++;
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      x--; y--;
      ask[y].emplace_back(x, t++);
    }
  }
  
  num.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, 0);
  cntr = numCC = 0;
  for(int i = 0; i<n; i++)
    if(num[i] == -1)
      tarjanSCC(i);

  set<pair<int, int>> edges;
  for (int i = 0; i < n; i++) {
    for (auto it : edge[i]) {
      if (comp[i] == comp[it]) continue;
      edges.insert(make_pair(comp[i], comp[it]));
    }
  }
  for (auto it : edges) {
    from[it.second]++;
    adj[it.first].push_back(it.second);
  }
  queue<int> st;
  for (int i = 0; i < numCC; i++) {
    if (from[i] == 0) {
      st.push(i);
    }
  }
  int done = 0;
  while (!st.empty()) {
    int now = st.front();
    done++;
    st.pop();
    for (auto it : el[now]) {
      int i = it / 64;
      int j = it % 64;
      dp[now][i] |= (1ULL << j);
    }
    for (auto node : el[now]) {
      for (auto it : ask[node]) {
        int i = it.first / 64;
        int j = it.first % 64;
        if (dp[now][i] & (1ULL << j)) {
          ans[it.second] = 1;
        }
      }
    }
    for (auto near : adj[now]) {
      for (int i = 0; i < magic; i++) {
        dp[near][i] |= dp[now][i];
      }
      from[near]--;
      if (from[near] == 0) st.push(near);
    }
  }
  assert(done == numCC);
  for (int i = 0; i < t; i++) puts(ans[i]? "Yes" : "No");
  return 0;
}
