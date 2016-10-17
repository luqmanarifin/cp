#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
vector<int> edge[N];
bool done[N];

set<int> col;
int cnt[N], st;

void dfs(int now) {
  if (done[now]) return;
  done[now] = 1;
  col.insert(a[now]);
  cnt[a[now]]++;
  st++;
  for (auto it : edge[now]) dfs(it);
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (done[i] == 0 && edge[i].size()) {
      col.clear();
      st = 0;
      dfs(i);
      int maks = 0;
      for (auto it : col) {
        maks = max(maks, cnt[it]);
      }
      ans += st - maks;
      for (auto it : col) cnt[it] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
