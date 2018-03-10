#include <bits/stdc++.h>

using namespace std;

// S, N
// C - V
// C - V
// C - V

const int N = 2005;

int dp[N][N];    
// state 1. berapa yg udah diconsider
// state 2. kapasitas berapa yg bisa diambil
// berapa value maksimum yg bisa kita dapet

// dp berapa value maksimum dengan consider i barang pertama, dan kapasitas maksimum j

int c[N], v[N];

int main() {
  int s, n;
  scanf("%d %d", &s, &n);
  for (int i = 0; i < n; i++) scanf("%d %d", c + i, v + i);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -1e9;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {         // iterasi barang
    // consider barang i
    for (int j = 0; j <= s; j++) {       // iterasi kapasitas
      // dp[i][j] - dengan ngeconsider i barang, kapasitas maksimum j
      
      // nggak ngambil
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      
      // ambil barang
      if (j+c[i] < N) {
        dp[i+1][j+c[i]] = max(dp[i+1][j+c[i]], dp[i][j] + v[i]);
      }
    }
  }
  int ans = -1e9;
  for (int i = 0; i <= s; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}
