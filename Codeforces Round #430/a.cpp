#include <bits/stdc++.h>

using namespace std;

int main() {
  int l, r, x, y, k;
  scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);
  for (int i = x; i <= y; i++) {
    long long val = 1LL * i * k;
    if (l <= val && val <= r) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}