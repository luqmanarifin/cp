#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair<int, int>> edge[N];

char s[N][30];

void dfs(int now, int t) {
  int p = upper_bound(edge[now].begin(), edge[now].end(), make_pair(t, -1)) - edge[now].begin() - 1;
  if (p >= 0) {
    printf("I_love_");
    dfs(edge[now][p].second, edge[now][p].first);
  } else {
    printf("%s", s[now]);
  }
}

int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].emplace_back(i, b);
  }
  dfs(1, m);

  return 0;
}
