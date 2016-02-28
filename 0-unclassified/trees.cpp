#include <bits/stdc++.h>

using namespace std;

pair<int, int> p[105];

int get(int l, int r) {
  int ret = 0;
  for(int i = l; i <= r; ++i) ret += p[i].second;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].first, &p[i].second);
  }
  sort(p, p + n);
  int id = lower_bound(p, p + n, make_pair(0, 0)) - p;
  int l = id, r = n - id;
  int ans = 0;
  
  int x = min(l, r);
  ans = max(ans, get(id - x, id - 1) + get(id, id + x - 1));
  
  x = min(l, r + 1);
  ans = max(ans, get(id - x, id - 1) + get(id, id + x - 2));
  
  x = min(l + 1, r);
  ans = max(ans, get(id - x + 1, id - 1) + get(id, id + x - 1));
  
  cout << ans << endl;
  return 0;
}
