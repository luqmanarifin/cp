#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long inf = 1e18;

int a[3], tot;
long long dp[N];

long long solve(long long n) {
  if(n == 1) return 0;
  if(n < 1) return -inf;
  if(n < N) {
    if(dp[n] != -1) return dp[n];
    dp[n] = inf;
    for(int i = 0; i < n; i++) {
      for(int j = 0; i + j <= n; j++) {
        long long cur = max(solve(i) + a[0], max(solve(j) + a[1], solve(n - i - j) + a[2]));
        dp[n] = min(dp[n], cur);
      }
    }
    return dp[n];
  }
  vector<double> frac = {
    1. * (a[1] * a[2]) * n / tot,
    1. * (a[0] * a[2]) * n / tot,
    1. * (a[0] * a[1]) * n / tot
  };
  long long rem = n;
  vector<long long> nk;
  nk.resize(3);
  for(int i = 0; i < 3; i++) {
    nk[i] = (long long) frac[i];
    rem -= nk[i];
  }
  if(rem == 1) {
    double best = 2.0;
    int at = -1;
    for(int i = 0; i < 3; i++) {
      nk[i]++;
      double maxi = -2.0;
      for(int k = 0; k < 3; k++) {
        maxi = max(maxi, (nk[k] - frac[k]) / frac[k]);
      }
      if(maxi < best) {
        best = maxi;
        at = i;
      }
      nk[i]--;
    }
    nk[at]++;
  } else if(rem == 2) {
    
    double best = 2.0;
    int ai = -1, aj = -1;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        nk[i]++; nk[j]++;
        double maxi = -2.0;
        for(int k = 0; k < 3; k++) {
          maxi = max(maxi, (nk[k] - frac[k]) / frac[k]);
        }
        if(maxi < best) {
          best = maxi;
          ai = i;
          aj = j;
        }
        nk[i]--; nk[j]--;
      }
    }
    nk[ai]++; nk[aj]++;
  } else {
    assert(rem == 0);
  }
  assert(nk[0] + nk[1] + nk[2] == n);
  
  double maxi = -2.0;
  int at = -1;
  for(int i = 0; i < 3; i++) {
    double cur = (nk[i] - frac[i]) / frac[i];
    if(cur > maxi) {
      maxi = cur;
      at = i;
    } 
  }
  assert(n != nk[at]);
  return solve(nk[at]) + a[at];
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(dp, -1, sizeof(dp));
    long long n;
    scanf("%lld %d %d %d", &n, &a[0], &a[1], &a[2]);
    tot = a[0] * a[1] + a[1] * a[2] + a[0] * a[2];
    printf("%lld\n", solve(n));
  }
  return 0;
}
