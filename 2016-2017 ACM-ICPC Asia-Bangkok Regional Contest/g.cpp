#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

struct matrix {
  matrix() : n(2) {
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].assign(n, 0);
    }
  }
  matrix(int n) : n(n) { 
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].assign(n, 0);
    }
  }
  matrix(const matrix& m) : n(m.n) {
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].assign(n, 0);
    }
  }
  matrix operator=(const matrix& m) {
    n = m.n;
    this->a.resize(n);
    for (int i = 0; i < n; i++) {
      this->a[i].assign(n, 0);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        this->a[i][j] = m.a[i][j];
      }
    }
    return *this;
  }
  matrix operator*(const matrix& m) {
    matrix ret(m.n);
    for (int k = 0; k < m.n; k++) {
      for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
          ret.a[i][j] += a[i][k] * m.a[k][j];
          ret.a[i][j] %= mod;
        }
      }
    }
    return ret;
  }
  vector<vector<long long>> a;
  int n;
};

matrix power(matrix& m, long long b) {
    //printf("pangkat %d\n", b);
    //for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%I64d ", m.a[i][j]); printf("\n"); }
  
  matrix ret(m.n);
  if (b == 0) {
    for (int i = 0; i < m.n; i++) {
      ret.a[i][i] = 1;
    }
    //printf("base %d\n", m.n);
    //for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%I64d ", ret.a[i][j]); printf("\n"); }
    return ret;
  }
  ret = power(m, b / 2);
  //printf("bef %d\n", b);
  //for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%I64d ", ret.a[i][j]); printf("\n"); }
  ret = ret * ret;
  //printf("sendiri %d\n", b);
  //for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%I64d ", ret.a[i][j]); printf("\n"); }
  if (b & 1) {
    ret = ret * m;
  }
  //printf("hehe %d\n", b);
  //for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%I64d ", ret.a[i][j]); printf("\n"); }
  return ret;
}

long long get_fibo(long long n) {
  if (n < 0) return 1;
  matrix m(2);
  m.a[0][0] = 1;
  m.a[1][0] = 1;
  m.a[0][1] = 1;
  //puts("LOL");
  //for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%I64d ", m.a[i][j]); printf("\n"); }
  matrix ret = power(m, n + 1);
  //for (int i = 0; i < 2; i++) { for (int j = 0; j < 2; j++) printf("%I64d ", ret.a[i][j]); printf("\n"); }
  return ret.a[0][0];
}

long long find(long long n, int k) {
  if (k == 1) return get_fibo(n + 2) - 2;
  matrix a(3);
  a.a[0][0] = 1;
  a.a[0][1] = 2;
  a.a[0][2] = 1;
  matrix b(3);
  long long f3 = get_fibo(k - 3);
  long long f2 = get_fibo(k - 2);
  long long f1 = get_fibo(k - 1);
  b.a[0][0] = f3;
  b.a[1][0] = f2;
  b.a[2][0] = 0;
  b.a[0][1] = f2;
  b.a[1][1] = f1;
  b.a[2][1] = 0;
  b.a[0][2] = f3;
  b.a[1][2] = f2;
  b.a[2][2] = 1;
  long long p = n / k;
  b = power(b, p);
  a = a * b;
  return a.a[0][2];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    long long l, r, k;
    scanf("%I64d %I64d %I64d", &l, &r, &k);
    long long ans = find(r, k) - find(l - 1, k);
    ans %= mod;
    if (ans < 0) ans += mod;
    printf("Case %d: %I64d\n", tt, ans);
  }

  return 0;
}
