#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int a[N];
int dp[N][N][2];

int find(int l, int r, int c) {
  if(dp[l][r][c] != -1) return dp[l][r][c];
  int& ret = dp[l][r][c] = 0;
  if(l >= r) return ret = 0;
  if(c == 1) {
    ret = find(l, r - 1, c);
    if(a[l] > a[r - 1]) {
      ret = max(ret, find(l, r - 1, c ^ 1) + 1);
    }
  } else {
    ret = find(l + 1, r, c);
    if(a[l + 1] < a[r]) {
      ret = max(ret, find(l + 1, r, c ^ 1) + 1);
    }
  }
  return ret;
}

int main() {
  memset(dp, -1, sizeof(dp));
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 1; i <= n; i++) {
    printf("%d ", max(find(i, n + 1, 1), find(0, i, 0)));
  }
  return 0;
}
