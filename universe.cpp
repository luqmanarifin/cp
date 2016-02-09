#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int s[N], n, a, b;
int dp[N];

int find(int i) {
  if(i >= n) return 0;
  if(s[i] < a || b < s[i]) return 0;
  if(dp[i] != -1) return dp[i];
  return dp[i] = 1 + find(i + s[i]);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d %d %d", &n, &a, &b);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
      scanf("%d", s + i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      ans = max(ans, find(i));
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
