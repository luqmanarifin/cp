#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int ans = 2e9 + 5, cnt = 0;
  for (int i = 1; i < n; i++) {
    int cur = a[i] - a[i-1];
    if (cur < ans) {
      ans = cur;
      cnt = 1;
    } else if (cur == ans) {
      cnt++;
    }
  }
  printf("%d %d\n", ans, cnt);
  return 0;
}
