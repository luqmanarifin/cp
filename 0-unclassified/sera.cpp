#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  long long add = 0;
  while(m--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int v, x;
      scanf("%d %d", &v, &x);
      a[v] = x - add;
    } else if(t == 2) {
      int y;
      scanf("%d", &y);
      add += y;
    } else {
      int q;
      scanf("%d", &q);
      printf("%I64d\n", a[q] + add);
    }
  }
  return 0;
}
