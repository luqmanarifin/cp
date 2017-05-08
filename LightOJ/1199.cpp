#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int dp[N];

int main() {
  dp[1] = dp[2] = 0;
  for (int i = 3; i < N; i++) {
    set<int> s;
    for (int j = 1; j < (i + 1) / 2; j++) {
      s.insert(dp[j] ^ dp[i - j]);
    }
    for (int j = 0; j < N; j++) {
      if (!s.count(j)) {
        dp[i] = j;
        break;
      }
    }
  }
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      ans ^= dp[v];
    }
    printf("Case %d: ", tt);
    if (ans) {
      puts("Alice");
    } else {
      puts("Bob");
    }
  }
  return 0;
}
