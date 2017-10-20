#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int ans = 0;
  for (int i = 0; i < n - k; i++) ans += a[i];
  for (int i = n - k; i < n; i++) ans += x;
  cout << ans << endl;
  return 0;
}
