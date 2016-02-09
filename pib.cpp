#include <bits/stdc++.h>

using namespace std;

const long long mod = 1111111111;

const int N = 110;

int size, n, d;
long long a[N], t[N][N], tmp[N][N];
long long comb[N][N];

void ttmp() {
  long long temp[size][size];
  memset(temp, 0, sizeof(temp));
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      for(int k = 0; k < size; k++) {
        temp[i][j] += t[i][k] * tmp[k][j];
        temp[i][j] %= mod;
      }
    }
  }
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      tmp[i][j] = temp[i][j];
    }
  }
}

void tmptmp() {
  long long temp[size][size];
  memset(temp, 0, sizeof(temp));
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      for(int k = 0; k < size; k++) {
        temp[i][j] += tmp[i][k] * tmp[k][j];
        temp[i][j] %= mod;
      }
    }
  }
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      tmp[i][j] = temp[i][j];
    }
  }
}

void atmp() {
  long long temp[size];
  memset(temp, 0, sizeof(temp));
  for(int j = 0; j < size; j++) {
    for(int k = 0; k < size; k++) {
      temp[j] += a[k] * tmp[k][j];
      temp[j] %= mod;
    }
  }
  for(int j = 0; j < size; j++) {
    a[j] = temp[j];
  }
}

int c[105];

void power(int k) {
  if(k == 0) return;
  power(k / 2);
  tmptmp();
  if(k & 1) {
    ttmp();
  }
}

int get(int n) {
  if(n <= 1) return 1;
  memset(a, 0, sizeof(a));
  memset(t, 0, sizeof(t));
  memset(tmp, 0, sizeof(tmp));
  a[size - 1] = a[size - 2] = a[size - 3] = 1;
  for(int i = size - 4; i >= 0; i--) {
    a[i] = a[i + 1] * 2 % mod;
  }
  for(int i = 0; i < size; i++) {
    tmp[i][i] = 1;
  }
  for(int j = 0; j <= d; j++) {
    for(int i = j; i <= d; i++) {
      t[i][j] = comb[d - j][i - j];
    }
  }
  for(int i = 0; i < size; i++) {
    t[i][size - 2] = (i == size - 1);
  }
  t[size - 1][size - 1] = t[size - 2][size - 1] = 1;
  for(int i = 0; i <= d; i++) {
    t[i][size - 1] = c[d - i];
  }
  
  power(n - 1);
  atmp();
  return a[size - 1];
}

int main() {
  comb[0][0] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) {
        comb[i][j] = 1;
      } else {
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
      }
    }
  }
  
  scanf("%d %d", &n, &d);
  size = d + 3;
  for(int i = 0; i <= d; i++) {
    scanf("%d", c + i);
  }
  cout << get(n) << endl;
  return 0;
}
