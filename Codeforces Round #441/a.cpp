#include <bits/stdc++.h>

using namespace std;

int get(int v) {
  int p = v;
  while (v > 0) {
    p += v % 10;
    v /= 10;
  }
  return p;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans;
  for (int i = max(0, n - 300); i <= n; i++) {
    if (get(i) == n) {
      ans.push_back(i);
    }
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it);
  return 0;
}
