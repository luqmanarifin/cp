#include <bits/stdc++.h>

using namespace std;

const int N = 4;
const long long mod = 1e9 + 7;

long long t[N][N], temp[N][N];
long long a[N];

void ttemp() {
  long long ret[N][N];
  memset(ret, 0, sizeof(ret));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        ret[i][j] += (t[i][k] * temp[k][j]) % mod;
      }
      ret[i][j] %= mod;
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      temp[i][j] = ret[i][j];
    }
  }
}

void temptemp() {
  long long ret[N][N];
  memset(ret, 0, sizeof(ret));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        ret[i][j] += (temp[i][k] * temp[k][j]) % mod;
      }
      ret[i][j] %= mod;
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      temp[i][j] = ret[i][j];
    }
  }
}

void atemp() {
  long long ret[N];
  memset(ret, 0, sizeof(ret));
  for(int j = 0; j < N; j++) {
    for(int k = 0; k < N; k++) {
      ret[j] += (a[k] * temp[k][j]) % mod;
    }
    ret[j] %= mod;
  }
  for(int j = 0; j < N; j++) {
    a[j] = ret[j];
  }
}

void power(int n) {
  if(n == 0) return;
  power(n / 2);
  temptemp();
  if(n & 1) {
    ttemp();
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      t[i][j] = (i != j);
      temp[i][j] = (i == j);
    }
    a[i] = !i;
  }
  power(n);
  atemp();
  cout << a[0] << endl;
  return 0;
}
