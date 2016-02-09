#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1005;

long long c[N][N];
long long exact[N];
int n, m, k;

long long power(int a, int b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

long long get(int a) {
  return a * power(a - 1, n - 1) % mod;
}

int main() {
  c[0][0] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 0; j <= i; j++) {
      if(j == 0 || j == i) {
        c[i][j] = 1;
      } else {
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d", &n, &m, &k);
    if(n == 1) {
      printf("%d\n", (int) c[m][k]);
      continue;
    }
    exact[0] = exact[1] = 0;
    for(int i = 2; i <= k; i++) {
      exact[i] = get(i);
      for(int j = 2; j < i; j++) {
        long long bad = c[i][j] * exact[j] % mod;
        exact[i] -= bad;
        if(exact[i] < 0) exact[i] += mod;
      }
    }
    exact[k] = exact[k] * c[m][k] % mod;
    printf("%d\n", (int) exact[k]);
  }
  
  return 0;
}
