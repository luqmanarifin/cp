#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const long long INF = 1e17;

// hour, drinkcount, points, habisminum
long long dp[170][26][1694][2];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int hour, energy, sleep, dcount, drink, crash;
    scanf("%d %d %d %d %d %d", &hour, &energy, &sleep, &dcount, &drink, &crash);
    for(int i = 0; i < 170; i++) {
      for(int j = 0; j < 26; j++) {
        for(int k = 0; k < 1694; k++) {
          for(int l = 0; l < 2; l++) {
            dp[i][j][k][l] = -inf;
          }
        }
      }
    }
    dp[0][dcount][0][0] = energy;
    for(int i = 1; i <= hour; i++) {
      int req, point;
      scanf("%d %d", &req, &point);
      point /= 10;
      for(int j = 0; j <= dcount; j++) {
        for(int k = 0; k <= 1680; k++) {
          dp[i][j][k][0] = max(dp[i][j][k][0], dp[i-1][j][k][0] + sleep);
          dp[i][j][k][0] = max(dp[i][j][k][0], dp[i-1][j][k][1] + sleep - crash);
          
          if(k-point >= 0 && dp[i-1][j][k-point][0] >= req) {
            dp[i][j][k][0] = max(dp[i][j][k][0], dp[i-1][j][k-point][0] - req);
          }
          if(k-point >= 0 && dp[i-1][j][k-point][1] >= req) {
            dp[i][j][k][0] = max(dp[i][j][k][0], dp[i-1][j][k-point][1] - req - crash);
          }
          
          if(k-point >= 0 && dp[i-1][j+1][k-point][0] + drink >= req) {
            dp[i][j][k][1] = max(dp[i][j][k][1], dp[i-1][j+1][k-point][0] + drink - req);
          }
          if(k-point >= 0 && dp[i-1][j+1][k-point][1] + drink >= req) {
            dp[i][j][k][1] = max(dp[i][j][k][1], dp[i-1][j+1][k-point][1] + drink - req - crash);
          }
        }
      }
    }
    bool done = 0;
    for(int k = 1680; k >= 0; k--) {
      for(int j = 0; j <= dcount; j++) {
        for(int l = 0; l < 2; l++) {
          if(dp[hour][j][k][l] >= -INF) {
            done = 1;
            printf("%d\n", k * 10);
            goto NEXT;
          }
        }
      }
    }
    NEXT:;
    assert(done);
  }
  
  return 0;
}
