#include <bits/stdc++.h>

using namespace std;

set<int> num = {4, 6, 8, 10, 12, 20};

tuple<int, int, int> parse(string s) {
  int x = 0, y = 0, z = 0, now = 0;
  bool sign = 0; // 1 negatif
  for (int i = 0; i < s.size(); i++) {
    if (now == 0) {
      if (s[i] == 'd') {
        now++;
      } else {
        x = x * 10 + s[i] - '0';
      }
    } else if (now == 1) {
      if (s[i] == '+' || s[i] == '-') {
        now++;
        if (s[i] == '-') {
          sign = 1;
        }
      } else {
        y = y * 10 + s[i] - '0';
      }
    } else {
      z = z * 10 + s[i] - '0';
    }
  }
  if (sign) z *= -1;
  return make_tuple(x, y, z);
}

// dadu, banyak, value
double dp[25][25][405];

int main() {
  for (int n = 1; n <= 20; n++) {
    if (!num.count(n)) continue;
    dp[n][0][0] = 1;
    for (int i = 0; i <= 20; i++) {
      for (int j = 0; j < 405; j++) {
        for (int k = 1; j + k < 405 && k <= n; k++) {
          dp[n][i + 1][j + k] += dp[n][i][j] / n;
        }
      }
    }
  }
  
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    int h, s;
    cin >> h >> s;
    double ans = 0;
    while (s--) {
      string str;
      cin >> str;
      int x, y, z;
      tie(x, y, z) = parse(str);
      //printf("%d %d %d\n", x, y, z);
      
      double cur = 0;
      int til = max(0, h - z);
      for (int i = til; i < 405; i++) {
        cur += dp[y][x][i];
      }
      ans = max(ans, cur);
    }
    printf("Case #%d: %.15f\n", tt, ans);
  }
  
  return 0;
}
