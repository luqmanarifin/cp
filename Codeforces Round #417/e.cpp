#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int BIG = 2e7 + 6;

vector<int> edge[N], g[2];
int leaf, a[N];
int cnt[BIG];

void dfs(int now, int c) {
  g[c].push_back(a[now]);
  for (auto it : edge[now]) dfs(it, c ^ 1);
  if (edge[now].empty()) leaf = c;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    edge[p].push_back(i);
  }
  dfs(1, 0);
  int all = 0;
  for (auto it : g[leaf]) {
    cnt[it]++;
    all ^= it;
  }
  long long ans = 0;
  for (auto it : g[leaf ^ 1]) {
    ans += cnt[all ^ it];
  }
  if (all == 0) {
    ans += 1LL * g[0].size() * (g[0].size() - 1) / 2;
    ans += 1LL * g[1].size() * (g[1].size() - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
