#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int a[N];
int take[N][N];
int dp[N], first[N], last[N];

bool done[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (first[a[i]] == 0) {
      first[a[i]] = i;
    }
    last[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    memset(done, 0, sizeof(done));
    int now = 0;
    for (int j = i; j <= n; j++) {
      if (!done[a[j]]) {
        done[a[j]] = 1;
        now ^= a[j];
      }
      take[i][j] = take[j][i] = now;
    }
  }
  for (int i = 1; i <= n; i++) {
    int l = first[a[i]], r = last[a[i]];
    int j = i;
    while (j <= r) {
      l = min(l, first[a[j]]);
      r = max(r, last[a[j]]);
      j++;
    }
    if (l < i) {
      for (int j = i; j <= n; j++) take[i][j] = 0;
    } else {
      for (int j = i; j < r; j++) take[i][j] = 0;
      for (int j = r + 1; j <= n; j++) take[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
     // printf("%d %d: %d\n", j, i, take[j][i]);
      take[j][i] = max(take[j][i], take[j+1][i]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      dp[i] = max(dp[i], dp[j] + take[j+1][i]);
    }
    //printf("%d: %d\n", i, dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
