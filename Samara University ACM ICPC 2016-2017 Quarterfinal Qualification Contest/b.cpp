#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
vector<tuple<int, int, int>> p;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
    p.emplace_back(a[i] - b[i], a[i], b[i]);
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  long long now = 0, ans = 0;
  for (auto it : p) {
    int need, die;
    tie(ignore, need, die) = it;
    if (now < need) {
      ans += need - now;
      now = need;
    }
    now -= die;
  }
  cout << ans << endl;
  return 0;
}
