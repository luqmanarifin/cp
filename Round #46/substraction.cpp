#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) scanf("%d", a + i);
  set<int> can;
  sort(a, a + 2 * n);
  for (int i = 1; i < 2 * n; i++) {
    if (a[i] > a[0]) {
      can.insert(a[i] - a[0]);
    }
  }
  for (auto x : can) {
    multiset<int> num;
    for (int i = 0; i < 2 * n; i++) {
      num.insert(a[i]);
    }
    vector<int> ans;
    for (auto it : num) {
      if (num.count(it + x)) {
        num.erase(num.find(it + x));
        ans.push_back(it + x);
      }
    }
    if (ans.size() == n) {
      printf("%d\n", x);
      for (auto it : ans) printf("%d ", it);
      printf("\n");
      return 0;
    }
  }
  puts("-1");
  return 0;
}