#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

long long x[N];
bool locked[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", x + i);
  while (q--) {
    char c; int l, r, v;
    scanf(" %c", &c);
    if (c == 'F') {
      scanf("%d %d %d", &l, &r, &v);
      for (int i = l; i <= r; i++) if (!locked[i]) {
        x[i] = v;
      }
    } else if (c == 'I') {
      scanf("%d", &v);
      
    } else if (c == 'L') {
      scanf("%d %d", &l, &r);
      for (int i = l; i <= r; i++) locked[i] = 1;
    } else if (c == 'C') {
      scanf("%d %d", &l, &r);
      for (int i = l; i <= r; i++) locked[i] = 0;
    } else if (c == 'O') {
      scanf("%d %d", &l, &r);
      long long sum = 0;
      for (int i = l; i <= r; i++) sum += x[i];
      printf("%lld\n", sum);
    } else {
      assert(0);
    }
  }

  return 0;
}
