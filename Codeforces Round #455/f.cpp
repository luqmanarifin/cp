#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ans[N];

void solve(int n) {
  if (n == 0) return;
  for (int j = 20; j >= 0; j--) {
    if ((1 << j) > n) continue;
    int cen = (1 << j);
    int ada = n - cen + 1;
    for (int i = 0; i < ada; i++) {
      swap(ans[cen + i], ans[cen - i - 1]);
    }
    return solve(cen - ada - 1);
  }
  assert(0);
}

void solve_1(int n) {
  if (n % 2) {
    puts("NO");
    return;
  }
  puts("YES");
  for (int i = 1; i <= n; i++) ans[i] = i;
  solve(n);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
}

void solve_2(int n) {
  if (n <= 5) {
    puts("NO");
    return;
  }
  if (__builtin_popcount(n) == 1) {
    puts("NO");
    return;
  }
  puts("YES");
  if (n == 6) {
    puts("3 6 1 5 4 2");
    return;
  }
  if (n == 7) {
    puts("3 6 1 5 4 7 2");
    return;
  }
  for (int i = 1; i <= n; i++) ans[i] = i;
  for (int j = 17; j >= 3; j--) {
    if ((1 << j) > n) continue;
    int from = (1 << j);
    int to = min(n, from * 2 - 1);
    for (int i = from; i <= to; i++) {
      if (i + 2 <= to) {
        swap(ans[i], ans[i + 2]);
      } else if (i + 1 <= to) {
        swap(ans[i], ans[i + 1]);
      }
    }    
  }
  vector<int> asu = {3, 6, 1, 5, 4, 7, 2};
  for (int i = 0; i < asu.size(); i++) ans[i + 1] = asu[i];
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  solve_1(n);
  solve_2(n);
  return 0;
}
