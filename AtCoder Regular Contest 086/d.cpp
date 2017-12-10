#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const long long inf = 1e18;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long mini = inf, maxi = -inf;
  int pmin = -1, pmax = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    if (a[i] < mini) {
      mini = a[i];
      pmin = i;
    }
    if (a[i] > maxi) {
      maxi = a[i];
      pmax = i;
    }
  }
  vector<pair<int, int>> ans;
  int with = (abs(mini) < abs(maxi)? pmax : pmin);
  bool pos = (abs(mini) < abs(maxi)? 1 : 0);
  for (int i = 1; i <= n; i++) {
    if (i == with) continue;
    ans.emplace_back(with, i);
  }
  if (pos) {
    for (int i = 2; i <= n; i++) ans.emplace_back(i - 1, i);
  } else {
    for (int i = n - 1; i >= 1; i--) ans.emplace_back(i + 1, i);
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d %d\n", it.first, it.second);

  return 0;
}
