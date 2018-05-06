
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans;
  ans.push_back(n - 1);
  ans.push_back(n);
  int last = n - 1;
  for (int i = last - 2; ; i -= 2) {
    bool ok = (i < 1);
    i = max(i, 1);
    for (int t = i; t <= last; t++) ans.push_back(t);
    last = i;
    if (ok) break;
  }
  printf("%d\n", ans.size());
  for (auto i : ans) printf("%d ", i);
  return 0;
}
