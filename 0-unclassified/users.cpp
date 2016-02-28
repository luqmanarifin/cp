#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int dp[N][2], k;
vector<int> edge[N];

void dfs(int now) {
  dp[now][0] = dp[now][1] = 1;
  vector<pair<int, int>> live, dead;
  for(auto it : edge[now]) {
    dfs(it);
    live.emplace_back(dp[it][1], it);
    dead.emplace_back(dp[it][0], it);
  }
  sort(live.begin(), live.end());
  sort(dead.begin(), dead.end());
  reverse(live.begin(), live.end());
  reverse(dead.begin(), dead.end());
  for(int i = 0; i < live.size() && i < k - 1; i++) {
    dp[now][1] += live[i].first;
  }
  set<int> good;
  int cur = 0, lst = -1;
  for(int i = 0; i < live.size() && i < k; i++) {
    good.insert(live[i].second);
    cur += live[i].first;
    lst = live[i].first;
  }
  int maxi = cur;
  for(int i = 0; i < dead.size(); i++) {
    int at = dead[i].second;
    if(good.count(at)) {
      maxi = max(maxi, cur - dp[at][1] + dp[at][0]);
    } else {
      maxi = max(maxi, cur - lst + dp[at][0]);
    }
  }
  dp[now][0] += maxi;
}

int main() {
  int n;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++) {
    int m;
    scanf("%d", &m);
    while(m--) {
      int c;
      scanf("%d", &c);
      edge[i].push_back(c);
    }
  }
  dfs(1);
  printf("%d\n", max(dp[1][0], dp[1][1]));
  return 0;
}
