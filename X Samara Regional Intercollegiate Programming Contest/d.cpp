#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int gcd = a[0];
  for (int i = 0; i < n; i++) gcd = __gcd(gcd, a[i]);
  if (abs(x) % gcd == 0) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
