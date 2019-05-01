#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n, z;
  scanf("%d %d", &n, &z);
  set<pair<int, int> > s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    auto it = s.lower_bound(make_pair(a[i] - z + 1, -1));
    if (it == s.begin()) {
      s.insert(make_pair(a[i], i));
    } else {
      it--;
      s.erase(it);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
