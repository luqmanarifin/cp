#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int a[N];

bool has(int l, int r) {
  for (int i = l; i <= r; i++) if (a[i] == 0) return 1;
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int tot = n;
    int mid = n / 2;
    vector<pair<int, int>> ans;
    if (has(mid, n - 1)) {
      int now = n - mid;
      tot -= now - 1;
      ans.emplace_back(mid, n - 1);
    }
    if (has(0, mid - 1)) {
      tot -= mid - 1;
      ans.emplace_back(0, mid - 1);
    }
    ans.emplace_back(0, tot - 1);
    printf("%d\n", ans.size());
    for (auto it : ans) {
      printf("%d %d\n", it.first + 1, it.second + 1);
    }
  }

  return 0;
}
