#include <bits/stdc++.h>

using namespace std;

const long long inf = 4e18;
const int N = 64;

long long dp[N][N], ne[N][N];

void upd(long long& at, long long val) {
  at = min(at, val);
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int add = 1; add <= 62; add++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        ne[i][j] = dp[i][j];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dp[i][j] == inf) continue;
        if (i + add < N) {
          upd(ne[i + add][j], dp[i][j] + (1LL << add));
        }
        if (j + add < N) {
          upd(ne[i][j + add], dp[i][j] + (1LL << add));
        }
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j] = ne[i][j];
      }
    }
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    long long ans = inf;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (x >> i == y >> j) {
          ans = min(ans, dp[i][j]);
        }
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
