#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 4; i++) scanf("%d", a + i);
    sort(a, a + 4);
    if (a[0] == a[1] && a[2] == a[3]) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
