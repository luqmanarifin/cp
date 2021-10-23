#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int now, int rem, int bit) {
  int all = (1 << (bit + 1)) - 1;
  vector<int> ans;
  for (int i = 0; i <= bit; i++) {
    int j = i;
    while (rem & (1 << j)) j++;
    int st = now - (1 << j) + 1;
    int p = st;
    for (int k = i; k < j; k++) {
      ans.push_back(p);
      p += (1 << k);
      now += (1 << k);
    }
    ans.push_back(st);
    now -= (1 << j);
    i = j;
  }
  printf("YES\n%d\n", ans.size());
  for (auto it : ans) printf("%d\n", it);
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 0) {
      printf("YES\n0\n");
      continue;
    }
    bool found = 0;
    for (int bit = 0; (1 << bit) <= n; bit++) {
      int all = (1 << (bit + 1)) - 1;
      if (all < k) continue;
      int rem = all - k;
      if (rem % 2 == 0 && rem / 2 <= all) {
        if (solve(n, k, rem / 2, bit)) {
          found = 1;
          break;
        }
      }
    }
    if (!found) {
      printf("NO\n");
    }
  }

  return 0;
}
