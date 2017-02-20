#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    int first = n;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      if (a[i] == 0) {
        ans += 1000;
        first = min(first, i);
      }
    }
    printf("%d\n", ans + (n - first) * 100);
  }

  return 0;
}
