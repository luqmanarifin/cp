#include <bits/stdc++.h>

using namespace std;

bool is(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, k;
    scanf("%d %d", &x, &k);
    if (x == 1) {
      puts(k == 2? "YES" : "NO");
      continue;
    }
    if (k != 1) {
      puts("NO");
      continue;
    }
    puts(is(x)? "YES" : "NO");
  }

  return 0;
}
