#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[N];

int main() {
  int k;
  scanf("%d", &k);
  int n = 12;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = 0, b = -1, e = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) continue;
      int buy = k / a[i];
      int profit = (a[j] - a[i]) * buy;
      if (profit > ans) {
        ans = profit;
        b = i;
        e = j;
      } else if (profit == ans) {
        if (b != -1 && a[i] < a[b]) {
          b = i;
          e = j;
        }
      }
    }
  }
  if (b == -1) {
    puts("IMPOSSIBLE");
  } else {
    printf("%d %d %d\n", b + 1, e + 1, ans);
  }
  return 0;
}