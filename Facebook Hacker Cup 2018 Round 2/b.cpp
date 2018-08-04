#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int par[N], p[N], cnt[N];
set<int> s[N];
long long ans;

void dfs(int now) {
  int root = par[now];
  for (auto it : edge[now]) {
    dfs(it);
    int other = par[it];
    if (s[root].size() < s[other].size()) swap(root, other);
    for (auto j : s[other]) s[root].insert(j);
  }
  par[now] = root;
  while (cnt[now]-- && s[root].size() > 0) {
    auto it = s[root].end();
    it--;
    ans += *it;
    s[root].erase(it);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) {
      edge[i].clear();
      par[i] = i;
      cnt[i] = 0;
      s[i].clear();
      s[i].insert(i);
    }

    long long n, m, a, b;
    scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
    for (int i = 1; i < n; i++) {
      scanf("%d", p + i);
      edge[p[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) {
      // printf("ambil subtree %d\n", (a * i + b) % n);
      cnt[(a * i + b) % n]++;
    }
    ans = 0;
    dfs(0);
    printf("Case #%d: %lld\n", tt, ans);
    fprintf(stderr, "%d done!\n", tt);
  }

  return 0;
}
