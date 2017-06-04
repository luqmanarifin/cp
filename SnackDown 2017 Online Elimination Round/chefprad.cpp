#include <bits/stdc++.h>

using namespace std;

const int N = 255;

long long a[N], b[N];
int n, m, e;

int solve(int x) {
  for (int i = 0; i < n; i++) a[i] += x;
  int ans = 0, q = 0;
  for (int i = 0; i < n; i++) {
    while (q < m && b[q] < a[i] - e) q++;
    if (q < m && abs(a[i] - b[q]) <= e) {
      ans++;
      q++;
    }
  }
  for (int i = 0; i < n; i++) a[i] -= x;
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &e);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < m; i++) scanf("%d", b + i);
    sort(a, a + n);
    sort(b, b + m);
    vector<int> can;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        can.push_back(b[j] - a[i]);
        can.push_back(b[j] - e - a[i]);
        can.push_back(b[j] + e - a[i]);
      }
    }
    int ans = 0;
    for (auto it : can) ans = max(ans, solve(it));
    printf("%d\n", ans);
  }

  return 0;
}
