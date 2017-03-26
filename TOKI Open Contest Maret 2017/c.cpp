#include <bits/stdc++.h>

using namespace std;

const int N = 405;
const int M = 2e5 + 5;

int a[N][N], n, m;
int com[N * N]; // masuk komponen berapa
long long gain[N * N];
vector<int> edge[N * N];

vector<int> pos[M];

set<int> adj[N * N];

int id(int i, int j) {
  return i * m + j + 1;
}

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;

void tarjanSCC(int v, int bef) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : edge[v]) {
    //if (u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    int num_comp = ++numCC;
    vector<int> el;
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      el.push_back(u);
      if(u == v)
        break;
    }
    //printf("%d: ", num_comp);
    for (auto it : el) {
      //printf("%d ", it);
      com[it] = num_comp;
      if (1 <= it && it <= n*m) {
        int v = it - 1;
        gain[num_comp] += a[v / m][v % m];
      }
    }
    //printf("\n");
  }
}

long long dp[N * N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      pos[a[i][j]].push_back(id(i, j));
    }
  }
  for (int i = 0; i < M; i++) {
    if (pos[i].empty()) continue;
    for (int j = 0; j + 1 < pos[i].size(); j++) {
      edge[pos[i][j]].push_back(pos[i][j+1]);
      edge[pos[i][j+1]].push_back(pos[i][j]);
    }
    edge[pos[i].back()].push_back(pos[i][0]);
    edge[pos[i][0]].push_back(pos[i].back());
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j + 1 < m) {
        edge[id(i, j)].push_back(id(i, j + 1));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    edge[0].push_back(id(i, 0));
    edge[id(i, m - 1)].push_back(n * m + 1);
  }
  for (int i = 0; i <= n*m+1; i++) {
    //for (auto it : edge[i]) printf("%d -> %d\n", i, it);
  }
  
  // In MAIN();
  num.assign(N * N, -1);
  low.assign(N * N, 0);
  vis.assign(N * N, 0);
  cntr = numCC = 0;
  for(int i = 0; i <= n*m+1; i++) {
    if(num[i] == -1)
      tarjanSCC(i, -1);
  }
    
  for (int i = 0; i <= n*m+1; i++) {
    for (auto it : edge[i]) {
      if (com[it] != com[i]) {
        adj[com[i]].insert(com[it]);
      }
    }
  }
  int to[N * N];
  memset(to, 0, sizeof(to));
  for (int i = 1; i <= numCC; i++) {
    for (auto it : adj[i]) {
      to[it]++;
      //printf("%d -> %d\n", i, it);
    }
    //printf("%d gain %I64d\n", i, gain[i]);
  }
  //printf("numCC %d\n", numCC);
  queue<int> q;
  q.push(com[0]);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto it : adj[now]) {
      dp[it] = max(dp[it], dp[now] + gain[it]);
      
      to[it]--;
      if (to[it] == 0) {
        q.push(it);
      }
    }
  }
  cout << dp[com[n*m+1]] << endl;
  return 0;
}
