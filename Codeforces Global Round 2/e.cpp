#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  long long ans = 0, carry = 0;
  for (int i = 0; i < n; i++) {
    long long solve = min(carry, a[i] / 2);
    ans += solve;
    carry -= solve;
    a[i] -= solve * 2;

    long long full = a[i] / 3;
    ans += full;
    carry += a[i] % 3;
  }
  cout << ans << endl;
  return 0;
}
