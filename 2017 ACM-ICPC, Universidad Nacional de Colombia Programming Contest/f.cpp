#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
  int t;
  scanf("%d", &t);
  bool bad = 0;
  while (t--) {
    for (int i = 0; i < 3; i++) scanf("%d", a + i);
    sort(a, a + 3);
    if (a[0] + a[1] <= a[2]) {
      bad = 1;
    }
  }
  puts(bad? "NO" : "YES");
  return 0;
}
