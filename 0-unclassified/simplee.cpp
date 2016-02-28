#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int is[N];

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long t = power(a, b / 2);
  t = t * t;
  if(b & 1) {
    t = t * a;
  }
  return t;
}

long long get(int n) {
  return 1LL * n * (n - 1) + 1;
}

long long getnum(long long a, long long b) {
  return (power(a, 2 * b + 1) + 1) / (a + 1);
}

int main() {
  for(long long i = 2; i < N; i++) {
    if(!is[i]) {
      for(long long j = i * i; j < N; j += i) {
        if(!is[j]) {
          is[j] = i;
        }
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    long long ans = 1;
    while(is[n]) {
      int cur = 0;
      int fac = is[n];
      while(n % fac == 0) {
        cur++;
        n /= fac;
      }
      ans *= getnum(fac, cur);
    }
    if(n > 1) {
      ans *= get(n);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
