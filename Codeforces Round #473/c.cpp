
#include <bits/stdc++.h>

using namespace std;

void cannot(int n) {
  if (n < 6) {
    puts("-1");
    return;
  }
  vector<pair<int, int>> a = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}};
  for (int i = 7; i <= n; i++) a.emplace_back(i, 1);
  for (auto it : a) printf("%d %d\n", it.first, it.second);
}

void can(int n) {
  for (int i = 2; i <= n; i++) printf("%d %d\n", i, i - 1);
}

int main() {
  int n;
  scanf("%d", &n);
  cannot(n);
  can(n);
  return 0;
}
