#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

long long power(int a, int b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: %d\n", tt, 4 * power(5, n - 1) % mod);
  }
  
  return 0;
}
