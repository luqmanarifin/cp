#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  b += a * 4;
  c += b / 2 * 4;
  cout << min(c, d) * 4 << endl;
  return 0;
}
