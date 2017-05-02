#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  a = max(a, b);
  c = min(c, d);
  puts(a <= c? "YES" : "NO");
  return 0;
}
