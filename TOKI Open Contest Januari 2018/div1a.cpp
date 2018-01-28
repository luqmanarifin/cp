#include <bits/stdc++.h>

using namespace std;

long long arith(int a, int b, int n) {
  long long Un = a + 1LL * (n - 1) * b;
  return n * (a + Un) / 2;
}

long long sum(int n) {
  if (n == 1) return 1;
  return 1 + arith(4, 4, n - 1);
}

pair<int, int> solve(int level, int ke) {
  int kiri = 1 + (level - 2) * 2;
  if (ke <= kiri) {
    int s = ke / 2;
    int x = -level + 1 + s;
    int y = (ke % 2 == 0? s : -s);
    return {x, y};
  }
  ke -= kiri;
  if (ke <= level) {
    int x = ke - 1;
    int y = level - ke;
    return {x, y};
  }
  ke -= level;
  int x = level - 1 - ke;
  int y = -ke;
  return {x, y};
}


int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("0 0");
    return 0;
  }
  int l = 1, r = 1000000;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (sum(mid) < n) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  auto ans = solve(l + 1, n - sum(l));
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}
