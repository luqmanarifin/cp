
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const long long inf = 1e18;

long long dp[N][105];
int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 105; j++) {
      dp[i][j] = -inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    
  }

  return 0;
}
