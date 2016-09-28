#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long c[N], sum[N], o[N];
bool a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%I64d", c + i);
  for (int i = n; i >= 1; i--) sum[i] += sum[i + 1] + c[i];
  while (k--) { int v; scanf("%d", &v); a[v] = 1; }
  for (int i = n; i >= 1; i--) {
    o[i] = o[i + 1];
    if (a[i]) {
      o[i] += c[i];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      ans += c[i] * sum[i + 1];
    } else {
      if (a[i + 1]) {
        ans += c[i] * o[i + 1];
      } else {
        ans += c[i] * (c[i + 1] + o[i + 1]);
      }
    }
  }
  if (a[1] == 0 && a[n] == 0) ans += c[1] * c[n];
  cout << ans << endl;
  return 0;
}
