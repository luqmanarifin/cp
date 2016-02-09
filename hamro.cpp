#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
    if(i % 2 == 0) a[i] = -a[i];
    a[i] += a[i - 1];
  }
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%I64d\n", l % 2? a[r] - a[l - 1] : a[l - 1] - a[r]);
  }
  return 0;
}
