#include <bits/stdc++.h>

using namespace std;

long long count(int a, int b, long long len) {
  return len / 2 * b + (len / 2 + len % 2) * a;
}

bool can(int a, int b, int n) {
  long long l = 2, r = n;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (count(a, b, mid) < n) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return count(a, b, l) == n;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d:\n", n);
  for (int i = 2; 2 * i - 1 <= n; i++) {
    if (can(i, i - 1, n)) {
      printf("%d,%d\n", i, i - 1);
    }
    if (can(i, i, n)) {
      printf("%d,%d\n", i, i);
    }
  }

  return 0;
}
