#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], lef[N], rig[N], n;

void del(int x) {
  lef[rig[x]] = lef[x];
  rig[lef[x]] = rig[x];
}

bool check(int x) {
  if (lef[x] >= 1 && a[lef[x]] == a[x] - 1) {
    del(x);
    return 1;
  }
  if (rig[x] <= n && a[rig[x]] == a[x] - 1) {
    del(x);
    return 1;
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<pair<int, int>> p;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      p.emplace_back(-a[i], i);
    }
    sort(p.begin(), p.end());
    for (int i = 0; i <= n + 1; i++) {
      lef[i] = i - 1;
      rig[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + 1 < n && p[j + 1].first == p[j].first && p[j + 1].second == p[j].second + 1) j++;

      // printf("asu %d %d\n", i, j);

      int l = i, r = j;
      bool gone = 1;
      while (gone && l <= r) {
        gone = 0;
        if (check(p[l].second)) {
          gone = 1;
          l++;
        }
        if (check(p[r].second)) {
          gone = 1;
          r--;
        }
      }

      i = j;
    }
    int cnt = 0;
    bool all_zero = 1;
    for (int i = rig[0]; i <= n; i = rig[i]) {
      cnt++;
      if (a[i]) all_zero = 0;
    }
    puts(cnt == 1 && all_zero? "YES" : "NO");
  }

  return 0;
}
