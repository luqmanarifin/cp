#include <bits/stdc++.h>

using namespace std;

const int N = 105;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int p = 0; p < 64; p++) {
      bool has_0 = 0, has_1 = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] & (1LL << p)) {
          has_1 = 1;
        } else {
          has_0 = 1;
        }
      }
      if (has_0 && has_1) {
        printf("%lld\n", (1LL << (p + 1)));
        break;
      }
    }
  }

  return 0;
}
