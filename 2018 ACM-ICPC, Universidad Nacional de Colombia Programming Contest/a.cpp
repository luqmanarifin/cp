#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

typedef vector<vector<long long>> matrix;

matrix one(int n) {
  matrix ret(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) ret[i][i] = 1;
  return ret;
}

matrix zero(int n) {
  matrix ret(n, vector<long long>(n, 0));
  return ret;
}

matrix mul(matrix a, matrix b) {
  matrix ret(a.size(), vector<long long>(b[0].size(), 0));
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
  matrix ret = power(a, b / 2);
  ret = mul(ret, ret);
  if (b & 1) {
    ret = mul(ret, a);
  }
  return ret;
}

long long get(long long year) {
  long long n = year / 10;
  matrix a = {
    {1, 0, 0, 0, 0, 1}
  };
  matrix b = {
    {16, 1, 0, 0, 0, 16},
    {9, 0, 1, 0, 0, 9},
    {4, 0, 0, 1, 0, 4},
    {1, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1}
  };
  return mul(a, power(b, n))[0][5];
}

int main() {
  long long n;
  cin >> n;
  long long ans = get(n);
  if (n >= 45) ans -= get(n - 45);
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
