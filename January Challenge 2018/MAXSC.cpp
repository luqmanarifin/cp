#include <bits/stdc++.h>

using namespace std;

const int N = 705;

int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int maxi = -1;
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    long long sum = 0, maxi = 2e9;
    bool bad = 0;
    for (int i = n - 1; i >= 0; i--) {
      int now = -1;
      for (int j = 0; j < n; j++) {
        if (a[i][j] < maxi) {
          now = max(now, a[i][j]);
        }
      }
      sum += now;
      maxi = now;
      if (now == -1) {
        puts("-1");
        bad = 1;
        break;
      }
    }
    if (!bad) printf("%lld\n", sum);
  }

  return 0;
}
