#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

int a[N], n;
long long ans;
vector<int> edge[N];

void dfs(int now, int p) {
  for(auto it : edge[now]) {
    if(it == p) continue;
    dfs(it, now);
    a[now] += a[it];
  }
  a[now]++;
}

void cari(int now, int p) {
  int sum = 0;
  vector<int> tmp;
  for(auto it : edge[now]) {
    if(it == p) continue;
    cari(it, now);
    tmp.push_back(a[it]);
    sum += a[it];
  }
  tmp.push_back(n - 1 - sum);
  sum = n - 1;
  long long cur = 0;
  for(auto it : tmp) {
    sum -= it;
    cur += 1LL * it * sum;
  }
  ans = max(ans, cur);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    ans = 0;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs(1, 0);
    cari(1, 0);
    printf("Case #%d: %lld\n", tt, ans);
  }
  
  return 0;
}
