#include <bits/stdc++.h>

using namespace std;

long long dp[105];
int a[105];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    int now = 0;
    for(int j = i; j >= 1; j--) {
      now += a[j];
      if(now > 1) break;
      if(now == 1) {
        dp[i] += dp[j - 1];
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}
