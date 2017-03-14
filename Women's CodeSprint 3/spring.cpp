#include <bits/stdc++.h>

using namespace std;

const int N = 65;
const int BIG = 2e5 + 5;
const long long mod = 1e9 + 7;

// rb - rg - br - bg - gr - gb
// rbg
long long dp[2][11][11][11][11][11][11][3];
long long fact[BIG], ifact[BIG];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) temp = temp * a % mod;
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

long long get(int benda, int karung) {
  return c(benda + karung - 1, benda);
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < BIG; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  int n, rb, rg, br, bg, gr, gb;
  scanf("%d %d %d %d %d %d %d", &n, &rb, &rg, &br, &bg, &gr, &gb);
  
  for (int i = 0; i < 3; i++) dp[1][0][0][0][0][0][0][i] = 1;
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    int s = i % 2;
    int cur = 0;
    for (int a = 0; a <= rb; a++) {
      for (int b = 0; b <= rg; b++) {
        for (int c = 0; c <= br; c++) {
          for (int d = 0; d <= bg; d++) {
            for (int e = 0; e <= gr; e++) {
              for (int f = 0; f <= gb; f++) {
                for (int j = 0; j < 3; j++) {
                  long long& now = dp[s][a][b][c][d][e][f][j];
                  now %= mod;
                  cur += now;
                  if (cur >= mod) cur -= mod;
                }
                long long red = dp[s][a][b][c][d][e][f][0];
                long long blue = dp[s][a][b][c][d][e][f][1];
                long long green = dp[s][a][b][c][d][e][f][2];
                for (int j = 0; j < 3; j++) dp[s][a][b][c][d][e][f][j] = 0;
                if (a + 1 <= 10) dp[s^1][a+1][b][c][d][e][f][1] += red;
                if (b + 1 <= 10) dp[s^1][a][b+1][c][d][e][f][2] += red;
                if (c + 1 <= 10) dp[s^1][a][b][c+1][d][e][f][0] += blue;
                if (d + 1 <= 10) dp[s^1][a][b][c][d+1][e][f][2] += blue;
                if (e + 1 <= 10) dp[s^1][a][b][c][d][e+1][f][0] += green;
                if (f + 1 <= 10) dp[s^1][a][b][c][d][e][f+1][1] += green;
              }
            }
          }
        }
      }
    }
    ans += cur * get(n - i, i);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
