#include <bits/stdc++.h>

using namespace std;

const int N = 128;

struct matriks {
  matriks() {
    memset(a, 0, sizeof(a));
  }
  matriks(int n) {
    for (int i = 0; i < N; i++) {
      a[i][i] = 1;
    }
  }
  matriks(const matriks& m) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        a[i][j] = m.a[i][j];
      }
    }
  }
  void operator= (const matriks& m) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        a[i][j] = m.a[i][j];
      }
    }
  }
  matriks operator* (const matriks& m) {
    matriks ret;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          ret.a[i][j] += this->a[i][k] * m.a[k][j];
        }
      }      
    }
    return ret;
  }
  double a[N][N];
};

matriks power(matriks a, int b) {
  if (b == 0) { 
    matriks ret(1);
    return ret;
  }
  matriks temp = power(a, b / 2);
  temp = temp * temp;
  if (b & 1) temp = temp * a;
  return temp;
}

double f[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= k; i++) scanf("%lf", f + i);
  matriks a;
  matriks t;
  a.a[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      t.a[i][j] = f[i ^ j];
    }
  }
  matriks ret = power(t, n);
  a = a * ret;
  double ans = 0;
  for (int i = 1; i < N; i++) ans += a.a[0][i];
  printf("%.15f\n", ans);
  return 0;
}
