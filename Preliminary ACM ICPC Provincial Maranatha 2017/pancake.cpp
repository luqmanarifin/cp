#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N], s[N], n;

void go(int at) {
  if (at == 0) return;
  printf("%d ", n - at);
  reverse(a, a + at + 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      s[i] = a[i];
    }
    sort(s, s + n);
    for (int j = n - 1; j >= 0; j--) {
      if (s[j] == a[j]) continue;
      if (a[0] == s[j]) {
        go(j);
        continue;
      }
      int at = -1;
      for (int i = 0; i < j; i++) {
        if (a[i] == s[j]) {
          at = i;
          break;
        }
      }
      if (at != j) {
        go(at);
        go(j);
      }
    }
    puts("0");
  }

  return 0;
}
