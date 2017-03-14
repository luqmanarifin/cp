#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    bool ada = 0;
    for (int j = 0; j < 31; j++) {
      int cur = -1;
      for (int i = 0; i < n; i++) {
        if (a[i] & (1 << j)) {
          if (cur == -1) {
            cur = a[i];
          } else {
            cur &= a[i];
          }
        }
      }
      if (__builtin_popcount(cur) == 1) {
        ada = 1;
        break;
      }
    }
    puts(ada? "YES" : "NO");
  }
  return 0;
}
