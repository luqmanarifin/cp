#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], ori[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i), ori[i] = a[i];
  if (n == 1) {
    puts("0");
    return 0;
  }
  int ans = N;
  for (int d0 = -1; d0 <= 1; d0++) {
    for (int d1 = -1; d1 <= 1; d1++) {
      a[0] = ori[0] + d0;
      a[1] = ori[1] + d1;
      for (int i = 2; i < n; i++) a[i] = ori[i];
      
      int cur = (d0 != 0) + (d1 != 0);
      int d = a[1] - a[0];
      bool can = 1;
      for (int i = 2; i < n; i++) {
        int be = a[i-1] + d;
        if (abs(a[i] - be) > 1) {
          can = 0;
          break;
        }
        if (a[i] != be) {
          cur++;
        }
        a[i] = be;
      }
      if (can) {
        ans = min(ans, cur);
      }
    }
  }
  if (ans == N) ans = -1;
  cout << ans << endl;
  return 0;
}
