#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  set<pair<int, int>> s;
  for (int i = 1; i <= min(k, n - 1); i++) {
    s.insert({a[i], -i});
  }
  for (int i = 0; i + 1 < n; i++) {
    auto it = s.begin();
    if (it->first < a[i]) {
      int id = -(it->second);
      swap(a[i], a[id]);
      for (int i = 0; i < n; i++) {
        printf("%d%c", a[i], " \n"[i == n - 1]);
      }
      return 0;
    }
    if (i + 1 < n) s.erase({a[i + 1], -(i + 1)});
    if (i + 1 + k < n) s.insert({a[i + 1 + k], -(i + 1 + k)});
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", a[i], " \n"[i == n - 1]);
  }
  return 0;
}
