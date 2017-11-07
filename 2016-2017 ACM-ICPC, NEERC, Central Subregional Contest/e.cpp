#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

int a[N], k;
int l, r;

void check() {
  if (l <= k && k <= r) {
    puts("YES");
    exit(0);
  }
  if (k < l) {
    puts("KEK");
    exit(0);
  }
}

main() {
#ifndef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%lld %lld", &n, &k);
  int maxi = -1, p = -1;
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    tot += a[i];
    if (a[i] > maxi) {
      maxi = a[i];
      p = i;
    }
  }
  long long awal = 0;
  for (int i = 0; i < p; i++) awal += a[i];
  if (p > 0) {
    l = p;
    r = awal;
  }
  check();
  while (1) {
    l += maxi;
    r += maxi;
    l += n - 1;
    r += tot - maxi;
    check();
  }

  return 0;
}
