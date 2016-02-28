#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const double inf = 1e18;

double got[N][N];
double a[N];
double pa[N], pb[N];
double dp[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        got[i][j] = 0;
      }
      a[i] = 0;
    }
    
    int n, k;
    double p;
    scanf("%d %d %lf", &n, &k, &p);
    //cerr << n << k << p << endl;
    pa[0] = pb[0] = 1;
    for(int i = 1; i < N; i++) {
      pa[i] = pa[i - 1] * p;
      pb[i] = pb[i - 1] * (1 - p);
    }
    
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= i; j++) {
        if(j == 0) {
          got[i][j] = pb[i];
        } else if(j == i) {
          got[i][j] = pa[i];
        } else {
          got[i][j] = got[i-1][j-1] * i / j * p;
        }
        //printf("got %d %d : %.15f\n", i, j, got[i][j]);
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = k; j <= i; j++) {
        a[i] += got[i][j];
      }
      //printf("a %d : %.15f\n", i, a[i]);
    }
    for(int i = 1; i <= n; i++) {
      dp[i] = -inf;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= i; j++) {
        dp[i] = max(dp[i], dp[i - j] + a[j]);
      }
    }
    printf("Case #%d: %.15f\n", tt, dp[n]);
    cerr << tt << " done!" << endl;
  }
  
  return 0;
}
