
#include <bits/stdc++.h>

using namespace std;

int solve_1(int n, int pos, int l, int r) {
  int ans = 0;
  if (l > 1) {
    ans += abs(pos - l) + 1;
    pos = l;
  }
  if (r + 1 <= n) {
    ans += abs(pos - r) + 1;
    pos = r;
  }
  return ans;
}

int solve_2(int n, int pos, int l, int r) {
  int ans = 0;
  if (r + 1 <= n) {
    ans += abs(pos - r) + 1;
    pos = r;
  }
  if (l > 1) {
    ans += abs(pos - l) + 1;
    pos = l;
  }
  return ans;
}

int main() {
  int n, pos, l, r;
  scanf("%d %d %d %d", &n, &pos, &l, &r);
  printf("%d\n", min(solve_1(n, pos, l, r), solve_2(n, pos, l, r)));
  return 0;
}
