#include <bits/stdc++.h>

using namespace std;

/*
  bikin scc
  dfs + cari jawaban
*/

const int N = 1e5 + 5;

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis, adj[N];
int cntr, numCC;

vector<int> el[N];
int cc[N];

void tarjanSCC(int v, int bef) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if (u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    //printf("SCC %d :", numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      el[numCC].push_back(u);
      cc[u] = numCC;
      //printf(" %d", u);
      if(u == v)
        break;
    }
    //printf("\n");
    numCC++;
  }
}

int a[N], got[N];
vector<int> edge[N];
int ans;

int dfs(int now, int bef) {
  //printf("moron %d %d\n", now, bef);
  vector<int> kids;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    int cur = dfs(it, now);
    kids.push_back(cur);
  }
  sort(kids.begin(), kids.end());
  reverse(kids.begin(), kids.end());
  int kid = (kids.size() >= 2? kids[0] + kids[1] : (kids.size() >= 1? kids[0] : 0));
  //printf("%d %d %d\n", now, got[now], kid);
  ans = max(ans, got[now] + kid);
  return got[now] + (kids.size() >= 1? kids[0] : 0);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  num.assign(n + 1, -1);
  low.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  cntr = numCC = 0;
  for(int i = 1; i <= n; i++)
    if(num[i] == -1)
      tarjanSCC(i, -1);
  
  for (int i = 1; i <= n; i++) got[cc[i]] += a[i];
  for (int i = 1; i <= n; i++) {
    for (auto it : adj[i]) {
      if (cc[i] != cc[it]) {
        edge[cc[i]].push_back(cc[it]);
        //printf("ke %d %d\n", cc[i], cc[it]);
      }
    }
  }
  dfs(0, -1);
  
  cout << ans << endl;
  return 0;
}
