#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int ans = (abs(a-c) + abs(b-d)) * 2 + 4;
  if (a == c || b == d)
    ans += 2;
  printf("%d\n", ans);
  return 0;
}
