#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 5;
 
int a[N], b[N], p[N], n;
set<int> can;
 
void tukar(int x, int y) {
  swap(p[a[x]], p[a[y]]);
  swap(a[x], a[y]);
  swap(b[x], b[y]);
}

void assess(int x) {
  if (a[x] == b[n - x + 1] || b[x] == a[n - x + 1]) {
    can.erase(x);
    return;
  }
  int y = p[b[n - x + 1]];
  if (x == y) {
    can.erase(x);
    return;
  }
 
  tukar(x, y);
  if (b[x] == a[n - x + 1]) {
    can.insert(x);
  } else {
    can.erase(x);
  }
  tukar(x, y);
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    can.clear();
 
    scanf("%d", &n);
    vector<bool> done(n + 1);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) {
      assess(i);
    }
    vector<pair<int, int>> ans;
    while (!can.empty()) {
      auto x = *(can.begin());
      can.erase(x);
      int y = p[b[n - x + 1]];
      if (x == y || a[x] == b[n - x + 1] || b[x] == a[n - x + 1]) {
        continue;
      }
      bool good = 0;
      tukar(x, y);
      if (a[x] == b[n - x + 1] && b[x] == a[n - x + 1]) {
        good = 1;
      }
      tukar(x, y);

      if (good) {
        done[x] = 1;
        ans.emplace_back(x, y);
        tukar(x, y);
        if (!done[y]) {
          assess(y);
        }
      }
    }
    bool good = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[n - i + 1]) {
        good = 0;
      }
    }
    if (!good) {
      puts("-1");
    } else {
      printf("%d\n", ans.size());
      for (auto it : ans) {
        printf("%d %d\n", it.first, it.second);
      }
    }
  }
 
  return 0;
}