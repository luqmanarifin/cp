#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long inf = 4e18;

// dp[pos][how many group have been created]
long long ret[N][N];
long long sum[N][N];
int val[N];

int main() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      ret[i][j] = inf;
    }
  }
  
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for(int i = 0; i < n; i++) {
    scanf("%d", val + i);
  }
  ret[0][1] = 0;
  sum[0][1] = val[0];
  for(int i = 1; i < n; i++) {
    for(int j = 1; j <= n; j++) {
      ret[i][j] = ret[i - 1][j];
      sum[i][j] = sum[i - 1][j] + val[i];
      if(j > 1) {
        if((ret[i - 1][j - 1] | sum[i - 1][j - 1] | val[i]) <= (ret[i][j] | sum[i][j])) {
          ret[i][j] = ret[i - 1][j - 1] | sum[i - 1][j - 1];
          sum[i][j] = val[i];
        }
      }
    }
  }
  long long ans = inf;
  for(int i = a; i <= b; i++) {
    ans = min(ans, ret[n - 1][i] | sum[n - 1][i]);
  }
  cout << ans << endl;
  return 0;
}
