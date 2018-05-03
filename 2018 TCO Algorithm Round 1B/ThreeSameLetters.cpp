#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 30;

long long dp[N][N][N][N][2];

void add(long long& at, long long val) {
  at += val;
  if (at >= mod) at -= mod;
}

class ThreeSameLetters {
public:
  int countStrings(int n, int s) {
    if (n < 3) return 0;
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        for (int k = 0; k < s; k++) {
          if (i == j && j == k) {
            dp[3][i][j][k][1] = 1;
          } else {
            dp[3][i][j][k][0] = 1;
          }
        }
      }
    }
    for (int p = 3; p < n; p++) {
      for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
          for (int k = 0; k < s; k++) {
            for (int l = 0; l < s; l++) {
              bool same = (j == k && k == l);
              if (same) {
                add(dp[p + 1][j][k][l][1], dp[p][i][j][k][0]);
              } else {
                add(dp[p + 1][j][k][l][0], dp[p][i][j][k][0]);
                add(dp[p + 1][j][k][l][1], dp[p][i][j][k][1]);
              }
            }
          }
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        for (int k = 0; k < s; k++) {
          add(ans, dp[n][i][j][k][1]);
        }
      }
    }
    return ans;
  }
};

// int main() {
//   int l = 0;
//   int r = 0;

//   ThreeSameLetters ThreeSameLetters;
//   cout << ThreeSameLetters.countStrings(3, 7) << endl;

//   return 0;
// }
