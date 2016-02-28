#include <bits/stdc++.h>

using namespace std;

const int kim = 1e5 + 5;
const int cil = 105;

int dua[cil][cil];
int tri[cil][cil][cil];

int dp[kim], d[kim], n;
int a[cil];

int find(int i) {
  if(dp[i] != -1) return dp[i];
  int& ret = dp[i];
  ret = find(i + 1) + 3;
  if(i + 1 < n && dua[d[i]][d[i + 1]]) {
    ret = min(ret, find(i + 2) + 2);
  }
  if(i + 2 < n && tri[d[i]][d[i + 1]][d[i + 2]]) {
    ret = min(ret, find(i + 3) + 1);
  }
  if(i + 3 < n) {
    bool good = 1;
    for(int j = 1; j < 4; j++) {
      if(!(d[i + j - 1] < d[i + j] && abs(d[i + j - 1] - d[i + j]) <= 10)) {
        good = 0;
        break;
      }
    }
    if(good) {
      ret = min(ret, find(i + 4));
    }
  }
  return ret;
}

int main() {
  for(int i = 1; i <= 100; i++) {
    for(int j = i + 1; j <= 100; j++) {
      for(int k = 1; k <= 100; k++) {
        if(k == i || k == j) continue;
        for(int l = 1; l <= 100; l++) {
          if(l == i || l == j || l == k) continue;
          a[0] = i; a[1] = j; a[2] = k; a[3] = l;
          sort(a, a + 4);
          bool good = 1;
          for(int t = 1; t < 4; t++) {
            if(a[t] - a[t - 1] > 10) {
              good = 0;
              break;
            }
          }
          if(good) {
            dua[i][j] = 1;
            goto CONT;
          }
        }
      }
      CONT:;
    }
  }
  for(int i = 1; i <= 100; i++) {
    for(int j = i + 1; j <= 100; j++) {
      for(int k = j + 1; k <= 100; k++) {
        for(int l = 1; l <= 100; l++) {
          if(l == i || l == j || l == k) continue;
          a[0] = i; a[1] = j; a[2] = k; a[3] = l;
          sort(a, a + 4);
          bool good = 1;
          for(int t = 1; t < 4; t++) {
            if(a[t] - a[t - 1] > 10) {
              good = 0;
              break;
            }
          }
          if(good) {
            tri[i][j][k] = 1;
            goto CUNT;
          }
        }
        CUNT:;
      }
    }
  }
  cerr << "Ready" << endl;
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", d + i);
    }
    dp[n] = 0;
    printf("Case #%d: %d\n", tt, find(0));
    cerr << tt << " done!" << endl;
  }
  return 0;
}
