#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, b, k, m;
long long dp[32][105], tmp[105], a[105], ten[32];

void compute(long long* ret, long long* u, long long* v, int dig) {
  for(int i = 0; i < m; i++) {
    ret[i] = 0;
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      int to = (i * ten[dig] + j) % m;
      ret[to] += u[i] * v[j];
      ret[to] %= mod;
    }
  }
}

void debug() {
  for(int i = 0; i < m; i++) {
    printf("%d ", (int) a[i]);
  }
  printf("\n");
}

int main() {
  scanf("%d %d %d %d", &n, &b, &k, &m);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    dp[0][num % m]++;
  }
  ten[0] = 10 % m;
  for(int i = 1; i < 32; i++) {
    ten[i] = ten[i - 1] * ten[i - 1] % m;
  }
  for(int i = 1; i < 31; i++) {
    compute(dp[i], dp[i - 1], dp[i - 1], i - 1);
  }
  bool awal = 1;
  for(int i = 0; i < 31; i++) {
    if(b & (1 << i)) {
      if(awal) {
        for(int j = 0; j < 105; j++) {
          a[j] = dp[i][j];
        }
        awal = 0;
        //debug();
        continue;
      }
      compute(tmp, a, dp[i], i);
      for(int j = 0; j < 105; j++) {
        a[j] = tmp[j];
      }
      //debug();
    }
  }
  cout << a[k] << endl;
  return 0;
}
