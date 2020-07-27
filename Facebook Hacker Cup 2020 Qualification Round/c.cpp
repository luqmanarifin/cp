#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 5;

int p[N], h[N];
vector<pair<int, int>> num;

long long dp[N][2];
vector<int> aft[N];
int to[N];

int pos(int x) {
  int at = lower_bound(num.begin(), num.end(), make_pair(x, -1)) - num.begin();
  if (at < num.size() && num[at].first == x) return at;
  return -1;
}

long long dfs(int x, int s) {
  if (dp[x][s] != -1) return dp[x][s];
  // printf("%d %d\n", x, s);
  long long ans = 0;
  for (auto it : aft[x]) {
    ans = max(ans, h[it] + dfs(it, 1));
  }
  if (s == 0 && h[x]) {
    long long add = h[x];
    if (to[x] != -1) {
      add += dfs(to[x], 0);
    }
    ans = max(ans, add);
  }
  return dp[x][s] = ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    num.clear();
    memset(dp, -1, sizeof(dp));
    memset(to, -1, sizeof(to));
    for (int i = 0; i < N; i++) {
      aft[i].clear();
    }

    int n;
    scanf("%d", &n);
    set<int> ada;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", p + i, h + i);
      num.emplace_back(p[i], h[i]);
      ada.insert(p[i]);
    }
    for (int i = 0; i < n; i++) {
      if (!ada.count(p[i] + h[i])) {
        ada.insert(p[i] + h[i]);
        num.emplace_back(p[i] + h[i], 0);
      }
      if (!ada.count(p[i] - h[i])) {
        ada.insert(p[i] - h[i]);
        num.emplace_back(p[i] - h[i], 0);
      }
    }
    sort(num.begin(), num.end());
    // printf("after sorting\n");
    for (int i = 0; i < num.size(); i++) {
      p[i] = num[i].first;
      h[i] = num[i].second;
    }
    for (int i = 0; i < num.size(); i++) {
      int lower = pos(p[i] - h[i]);
      int upper = pos(p[i] + h[i]);
      if (upper != -1 && upper != i) {
        to[i] = upper;
      }
      if (lower != -1 && lower != i) {
        aft[lower].push_back(i);
      }
    }
    long long ans = 0;
    for (int i = (int) num.size() - 1; i >= 0; i--) {
      ans = max(ans, h[i] + dfs(i, 1));
      ans = max(ans, dfs(i, 0));
    }
    printf("Case #%d: %lld\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
