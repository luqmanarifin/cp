#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long dp[205][205][205];
int a[205], b[205];

int main() {
  int n, p, q;
  scanf("%d %d %d", &n, &p, &q);
  for(int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    a[i] = s[0] - 'a';
  }
  for(int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    b[i] = s[0] - 'a';
  }
  dp[0][0][0] = 1;
  for(int i = 1; i <= n; i++) {
    char s[10];
    scanf("%s", s);
    for(int j = 0; j < 5; j++) {
      if(s[j] != '.') {
        for(int x = 0; x <= i; x++) {
          for(int y = 0; y <= i; y++) {
            int lef = x - (j == a[i]);
            int rig = y - (j == b[i]);
            if(0 <= lef && 0 <= rig) {
              dp[i][x][y] += dp[i - 1][lef][rig];
              dp[i][x][y] %= mod;
            }
          }
        }
      }
    }
  }
  cout << dp[n][p][q] << endl;
  return 0;
}
