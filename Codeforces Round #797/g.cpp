#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int l[N], r[N];
set<int> cur;

void add(int at, int val) {
  int lef = at;
  int rig = r[at];
  l[val] = lef;
  r[val] = rig;
  r[lef] = val;
  l[rig] = val;
  cur.insert(val);
}

void remove(int val) {
  int lef = l[val];
  int rig = r[val];
  l[rig] = lef;
  r[lef] = rig;
  cur.erase(val);
}

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);

    cur.clear();
    for (int i = 0; i <= n + 1; i++) {
      l[i] = i - 1;
      r[i] = i + 1;
      if (1 <= i && i <= n) {
        cur.insert(i);
      }
    }

    int slowest = a[1];
    for (int i = 2; i <= n; i++) {
      if (a[i] >= slowest) {
        remove(i);
      }
      slowest = min(slowest, a[i]);
    }
    // printf("train: "); for (auto i : cur) printf("%d ", i); printf("\n");
    for (int tt = 1; tt <= m; tt++) {
      int u, v;
      scanf("%d %d", &u, &v);
      a[u] -= v;

      auto it = cur.upper_bound(u);
      it--;
      int rig = r[*it];

      if (a[u] < a[*it] && u != *it) {
        add(*it, u);
      }
      vector<int> to_remove;
      while (rig <= n) {
        if (a[rig] >= a[u]) {
          to_remove.push_back(rig);
          rig = r[rig];
        } else {
          break;
        }
      }
      for (auto i : to_remove) remove(i);
      printf("%d ", cur.size());
      // printf("train: "); for (auto i : cur) printf("%d ", i); printf("\n");
    }
    printf("\n");
  }

  return 0;
}
