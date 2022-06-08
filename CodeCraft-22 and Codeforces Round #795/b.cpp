#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      p.emplace_back(a[i], i);
    }
    sort(p.begin(), p.end());
    bool bad = 0;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + 1 < n && p[j + 1].first == p[j].first) j++;
      vector<int> v;
      for (int k = i; k <= j; k++) v.push_back(p[k].second);
      if (v.size() == 1) {
        bad = 1;
        break;
      }
      for (int i = 0; i < v.size(); i++) {
        ans[v[i]] = v[(i + 1) % v.size()];
      }
      i = j;
    }
    if (bad) {
      printf("-1\n");
      continue;
    }
    for (int i = 0; i < n; i++) printf("%d ", ans[i] + 1); printf("\n");
  }

  return 0;
}
