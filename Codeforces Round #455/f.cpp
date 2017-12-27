#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int all = 131072;

int ada[all], ans[N];

void solve_1(int n) {
  if (n % 2) {
    puts("NO");
    return;
  }
  puts("YES");
  memset(ada, 0, sizeof(ada));
  for (int i = 1; i <= n; i++) {
    ada[all ^ i] = i;
  }
  for (int i = n; i >= 1; i--) {
    bool found = 0;
    for (int j = i; j < all; j = ((j + 1) | i)) {
      if (ada[j]) {
        ans[i] = ada[j];
        ada[j] = 0;
        found = 1;
        break;
      }
    }
    assert(found);
  }
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
  for (int i = 1; i <= n; i++) ans[i] = i;
  for (int j = 17; j > 0; j--) {
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
  swap(ans[1], ans[3]);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  solve_1(n);
  solve_2(n);
  return 0;
}
