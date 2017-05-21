#include <bits/stdc++.h>

using namespace std;

#define matrix vector<vector<long long>>

long long mod;

matrix trans = {
  {0, 1, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1}
};

matrix one(int n, int m) {
  matrix ret(n, vector<long long>(m, 0));
  for (int i = 0; i < min(n, m); i++) ret[i][i] = 1;
  return ret;
}

matrix mul(matrix a, matrix b) {
  assert(a[0].size() == b.size());
  matrix ret(a.size(), vector<long long>(b[0].size(), 0));
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

matrix power(matrix m, int b) {
  if (b == 0) return one(m.size(), m[0].size());
  matrix tmp = power(m, b / 2);
  tmp = mul(tmp, tmp);
  if (b & 1) tmp = mul(tmp, m);
  return tmp;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d %lld", &n, &mod);
    matrix a(1, vector<long long>(4, 0));
    a[0][1] = a[0][2] = a[0][3] = 1;
    matrix t = trans;
    printf("%lld\n", mul(a, power(t, n))[0][0]);
  }

  return 0;
}
