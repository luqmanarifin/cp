#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], at[N];
vector<int> used;
int need_hi, need_lo;

void dfs(int l, int r, int x) {
  int mid = (l + r) >> 1;
  if (a[mid] == x) return;
  used.push_back(a[mid]);
  if (mid < at[x]) {
    if (a[mid] > x) {
      need_lo++;
    }
    dfs(mid + 1, r, x);
  } else {
    if (a[mid] < x) {
      need_hi++;
    }
    dfs(l, mid - 1, x);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      at[a[i]] = i;
    }
    vector<int> ans;
    while (q--) {
      used.clear();
      need_hi = 0;
      need_lo = 0;

      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      if (at[x] < l || r < at[x]) {
        ans.push_back(-1);
        continue;
      }
      dfs(l, r, x);
      int used_hi = 0, used_lo = 0;
      for (auto it : used) {
        if (it < x) {
          used_lo++;
        } else {
          used_hi++;
        }
      }
      int p = min(need_hi, need_lo);
      need_hi -= p;
      need_lo -= p;
      if (need_lo > x - 1 - used_lo) {
        ans.push_back(-1);
        continue;
      }
      if (need_hi > n - x - used_hi) {
        ans.push_back(-1);
        continue;
      }
      ans.push_back(2 * p + 2 * (need_lo + need_hi));
    }
    for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], i + 1 == ans.size()? '\n' : ' ');
  }

  return 0;
}
