#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int ada[MAX];
int need[MAX];
int h[MAX];
int dp[505][5005];

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n * k; i++) {
    int v;
    scanf("%d", &v);
    ada[v]++;
  }
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    need[v]++;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", h + i);
  }
  int ans = 0;
  for (int c = 1; c < MAX; c++) {
    for (int i = 0; i <= need[c]; i++) {
      for (int j = 0; j <= ada[c]; j++) {
        dp[i][j] = 0;
      }
    }
    for (int i = 1; i <= need[c]; i++) {
      for (int j = 0; j <= ada[c]; j++) {
        for (int take = 0; take <= min(j, k); take++) {
          upd(dp[i][j], dp[i-1][j-take] + h[take]);
        }
      }
    }
    int cur = 0;
    for (int j = 0; j <= ada[c]; j++) {
      upd(cur, dp[need[c]][j]);
    }
    ans += cur;
  }
  printf("%d\n", ans);

  return 0;
}
