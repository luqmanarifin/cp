#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 1e5 + 5;

#define matrix vector<vector<long long>>

matrix P = {
  {1, 1, 0, 0, 0},
  {0, 1, 1, 0, 0},
  {0, 0, 1, 0, 0},
  {0, 0, 0, 1, 1},
  {0, 0, 0, 0, 1}
};

matrix A = {
  {1, 0, 0, 0, 0},
  {0, 1, 0, 0, 0},
  {0, 0, 1, 1, 0},
  {0, 0, 0, 1, 0},
  {0, 0, 0, 0, 1}
};

matrix mul(matrix& a, matrix& b) {
  int n = a.size();
  int m = b[0].size();
  int v = a[0].size();
  matrix ret(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < v; k++) {
        ret[i][j] += a[i][k] * b[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  return ret;
}

matrix identity(int n) {
  matrix ret(n, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    ret[i][i] = 1; 
  }
  return ret;
}

matrix power(matrix a, int b) {
  if (b == 0) return identity(a.size());
  matrix tmp = power(a, b / 2);
  tmp = mul(tmp, tmp);
  if (b & 1) {
    tmp = mul(tmp, a);
  }
  return tmp;
}

char s[N];

int main() {
  int k, n;
  scanf("%d %d %s", &k, &n, s);
  matrix trans = identity(5);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') {
      trans = mul(trans, P);
    } else {
      trans = mul(trans, A);
    }
  }
  trans = power(trans, k);
  matrix ans = {{1, 0, 0, 0, 0}};
  ans = mul(ans, trans);
  cout << ans[0][4] << endl;
  return 0;
}
