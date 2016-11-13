#include <bits/stdc++.h>

using namespace std;

const int N = 55;

vector<int> a[N];

// length - colour
set<pair<int, int>> all;

void add(int c) {
  for (auto it : a[c]) {
    all.insert({it, c});
  }
}

void remove(int c) {
  for (auto it : a[c]) {
    all.erase({it, c});
  }
}

int main() {
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int n;
    scanf("%d", &n);
    while (n--) {
      int v;
      scanf("%d", &v);
      a[i].push_back(v);
    }
    sort(a[i].begin(), a[i].end());
    a[i].resize(distance(a[i].begin(), unique(a[i].begin(), a[i].end())));
  }
  for (int i = 0; i < k; i++) add(i);
  for (int i = 0; i < k; i++) {
    remove(i);
    for (int j = 0; j < k; j++) {
      if (i == j) continue;
      remove(j);

      int r = a[j].size() - 1;
      for (int q = a[i].size() - 1; q >= 0; q--) {
        while (r >= 0 && a[i][q] < a[j][r]) r--;
        if (r < 0) break;
        int lc = a[i][q];
        int lb = a[j][r];
        auto it = all.upper_bound({lb, -1});
        if (it != all.begin()) {
          it--;
          int la = it->first;
          int ck = it->second;
          if (la + lb > lc) {
            printf("%d %d %d %d %d %d\n", ck+1, la, i+1, lc, j+1, lb);
            return 0;
          }
        }
      }

      add(j);
    }
    add(i);
  }
  puts("NIE");
  return 0;
}