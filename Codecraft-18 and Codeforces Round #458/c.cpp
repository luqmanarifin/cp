#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long mod = 1e9 + 7;

char s[N];
int dp[N][N][2];    // posisi, banyak, 0 strict / 1 bebas
bool ada[N][N];     // transformasi, angka
vector<int> to[N];

void add(int& at, int val) {
  at += val;
  if (at >= mod) at -= mod;
}

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  int k;
  scanf("%d", &k);
  
  if (k == 0) {
    puts("1");
    return 0;
  }
  for (int i = 2; i <= 1000; i++) {
    to[__builtin_popcount(i)].push_back(i);
  }
  ada[0][1] = 1;
  for (int i = 0; i <= k - 2; i++) {
    for (int j = 0; j < 15; j++) {
      for (auto it : to[j]) {
        ada[i + 1][it] |= ada[i][j];
      }
    }
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < N; j++) {
      if (s[i + 1] == '0') {
        add(dp[i+1][j][0], dp[i][j][0]);
        add(dp[i+1][j][1], dp[i][j][1]);
        add(dp[i+1][j+1][1], dp[i][j][1]);
      } else {
        add(dp[i+1][j][1], dp[i][j][0]);
        add(dp[i+1][j+1][0], dp[i][j][0]);
        add(dp[i+1][j][1], dp[i][j][1]);
        add(dp[i+1][j+1][1], dp[i][j][1]);
      }
    }
  }
  if (n == 1) {
    dp[n][1][0]--;
  } else {
    dp[n][1][1]--;
  }
  long long ans = 0;
  for (int j = 0; j < N; j++) {
    if (ada[k-1][j]) {
      //printf("ada %d\n", j);
      ans += dp[n][j][0] + dp[n][j][1];
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
