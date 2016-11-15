#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

// cost, speed-up
pair<int, int> p[N];
int c[N], d[N];
int n, m, k;
int x, s;

long long get_speed(int val) {
  int it = upper_bound(p, p + m, make_pair(val, (int)2e9 + 5)) - p - 1;
  if (it >= 0) {
    return p[it].second;
  }
  return x;
}

int main() {
  scanf("%d %d %d %d %d", &n, &m, &k, &x, &s);
  for (int i = 0; i < m; i++) scanf("%d", &p[i].second);
  for (int i = 0; i < m; i++) scanf("%d", &p[i].first);
  sort(p, p + m);
  p[m].second = 2e9 + 5;
  for (int i = 1; i <= m; i++) {
    p[i].second = min(p[i].second, p[i - 1].second);
  }
  for (int i = 0; i < k; i++) scanf("%d", c + i);
  for (int i = 0; i < k; i++) scanf("%d", d + i);
  
  long long ans = get_speed(s) * n;
  for (int i = 0; i < k; i++) {
    if (d[i] <= s) {
      long long need = max(0, n - c[i]);
      ans = min(ans, get_speed(s - d[i]) * need);
    }
  }
  cout << ans << endl;
  return 0;
}
