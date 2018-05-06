
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int as[N], de[N];

void answer(int v) {
  printf("%d\n", v);
  fflush(stdout);
}

int main() {
  int n, m, c;
  scanf("%d %d %d", &n, &m, &c);
  int a = 0, d = 0;
  while ((a + d) < n) {
    int v;
    scanf("%d", &v);
    if (v <= c / 2) {
      int it = upper_bound(as, as + a, v) - as;
      answer(it + 1);
      as[it] = v;
      a += it == a;
    } else {
      v = -v;
      int it = upper_bound(de, de + d, v) - de;
      answer(n - it);
      de[it] = v;
      d += it == d;
    }
  }
  return 0;
}
