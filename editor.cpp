#include <bits/stdc++.h>

using namespace std;

int a[105];

int get(int r1, int c1, int r2, int c2) {
  for(int i = min(r1, r2); i <= max(r1, r2); i++) {
    c1 = min(c1, a[i] + 1);
  }
  return abs(r1 - r2) + abs(c1 - c2);
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, r1, c1, r2, c2;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
  int ans = 1e9;
  for(int i = 1; i <= n; i++) {
    int now = c1;
    for(int j = min(r1, r2); j <= max(r1, r2); j++) {
      now = min(now, a[j] + 1);
    }
    ans = min(ans, abs(r1 - i) + get(i, now, r2, c2));
  }
  cout << ans << endl;
  return 0;
}
