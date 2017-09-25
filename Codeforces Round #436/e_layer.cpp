#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int T = 3000;

int t[N], d[N], p[N];

int dp[N][T], got[N][T];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", t + i, d + i, p + i);
  }
  
  for (int i = 1; i <= n; i++) {
    for (int time = 0; time < T; time++) {
      dp[i][time] = dp[i - 1][time];
      got[i][time] = 0;
    }
    for (int time = d[i] - 1 - t[i]; time >= 0; time--) {
      if (dp[i][time + t[i]] < dp[i-1][time] + p[i]) {
        dp[i][time + t[i]] = dp[i-1][time] + p[i];
        got[i][time + t[i]] = i;
      }
    }
  }
  int best = -1, now = -1;
  for (int i = 0; i < T; i++) {
    if (dp[n][i] > best) {
      best = dp[n][i];
      now = i;
    }
  }
  //printf("%d %d\n", best, now);
  vector<int> ans;
  for (int i = n; i >= 1; i--) {
    if (got[i][now]) ans.push_back(got[i][now]);
    now -= t[got[i][now]];
  }
  reverse(ans.begin(), ans.end());
  printf("%d\n", best);
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it); printf("\n");
  return 0;
}
