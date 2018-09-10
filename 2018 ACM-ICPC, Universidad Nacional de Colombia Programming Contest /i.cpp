#include <bits/stdc++.h>

using namespace std;

int n;

long long trans(long long num) {
  num *= 2;
  num &= -2LL;
  if (num & (1LL << n)) {
    num |= 1;
  }
  num &= (1LL << n) - 1;
  return num;
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  while (m--) {
    long long num, k;
    scanf("%lld %lld", &num, &k);
    k %= n;
    while (k--) {
      num = trans(num);
    }
    printf("%lld\n", num);
  }

  return 0;
}
