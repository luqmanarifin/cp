#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    int cost = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i + 1 < n; i++) {
      int val = 1e9, p = -1;
      for (int j = i; j < n; j++) {
        if (a[j] < val) {
          val = a[j];
          p = j;
        }
      }
      cost += p - i + 1;
      for (int l = i, r = p; l < r; l++, r--) {
        swap(a[l], a[r]);
      }
    }
    printf("Case #%d: %d\n", tt, cost);
  }

  return 0;
}
