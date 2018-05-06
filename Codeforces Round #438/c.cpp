
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[1 << 4];
int a[N][4], now[4];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < k; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j]) {
        cur |= (1 << j);
      }
    }
    cnt[cur]++;
  }
  for (int p = 1; p <= n; p++) {
    //cout << p << endl;
    int wajib = 0;
    for (int j = 0; j < k; j++) {
      if ((now[j] + 1) > p / 2) {
        wajib |= (1 << j);
      }
    }
    for (int longgar = 0; longgar <= k; longgar++) {
      int take = -1;
      for (int mask = 0; mask < (1 << k); mask++) {
        if (cnt[mask] == 0) continue;
        if (__builtin_popcount(wajib & mask) != longgar) continue;
        take = mask;
        break;
      }
      if (take != -1) {
        cnt[take]--;
        for (int j = 0; j < k; j++) {
          if (take & (1 << j)) {
            now[j]++;
          }
        }
        break;
      }
    }
    bool ok = 1;
    for (int j = 0; j < k; j++) {
      if (now[j] > p / 2) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
