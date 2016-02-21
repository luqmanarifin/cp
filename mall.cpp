#include <bits/stdc++.h>

using namespace std;

const long long mod = (1LL << 31);
const int N = 3;

long long a[N][N], temp[N][N];
long long t[][3] = {
  {2, 3, 2},
  {3, 5, 3},
  {0, 0, 1}
};

void ttemp() {
  long long tmp[N][N];
  memset(tmp, 0, sizeof(tmp));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        tmp[i][j] += t[i][k] * temp[k][j];
        tmp[i][j] %= mod;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      temp[i][j] = tmp[i][j];
    }
  }
}

void temptemp() {
  long long tmp[N][N];
  memset(tmp, 0, sizeof(tmp));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        tmp[i][j] += temp[i][k] * temp[k][j];
        tmp[i][j] %= mod;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      temp[i][j] = tmp[i][j];
    }
  }
}

void atemp() {
  long long tmp[N][N];
  memset(tmp, 0, sizeof(tmp));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        tmp[i][j] += a[i][k] * temp[k][j];
        tmp[i][j] %= mod;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      a[i][j] = tmp[i][j];
    }
  }
}

void power(long long n) {
  if(n == 0) return;
  power(n / 2);
  temptemp();
  if(n % 2) {
    ttemp();
  }
}

long long solve(int u, int v, long long n) {
  a[0][0] = u;
  a[0][1] = v;
  a[0][2] = u;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      temp[i][j] = i == j;
    }
  }
  power(n);
  atemp();
  return a[0][2];
}

int main() {
  long long n;
  scanf("%lld", &n);
  long long p, q, r, s;
  p = q = r = s = 0;
  if(n >= 1) {
    p = solve(1, 1, (n - 1) / 4);
  }
  if(n >= 2) {
    q = solve(1, 2, (n - 2) / 4);
  }
  if(n >= 3) {
    r = solve(2, 3, (n - 3) / 4);
  }
  if(n >= 4) {
    s = solve(3, 5, (n - 4) / 4);
  }
  //printf("%I64d %I64d %I64d %I64d\n", p, q, r, s);
  cout << ((p - r)*(p - r) + (q - s)*(q - s)) % mod << endl;
  return 0;
}