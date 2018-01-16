#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N];

long long val(int mask, int len) {
  long long a = 0, b = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (mask & (1 << i)) {
      b = a + b + 1;
    } else {
      a = a + b;
    }
  }
  return a;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%s %d", s, &x);
    int n = strlen(s), now = 0; 
    int ans = n + 1;
    for (int i = 0; i < n; i++) now = now * 2 + s[i] - '0';
    for (int i = 0; i < (1 << (n - 2)); i++) {
      int hail = ~(((1 << (n - 2)) - 1) << 1);
      int mask = (now & hail);
      mask |= i << 1;
      if (val(mask, n) == x) {
        ans = min(ans, __builtin_popcount(mask ^ now));
      }
    }
    if (ans > n) {
      puts("NO");
    } else {
      puts("YES");
      printf("%d\n", ans);
    }
  }

  return 0;
}
