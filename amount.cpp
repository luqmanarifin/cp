#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

long long a[N];

int main() {
  int q, n;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
    a[i] += a[i - 1];
  }
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l++; r++;
    printf("%I64d\n", a[r] - a[l - 1]);
  }
  return 0;
}
