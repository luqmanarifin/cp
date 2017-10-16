#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<tuple<int, int, int, int>> v;
  int n = 5;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = i; k <= n; k++) {
        for (int l = j; l <= n; l++) {
          v.emplace_back(i, k, j, l);
        }
      }
    }
  }
  printf("%d\n", v.size());
  for (auto it : v) {
    int a, b, c, d;
    tie(a, b, c, d) = it;
    printf("%d %d %d %d %d\n", n, a, b, c, d);
  }
  return 0;
}
