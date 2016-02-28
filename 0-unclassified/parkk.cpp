#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
vector<int> edge[N];
int ans, n, m;

void dfs(int now, int prev, int p) {
  if(a[now] == 0) {
    p = 0;
  } else {
    p++;
  }
  if(p > m) {
    return;
  }
  bool ada = 0;
  for(auto it : edge[now]) {
    if(it == prev) {
      continue;
    }
    ada = 1;
    dfs(it, now, p);
  }
  if(!ada) {
    ans++;
    return;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, -1, 0);
  cout << ans << endl;
  return 0;
}
