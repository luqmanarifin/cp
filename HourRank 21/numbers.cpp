#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;
const int N = 1e5 + 5;

#define matrix vector<vector<long long> > 

int m;
int dp[N][15];

matrix one(int n) {
  matrix ret(n, vector<long long>(n));
  for (int i = 0; i < n; i++) ret[i][i] = 1;
  return ret;
}

matrix mul(matrix a, matrix b) {
  matrix ret(a.size(), vector<long long>(b[0].size()));
  assert(a[0].size() == b.size());
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < a[0].size(); k++) {
        ret[i][j] += a[i][k] * b[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  return ret;
}

matrix power(matrix a, long long b) {
  if (b == 0) return one(a.size());
  matrix tmp = power(a, b / 2);
  tmp = mul(tmp, tmp);
  if (b & 1) {
    tmp = mul(tmp, a);
  }
  return tmp;
}

int main() {
  long long s;
  int d;
  scanf("%lld %d %d", &s, &m, &d);
  for (int i = 1; i <= m; i++) dp[i][i] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = max(1, j - d); k <= min(m, j + d); k++) {
        if (i - j >= 0) {
          dp[i][j] += dp[i - j][k];
          dp[i][j] %= mod;
        }
      }
    }
  }
  
  matrix a(1, vector<long long>(m * m));
  matrix t(m * m, vector<long long>(m * m));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      a[0][(i - 1) * m + j - 1] = dp[i][j];
    }
  }
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < m; j++) {
      int now = i * m + j;
      t[now + m][now] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    int cur = m * (m - 1) + i;
    for (int j = max(0, i - d); j <= min(m - 1, i + d); j++) {
      int pi = m - 1 - i;
      int pj = j;
      int now = pi * m + pj;
      t[now][cur] = 1;
    }
  }
  t = power(t, s - 1);
  matrix ans = mul(a, t);
  long long ret = 0;
  for (int i = 0; i < m; i++) ret += ans[0][i];
  cout << ret % mod << endl;
  return 0;
}
