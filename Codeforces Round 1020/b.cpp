#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> ans;
    for (int i = 0; i < x; i++) ans.push_back(i);
    for (int i = x + 1; i < n; i++) ans.push_back(i);
    if (x < n) {
      ans.push_back(x);
    }
    for (int i = 0; i < ans.size(); i++) {
      printf("%d%c", ans[i], i + 1 == ans.size()? '\n' : ' ');
    }
  }

  return 0;
}
