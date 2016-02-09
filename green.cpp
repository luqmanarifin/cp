#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<pair<int, int>> edge[N];
int ans;

void dfs(int now, int p, int cap) {
  vector<int> a;
  int tot = 0;
  for(auto it : edge[now]) {
    if(it.first == p) continue;
    dfs(it.first, now, it.second);
    a.push_back(it.second);
    tot += it.second;
  }
  if(a.empty()) return;
  sort(a.begin(), a.end());
  int be = 2 * a.back() - tot;
  int add = 0;
  if(cap < be) {
    ans += tot - a.back() + be - cap;
    add = tot - a.back() + be - cap;
  } else {
    int c = max(0, tot - cap);
    ans += c / 2 + c % 2;
    add = c / 2 + c % 2;
  }
  //printf("%d nambah %d\n", now, add);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
    }
    ans = 0;
    dfs(1, -1, 0);
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
