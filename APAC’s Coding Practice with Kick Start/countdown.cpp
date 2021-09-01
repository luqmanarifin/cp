#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int ans = 0, goal = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == goal) {
        goal++;
        if (goal > k) {
          ans++;
          goal = 1;
        }
      } else {
        if (a[i] == 1) {
          goal = 2;
        } else {
          goal = 1;
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
