#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 1e5 + 5;

void norm(long long &will) {
  will %= mod;
  if(will < 0) will += mod;
}

long long awal[N];
long long at[N];
long long f[N], a, b;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  scanf("%I64d %I64d %I64d %I64d", &f[1], &f[2], &a, &b);
  for(int i = 3; i < N; i++) {
    f[i] = a * f[i - 2] + b * f[i - 1];
    f[i] %= mod;
  }
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", &awal[i]);
  }
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    if(l == r) {
      at[l] += f[1];
      at[l + 1] += -b * f[1];
      at[l + 2] += -a * f[1];
      norm(at[l + 2]);
    } else {
      at[l] += f[1];
      at[l + 1] += f[2] - b * f[1];
      at[r + 1] += -f[r - l + 2];
      at[r + 2] += -a * f[r - l + 1];
      norm(at[r + 1]);
      norm(at[r + 2]);
    }
    norm(at[l]);
    norm(at[l + 1]);
  }
  for(int i = 1; i <= n; i++) {
    at[i] += b * at[i - 1];
    norm(at[i]);
    if(i - 2 >= 0) {
      at[i] += a * at[i - 2];
      norm(at[i]);
    }
    printf("%I64d ", (at[i] + awal[i]) % mod);
  }
  
  return 0;
}
