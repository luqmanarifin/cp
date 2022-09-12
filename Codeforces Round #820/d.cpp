#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    vector<int> v;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
      int c = b[i] - a[i];
      if (c < 0) {
        v.push_back(c);
      } else {
        s.insert(c);
      }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = 0;
    for (auto it : v) {
      auto c = s.lower_bound(-it);
      if (c == s.end()) {
        break;
      }
      ans++;
      s.erase(c);
    }
    ans += s.size() / 2;
    printf("%d\n", ans);
  }

  return 0;
}
