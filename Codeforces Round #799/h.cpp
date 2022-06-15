#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      m[a[i]].push_back(i);
    }
    int ans = 1, p = a[1], l = 1, r = 1;
    for (auto asu : m) {
      auto it = asu.first;
      auto v = m[it];
      int now = 1, s = v[0];
      for (int i = 1; i < v.size(); i++) {
        int fut = now + 1 - (v[i] - v[i-1] - 1);
        if (fut < 1) {
          now = 1;
          s = v[i];
        } else {
          now = fut;
        }

        if (now > ans) {
          ans = now;
          p = it;
          l = s;
          r = v[i];
        }
      }
    }
    printf("%d %d %d\n", p, l, r);
  }

  return 0;
}
