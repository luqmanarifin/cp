
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis;
int cntr, numCC;
int par[N];
vector<int> adj[N];

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    //printf("SCC %d :", numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      //printf(" %d", u);
      par[u] = numCC;
      if(u == v)
        break;
    }
    //printf("\n");
    numCC++;
  }
}

int u[N], v[N], w[N];
vector<pair<int, long long>> edge[N];
long long gain[N], del[N];

long long sum(long long n) {
  return n * (n + 1) / 2;
}

long long get(int c) {
  long long l = 0, r = c;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (sum(mid) <= c) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  //printf("kentu %d %lld\n", c, l);
  return 1LL * c * (l + 1) - del[l];
}

long long dp[N];

long long dfs(int now) {
  if (dp[now] != -1) return dp[now];
  //cout << now << endl;
  long long best = 0;
  for (auto it : edge[now]) {
    best = max(best, dfs(it.first) + it.second);
  }
  return dp[now] = best + gain[now];
}

int main() {
  for (int i = 1; i < N; i++) del[i] = del[i - 1] + sum(i);
  
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", u + i, v + i, w + i);
    adj[u[i]].push_back(v[i]);
  }
  int s;
  scanf("%d", &s);
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  cntr = numCC = 0;
  
  for(int i = 1; i<=n; i++)
    if(num[i] == -1)
      tarjanSCC(i);
  
  //printf("tarjan done\n");
  for (int i = 0; i < m; i++) {
    int a = par[u[i]];
    int b = par[v[i]];
    if (a == b) {
      gain[a] += get(w[i]);
    } else {
      edge[a].emplace_back(b, w[i]);
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(par[s]) << endl;
  return 0;
}
