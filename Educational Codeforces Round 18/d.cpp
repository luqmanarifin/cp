#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  long long n;
  int q;
  scanf("%I64d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    if ((1LL << i) == n + 1) {
      n = i;
      break;
    }
  }
  while (q--) {
    long long now;
    scanf("%I64d %s", &now, s);
    int len = strlen(s);
    for (int at = 0; at < len; at++) {
      int lsb = -1;
      for (int i = 0; i < n; i++) {
        if ((1LL << i) & now) {
          lsb = i;
          break;
        }
      }
      if (s[at] == 'U') {
        if (lsb != n - 1) {
          now &= -1LL ^ (1LL << lsb);
          now |= (1LL << (lsb + 1));
        }
      } else if (s[at] == 'L') {
        if (lsb != 0) {
          now &= -1LL ^ (1LL << lsb);
          now |= (1LL << (lsb - 1));
        }
      } else {
        if (lsb != 0) {
          now |= (1LL << (lsb - 1));
        }
      }
    }
    printf("%I64d\n", now);
  }

  return 0;
}
