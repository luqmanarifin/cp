#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long mod = 1e9 + 7;

long long fact[N];
long long ifact[N];

long long c(int n, int k) {
  if(n < k || c < 0 || k < 0) {
    return 0;
  }
  long long temp = fact[n] * ifact[k];
  temp %= mod;
  temp *= fact[n - k];
  temp %= mod;
  return temp;
}

long long power(long long a, long long b) {
  if(b == 0) {
    return 1;
  }
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

int a[N];
int d[N];

int main() {
  fact[0] = ifact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
    ifact[i] = inv(fact[i]);
  }
  long long ans = 1;
  int n, sum = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", d + i);
    for(int j = 0; j < d[i]; j++) {
      scanf("%d", a + j);
    }
    sort(a, a + d[i]);
    for(int j = 0; j < d[i]; j++) {
      int ada = 1;
      while(j + 1 < d[i] && a[j] == a[j + 1]) {
        ada++;
        j++;
      }
      ans *= fact[ada];
      ans %= mod;
    }
    sum += d[i];
  }
  ans *= fact[sum];
  ans %= mod;
  for(int i = 0; i < n; i++) {
    ans *= ifact[d[i]];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
