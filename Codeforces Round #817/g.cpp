#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
map<int, vector<int>> sol;

void solve(int l, int r, int x) {
  int n = r - l + 1;
  if (n < 7) {
    for (int i = 0; i < n; i++) {
      a[l + i] |= (sol[n][i] << x);
    }
    return;
  }
  int half = n / 2;
  if (half % 2) half++;
  for (int i = 0; i < half; i++) a[l + i] |= (1 << x);
  solve(l, l + half - 1, x + 1);
  solve(l + half, r, x + 1);
}

int main() {
  sol[3] = {1, 2, 3};
  sol[4] = {1, 2, 3, 0};
  sol[5] = {3, 1, 6, 0, 4};
  sol[6] = {4, 1, 2, 12, 3, 8};

  int t;
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));

    int n;
    scanf("%d", &n);
    solve(0, n - 1, 0);
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i == n - 1? '\n' : ' ');
  }

  return 0;
}
