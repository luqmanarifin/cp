#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int add = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] + a[i] < k) {
      int cur = k - a[i - 1] - a[i];
      a[i] += cur;
      add += cur;
    }
  }
  printf("%d\n", add);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  
  return 0;
}
