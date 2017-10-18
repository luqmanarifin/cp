#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    while (v--) {
      int k;
      scanf("%d", &k);
      a[i].push_back(k);
    }
  }
  set<int> small;
  
  vector<pair<int, int>> p;
  
  for (int i = 1; i < n; i++) {
    int sz = min(a[i-1].size(), a[i].size());
    bool done = 0;
    for (int j = 0; j < sz; j++) {
      if (a[i-1][j] < a[i][j]) {
        if (small.count(a[i][j])) {
          small.insert(a[i-1][j]);
        }
        p.emplace_back(a[i-1][j], a[i][j]);
        done = 1;
        break;
      } else if (a[i-1][j] > a[i][j]) {
        if (small.count(a[i-1][j]) && small.count(a[i][j])) {
          puts("No");
          return 0;
        } else if (small.count(a[i-1][j])) {
          // nothing
        } else if (small.count(a[i][j])) {
          puts("No");
          return 0;
        } else {
          small.insert(a[i-1][j]);
        }
        p.emplace_back(a[i-1][j], a[i][j]);
        done = 1;
        break;
      }
    }
    if (!done) {
      if (a[i-1].size() > a[i].size()) {
        puts("No");
        return 0;
      }
    }
  }
  for (auto it : p) {
    int u, v;
    tie(u, v) = it;
    if (u < v) {
      if (small.count(v) && !small.count(u)) {
        puts("No");
        return 0;
      }
    } else {
      if (!(small.count(u) && !small.count(v))) {
        puts("No");
        return 0;
      }
    }
  }
  
  puts("Yes");
  printf("%d\n", small.size());
  for (auto it : small) printf("%d ", it);
  return 0;
}
