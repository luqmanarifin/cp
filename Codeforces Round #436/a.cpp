#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  if (a[0] == a[n - 1]) {
    puts("NO");
    return 0;
  }
  if (a[0] == a[n / 2 - 1] && a[n / 2] == a[n - 1]) {
    puts("YES");
    printf("%d %d\n", a[0], a[n - 1]);
  } else {
    puts("NO");
  }
  return 0;
}
