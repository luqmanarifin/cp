#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e4 + 7;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += 1LL * a[i] * a[n - 1- i];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
