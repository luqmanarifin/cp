#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    char e, f, g;
    if (a == b && b == c && c == d) e = '=', f = '=', g = '=';
    if (a == b && b == c + d) e = '=', f = '=', g = '+';
    if (a == b && b == c - d) e = '=', f = '=', g = '-';
    if (a == b + c && b + c == d) e = '=', f = '+', g = '=';
    if (a == b + c + d) e = '=', f = '+', g = '+';
    if (a == b + c - d) e = '=', f = '+', g = '-';
    if (a == b - c && b - c == d) e = '=', f = '-', g = '=';
    if (a == b - c + d) e = '=', f = '-', g = '+';
    if (a == b - c - d) e = '=', f = '-', g = '-';
    if (a + b == c && c == d) e = '+', f = '=', g = '=';
    if (a + b == c + d) e = '+', f = '=', g = '+';
    if (a + b == c - d) e = '+', f = '=', g = '-';
    if (a + b + c == d) e = '+', f = '+', g = '=';
    if (a + b - c == d) e = '+', f = '-', g = '=';
    if (a - b == c && c == d) e = '-', f = '=', g = '=';
    if (a - b == c + d) e = '-', f = '=', g = '+';
    if (a - b == c - d) e = '-', f = '=', g = '-';
    if (a - b + c == d) e = '-', f = '+', g = '=';
    if (a - b - c == d) e = '-', f = '-', g = '=';
    printf("Case #%d: %d %c %d %c %d %c %d\n", tt, a, e, b, f, c, g, d);
  }

  return 0;
}
