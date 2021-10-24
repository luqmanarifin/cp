#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int cnt[N];

void clear(int n) {
  for (int i = 0; i <= 2 * n; i++) cnt[i] = 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    clear(n);
    for (int i = 0; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      cnt[u + v]++;
    }
    bool ok = 1;
    for (int i = 0; i < 2 * n - 1; i++) {
      int dis = abs(n - 1 - i);
      int row = n - dis;
      if (cnt[i] >= row) {
        ok = 0;
      }
    }
    puts(ok? "YES" : "NO");
  }

  return 0;
}
