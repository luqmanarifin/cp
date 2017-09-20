#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int MAGIC = 1e5 + 5;

double dp[MAGIC][N];  // naik berapa - sisa tiket
int p[N][N];          // sisa - atraksi      

int main() {
  int T, A;
  scanf("%d %d", &T, &A);
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < A; j++) {
      scanf("%d", &p[i][j]);
    }
  }
  dp[0][T] = 1;
  for (int i = 0; i < MAGIC - 1; i++) {
    for (int j = 1; j <= T; j++) {
      double rusak = (double) p[j - 1][i % A] / 100;
      dp[i + 1][j] += dp[i][j] * rusak;
      dp[i + 1][j - 1] += dp[i][j] * (1 - rusak);
    }
  }
  double ans = 0;
  for (int i = 1; i < MAGIC; i++) {
    ans += dp[i][0] * i;
  }
  printf("%.15f\n", ans);
  return 0;
}
