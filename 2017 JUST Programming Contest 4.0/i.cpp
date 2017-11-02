#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int last[N];
int dp[N];
int c[N];

int main() {
  int t;
  scanf("%d", &t);
  memset(last, -1, sizeof last);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", c+i);
    }
    dp[0] = 0;
    last[c[0]] = 0;
    for (int i = 1; i < n; i++) {
      dp[i] = dp[i-1]+1;
      if (last[c[i]] >= 0)
        dp[i] = min(dp[i], dp[last[c[i]]]+1);
      last[c[i]] = i;
    }
    printf("%d\n", dp[n-1]);
    for (int i = 0; i < n; i++)
      last[c[i]] = -1;
  }
  return 0;
}
