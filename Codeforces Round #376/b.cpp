#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  if (n == 1) {
    if (a[0] % 2 == 0) {
      puts("YES");
    } else {
      puts("NO");
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    a[i] = a[i] % 2;
    if (a[i] && i + 1 < n && a[i + 1]) {
      a[i + 1]--;
      a[i]--;
    }
  }
  for (int i = 0; i < n; i++) if (a[i]) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}
