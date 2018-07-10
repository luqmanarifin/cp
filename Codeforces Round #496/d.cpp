#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;

int dp[N][3];
char s[N];

void upd(int& at, int val) {
  at = max(at, val);
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = -inf;
    }
  }
  dp[0][0] = -1;
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      // mau lanjutin sebelumnya
      if (s[i - 1] != '0') {
        upd(dp[i][(j+s[i]-'0')%3], dp[i-1][j]);
      }

      // bikin baru
      upd(dp[i][(s[i]-'0')%3], dp[i-1][j] + (j == 0));
    }
  }
  int ans = -inf;
  dp[n][0]++;
  for (int i = 0; i < 3; i++) upd(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
