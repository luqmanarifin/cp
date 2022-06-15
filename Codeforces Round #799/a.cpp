#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int cnt = 0;
    if (b > a) cnt++;
    if (c > a) cnt++;
    if (d > a) cnt++;
    printf("%d\n", cnt);
  }

  return 0;
}
