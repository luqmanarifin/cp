#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<int> edge[N];
int lef[N], rig[N], cnt, dad[N];

int a[N], h[N];
int all[N], dp[N][2];   // 0 berarti golongan root, 1 berarti kroco

void dfs(int now, int bef) {
  ++cnt;
  h[now] = h[bef] ^ 1;
  dad[now] = bef;
  lef[now] = cnt;
  for(auto it : edge[now]) {
    if(it == bef) continue;
    dfs(it, now);
  }
  rig[now] = cnt;
  
  all[now] = dp[now][0] = a[now];
  for(auto it : edge[now]) {
    if(it == bef) continue;
    all[now] ^= all[it];
    dp[now][0] ^= dp[it][1];
  }
  dp[now][1] = all[now] ^ dp[now][0];
}

int main() {
  int n, q;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  int nope = dp[1][1];
  
  scanf("%d", &q);
  while(q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    int ans = 0;
    if(dad[u] == v) {
      ans = nope;
    } else if(lef[u] <= lef[v] && lef[v] <= rig[u]) {
      puts("INVALID");
      continue;
    } else {
      //printf("me %d %d\n", dp[u][0], dp[u][1]);
      ans = (nope ^ dp[u][h[u]] ^ dp[u][h[v] ^ 1]);
      //printf("cok %d %d\n", dp[u][h[u]], dp[u][h[v]]);
    }
    //printf("haha %d\n", ans);
    puts(ans? "YES" : "NO");
  }
  return 0;
}