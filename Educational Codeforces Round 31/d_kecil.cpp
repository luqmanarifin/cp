#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
long long s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    s[i] = a[i];
    if (i) s[i] += s[i-1];
  }
  long long ans = 0;
  for (int i = n - 1; i > 0; i -= 2) ans += s[i];
  cout << ans << endl;
  return 0;
}