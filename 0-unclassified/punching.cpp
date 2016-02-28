#include <bits/stdc++.h>

using namespace std;

const int mod = 997;
const int N = 2e6 + 5;

int comb[mod][mod];
int n, m;

int c(int n, int k) {
  return n == 0? 1 : comb[n%mod][k%mod] * c(n/mod, k/mod) % mod;
}

int find(int x, int y) {
  return c(x + y, x);
}

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

int main() {
  for(int i = 0; i < mod; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) {
        comb[i][j] = 1;
      } else {
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int k;
    scanf("%d %d %d", &n, &m, &k);
    vector<pair<int, int>> num;
    for(int i = 0; i < k; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      for(int x = -1; x <= 1; x++) {
        for(int y = -1; y <= 1; y++) {
          if(valid(a + x, b + y)) {
            num.emplace_back(a + x, b + y);
          }
        }
      }
    }
    sort(num.begin(), num.end());
    num.emplace_back(n, m);
    vector<int> dp(num.size());
    for(int i = 0; i < num.size(); i++) {
      dp[i] = find(num[i].first - 1, num[i].second - 1);
      for(int j = 0; j < i; j++) {
        if(num[j].first <= num[i].first && num[j].second <= num[i].second) {
          dp[i] -= dp[j] * find(num[i].first - num[j].first, num[i].second - num[j].second);
          dp[i] %= mod;
          if(dp[i] < 0) dp[i] += mod;
        }
      }
      //printf("%d %d %d\n", num[i].first, num[i].second, dp[i]);
    }
    printf("Case #%d: %d\n", tt, dp.back());
  }
  
  return 0;
}
