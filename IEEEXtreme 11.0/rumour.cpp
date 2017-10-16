#include <bits/stdc++.h>

using namespace std;

int find(long long a) {
  for (int i = 62; i >= 0; i--) {
    if (a & (1LL << i)) {
      return i + 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    int ans = 0;
    while (a != b) {
      ans++;
      if (a > b) a /= 2;
      else b /= 2;
    }
    printf("%d\n", ans);
  }

  return 0;
}
