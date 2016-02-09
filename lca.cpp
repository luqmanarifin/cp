#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<pair<int, int>> edge[N];

// node i height nya berapa
int h[N];

// di posisi lca node keberapa
int t, at[N * 3];

// node i posisinya dimana
int pos[N * 3];

// sparse table
int tab[N * 3][20];
int lg[N * 3];

int dp[N];
int ans[N];

void dfs(int now, int prev) {
  pos[now] = t;
  at[t++] = now;
  h[now] = h[prev] + 1;
  for(auto it : edge[now]) {
    if(it.first == prev) continue;
    dfs(it.first, now);
    pos[now] = t;
    at[t++] = now;
  }
}

void build() {
  dfs(1, 0);
  for(int i = 0; i < t; i++) {
    tab[i][0] = i;
  }
  for(int i = 0; (1 << i) < 3 * N; i++) {
    lg[1 << i] = i;
  }
  for(int i = 1; i < 3 * N; i++) {
    if(lg[i]) continue;
    lg[i] = lg[i - 1];
  }
  for(int j = 1; (1 << j) <= t ; j++) {
    for(int i = 0; i + (1 << j) <= t; i++) {
      if(h[at[tab[i][j - 1]]] < h[at[tab[i + (1 << (j - 1))][j - 1]]]) {
        tab[i][j] = tab[i][j - 1];
      } else {
        tab[i][j] = tab[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}

int rmq(int i, int j) {
  int logg = lg[j - i + 1];
  return h[at[tab[i][logg]]] < h[at[tab[j-(1<<logg)+1][logg]]]? tab[i][logg] : tab[j-(1<<logg)+1][logg];
}

int lca(int u, int v) {
  return at[rmq(min(pos[u], pos[v]), max(pos[u], pos[v]))];
}

int finish(int now, int prev) {
  int ret = dp[now];
  for(auto it : edge[now]) {
    if(it.first == prev) continue;
    int tmp = finish(it.first, now);
    ans[it.second] = tmp;
    ret += tmp;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].emplace_back(b, i);
    edge[b].emplace_back(a, i);
  }
  build();
  int k;
  scanf("%d", &k);
  while(k--) {
    int a, b;
    scanf("%d %d", &a, &b);
    dp[a]++; dp[b]++;
    dp[lca(a, b)] -= 2;
    //printf("lca : %d %d = %d\n", a, b, lca(a, b));
  }
  assert(finish(1, 0) == 0);
  for(int i = 0; i < n - 1; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
