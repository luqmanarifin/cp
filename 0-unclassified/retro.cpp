#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000009;
const int N = 25;

long long t[N][N], temp[N][N], a[N];
int n, ck[N];

void ttemp() {
  long long ret[N][N];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      ret[i][j] = 0;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        ret[i][j] += t[i][k] * temp[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      temp[i][j] = ret[i][j];
    }
  }
}

void temptemp() {
  long long ret[N][N];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      ret[i][j] = 0;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        ret[i][j] += temp[i][k] * temp[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      temp[i][j] = ret[i][j];
    }
  }
}

void atemp() {
  long long ret[N];
  for(int i = 0; i < n; i++) {
    ret[i] = 0;
  }
  for(int j = 0; j < n; j++) {
    for(int k = 0; k < n; k++) {
      ret[j] += a[k] * temp[k][j];
      ret[j] %= mod;
    }
  }
  for(int i = 0; i < n; i++) {
    a[i] = ret[i];
  }
}

void power(long long k) {
  if(k == 0) return;
  power(k / 2);
  temptemp();
  if(k & 1) ttemp();
}

int main() {
  int c;
  long long m;
  scanf("%d %I64d %d", &n, &m, &c);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
  }
  for(int i = 0; i < c; i++) {
    scanf("%d", ck + i);
  }
  if(m <= n) {
    printf("%I64d\n", a[m - 1]);
    return 0;
  }
  for(int i = 0; i < n - 1; i++) {
    t[i + 1][i] = 1;
  }
  for(int i = 0; i < c; i++) {
    t[n - ck[i]][n - 1]++;
  }
  for(int i = 0; i < n; i++) {
    temp[i][i] = 1;
  }
  /*
  puts("T");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", t[i][j]);
    }
    printf("\n");
  }
  puts("TEMP");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", temp[i][j]);
    }
    printf("\n");
  }
  */
  power(m - n);
  atemp();
  printf("%I64d\n", a[n - 1]);
  return 0;
}
