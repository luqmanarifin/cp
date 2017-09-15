#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long mod = 1e9 + 7;

#define matrix vector<vector<long long>>

matrix satu(int n) {
  matrix ret(n, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    ret[i][i] = 1;
  }
  return ret;
}

matrix mul(matrix a, matrix b) {
  matrix ret(a.size(), vector<long long>(b[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        ret[i][j] += a[i][k] * b[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  return ret;
}

matrix power(matrix a, long long b) {
  if (b == 0) return satu(a.size());
  matrix ret = power(a, b / 2);
  ret = mul(ret, ret);
  if (b & 1) {
    ret = mul(ret, a);
  }
  return ret;
}

long long a[N], k;

int main() {
  int n;
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  matrix t(n, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (__builtin_popcountll(a[i] ^ a[j]) == 3) {
        t[i][j] = 1;
      }
    }
  }
  matrix s(1, vector<long long>(n, 1));
  s = mul(s, power(t, k - 1));
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += s[0][i];
  cout << ans % mod << endl;

  return 0;
}
