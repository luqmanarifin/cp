#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int inf = 2e9;

vector<int> all;
int dp[N * N][2];

int a[N], b[N];
int s[N][N];

int find(int l, int r, int k) {
  if (l > r) return 0;
  return dp[r][k] - (l - 1 >= 0? dp[l - 1][k] : 0);
}  

int id(int val) {
  return lower_bound(all.begin(), all.end(), val) - all.begin();
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    all.clear();
    memset(dp, 0, sizeof(dp));
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &s[i][j]);
        int d = (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
        all.push_back(d);
        //printf("jarak %d %d %d\n", i, j, d);
      }
    }
    sort(all.begin(), all.end());
    all.resize(distance(all.begin(), unique(all.begin(), all.end())));
    //for (auto it : all) printf("%d ", it); printf("\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int d = (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
        int idk = id(d);
        dp[idk][s[i][j]]++;
      }
    }
    for (int i = 1; i < N * N; i++) {
      dp[i][0] += dp[i - 1][0];
      dp[i][1] += dp[i - 1][1];
    }
    int ans = inf, p = -1;
    for (int i = 0; i < all.size(); i++) {
      int cur = find(0, i, 0) + find(i + 1, all.size() - 1, 1);
      if (cur < ans) {
        ans = cur;
        p = all[i];
      }
    }
    printf("Case #%d: %d %d\n", tt, p, ans);
  }
  

  return 0;
}
