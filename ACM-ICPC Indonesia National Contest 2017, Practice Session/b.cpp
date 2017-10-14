#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

map<int, int> cx, cy;
map<pair<int, int>, int> cnt;

int x[N], y[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
    cx[x[i]]++;
    cy[y[i]]++;
    cnt[{x[i], y[i]}]++;
  }
  int ans = -1, p = -1;
  for (int i = 0; i < n; i++) {
    int cur = cx[x[i]] + cy[y[i]] - 2 * cnt[{x[i], y[i]}];
    if (cur > ans) {
      ans = cur;
      p = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
