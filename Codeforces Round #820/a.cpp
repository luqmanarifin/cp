#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ta = a - 1;
    int tb = abs(b - c) + (c - 1);
    if (ta < tb) {
      puts("1");
    } else if (ta > tb) {
      puts("2");
    } else {
      puts("3");
    }
  }

  return 0;
}
