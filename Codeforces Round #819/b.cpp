#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int m) {
  vector<int> ans;
  if (n == 1) {
    return {m};
  }
  if (n == 2) {
    if (m % 2) return ans;
    return {m / 2, m / 2};
  }
  if (n % 2) {
    if (m < n) return ans;
    for (int i = 0; i < n - 1; i++) ans.push_back(1);
    ans.push_back(m - (n - 1));
    return ans;
  }
  if (m % 2) return ans;
  if (m < n) return ans;
  ans = vector<int>(n, 1);
  ans[0] += (m - n) / 2;
  ans[1] += (m - n) / 2;
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    auto ans = solve(n, m);
    if (ans.empty()) {
      printf("No\n");
    } else {
      printf("Yes\n");
      for (int i = 0; i < ans.size(); i++) printf("%d%c", ans[i], i == n - 1? '\n' : ' ');
    }
  }
  return 0;
}
