#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

vector<int> all;
map<int, int> mp;

// end, id
vector<pair<int, int>> add[N];
pair<long long, long long> dp[N];

int a[N], b[N], c[N];
pair<int, int> bef[N];  // using which, to which

vector<int> ans;

void dfs(int now) {
  if (now == 0) return;
  if (bef[now].first != 0) {
    ans.push_back(bef[now].first);
  }
  dfs(bef[now].second);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", a + i, b + i, c + i);
    all.push_back(a[i]);
    all.push_back(b[i]);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i < all.size(); i++) mp[all[i]] = i;
  for (int i = 1; i <= n; i++) {
    add[mp[a[i]]].emplace_back(mp[b[i]], i);
  }
  
  for (int i = 0; i < all.size(); i++) {
    if (dp[i+1] < dp[i]) {
      dp[i+1] = dp[i];
      bef[i+1] = {0, i};
    }
    dp[i + 1] = max(dp[i + 1], dp[i]);
    for (auto it : add[i]) {
      int end = it.first;
      int id = it.second;
      int use = c[id];
      int duration = b[id] - a[id];
      pair<long long, long long> cur = {dp[i].first + use, dp[i].second - duration};
      if (cur > dp[end]) {
        dp[end] = cur;
        bef[end] = {id, i};
      }
    }
  }
  int to = all.size() - 1;
  dfs(to);
  printf("%d %I64d %I64d\n", ans.size(), dp[to].first, -dp[to].second);
  sort(ans.begin(), ans.end());
  for (auto it : ans) printf("%d ", it);
  return 0;
}
