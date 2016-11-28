#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

long long fact[N], ifact[N];

long long power(long long a, int b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if (b & 1) {
    temp = temp * a % mod;
  }  
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long c(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  long long temp = fact[n] * ifact[k] % mod;
  temp = temp * ifact[n - k] % mod;
  return temp;
}

long long dp[2005][40];

main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }
  //cout << c(5, 3) << endl;
  
  int n, m, k, s;
  scanf("%I64d %I64d %I64d %I64d", &n, &m, &k, &s);
  int oris = s;
  int til = 0;
  while (s > 1) {
    til++;
    s = (s + 1) / 2;
  }
  vector<pair<int, int>> p;
  int offset = 0;
  for (int i = 0; i < k; i++) {
    int u, v;
    scanf("%I64d %I64d", &u, &v);
    if ((u == 1 && v == 1) || (u == n && v == m)) {
      offset++;
    } else {
      p.emplace_back(u, v); 
    }
  }
  til = max(0LL, til - offset);
  //til = 24;
  sort(p.begin(), p.end());
  
  for (int i = 0; i < p.size(); i++) {
    long long bef = 0;
    for (int j = 1; j <= til; j++) {
      long long same = 0;
      for (int k = 0; k < i; k++) {
        if (p[k].first <= p[i].first && p[k].second <= p[i].second) {
          int dx = p[i].first - p[k].first;
          int dy = p[i].second - p[k].second;
          same += dp[k][j] * c(dx + dy, dx);
          same %= mod;
        }
      }
      dp[i][j] = c(p[i].first + p[i].second - 2, p[i].first - 1) - bef - same;
      dp[i][j] %= mod;
      if (dp[i][j] < 0) dp[i][j] += mod;
      
      //printf("%I64d %I64d: %I64d\n", i, j, dp[i][j]);
      
      bef += dp[i][j];
      bef %= mod;
    }
  }
  long long ans[40] = {};
  long long bef = 0;
  for (int j = 0; j <= til; j++) {
    long long same = 0;
    for (int k = 0; k < p.size(); k++) {
      int dx = n - p[k].first;
      int dy = m - p[k].second;
      same += dp[k][j+1] * c(dx + dy, dx);
      same %= mod;
    }
    ans[j] = c(n + m - 2, n - 1) - bef - same;
    ans[j] %= mod;
    if (ans[j] < 0) ans[j] += mod;
    
    bef += ans[j];
    bef %= mod;
  }
  long long num = 0, now = oris;
  while (offset--) now = (now + 1) / 2;
  //printf("itil %I64d\n", til);
  for (int i = 0; i <= til; i++) {
    //printf("%I64d ada %I64d\n", i, ans[i]);
    num += ans[i] * now;
    num %= mod;
    //printf("%I64d: %I64d\n", i, now);
    //if (i < til) assert(now != 1);
    //if (i == til) assert(now == 1);
    now = (now + 1) / 2;
  }
  //printf("tot %I64d\n", num);
  num = num * inv(c(n + m - 2, n - 1)) % mod;
  cout << num << endl;
  return 0;
}
