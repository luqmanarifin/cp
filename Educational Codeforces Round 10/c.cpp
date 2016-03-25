#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

pair<int, int> a[N], h[N];

int p[N], inv[N];
int pol[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", p + i);
    inv[p[i]] = i;
  }
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &h[i].first, &h[i].second);
    int l = min(inv[h[i].first], inv[h[i].second]);
    int r = max(inv[h[i].first], inv[h[i].second]);
    a[i] = {l, r};
  }
  sort(a, a + m);
  pol[m - 1] = a[m - 1].second;
  for(int i = m - 2; i >= 0; i--) {
    pol[i] = min(a[i].second, pol[i + 1]);
  }

  long long ans = 0;
  int l = 0;
  for(int i = 1; i <= n; i++) {
    while(l < m && a[l].first < i) l++;
    int r = n + 1;
    if(l < m) r = min(r, pol[l]);
    ans += r - i;
  }
  cout << ans << endl;
  return 0;
}
