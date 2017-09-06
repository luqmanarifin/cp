#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N], got[N];
int dp[N][55], n;

int find(int i, int j) {
  if (i == n) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = a[i] + find(i + 1, min(50, j + got[i]));
  int diskon = min(a[i], j);
  ans = min(ans, a[i] - diskon + find(i + 1, j - diskon));
  return dp[i][j] = ans;
}

int main() {
  scanf("%d", &n);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] /= 100;
    got[i] = a[i] / 10;
  }
  memset(dp, -1, sizeof(dp));
  cout << find(0, 0) * 100 << endl;
  return 0;
}