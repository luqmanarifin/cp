#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], x[N], b[N], y[N];
map<int, int> ma, mb;
set<int> sa, sb;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a + i, x + i);
    sa.insert(a[i]);
    ma[a[i]] = x[i];
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", b + i, y + i);
    sb.insert(b[i]);
    mb[b[i]] = y[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (sb.count(a[i])) {
      ans += max(x[i], mb[a[i]]);
    } else {
      ans += x[i];
    }
  }
  for (int i = 0; i < m; i++) {
    if (!sa.count(b[i])) {
      ans += y[i];
    }
  }
  cout << ans << endl;
  return 0;
}
