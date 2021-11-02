#include <bits/stdc++.h>

using namespace std;

long long rem(long long a) {
  return ((a % 4) + 4) % 4;
}

int get_sign(long long c, long long a) {
  if (a % 2) {
    if (c == 0 || c == 3) {
      return 1;
    } else {
      return -1;
    }
  } else {
    if (c == 0 || c == 3) {
      return -1;
    } else {
      return 1;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, n;
    scanf("%lld %lld", &a, &n);
    long long add = 0;
    long long start = n / 4 * 4;
    for (long long i = start + 1; i <= n; i++) {
      add += get_sign(rem(i - 1), a) * i;
    }
    printf("%lld\n", add + a);
  }

  return 0;
}
