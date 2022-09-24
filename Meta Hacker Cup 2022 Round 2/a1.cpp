#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int D = 26;

vector<int> at[D];
int sum[D][N];
char s[N];

int get(int c, int l, int r) {
  return sum[c][r] - sum[c][l-1];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < D; i++) at[i].clear();
    memset(sum, 0, sizeof(sum));

    int q;
    scanf("%s %d", s + 1, &q);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
      int c = s[i] - 'a';
      at[c].push_back(i);
      sum[c][i]++;
    }
    for (int j = 0; j < D; j++) {
      for (int i = 1; i <= n; i++) {
        sum[j][i] += sum[j][i-1];
      }
    }
    int ans = 0;
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      int len = r - l + 1;
      if (len % 2 == 0) continue;
      int odd = 0, c = -1;
      for (int j = 0; j < D; j++) {
        int sum_at = sum[j][r] - sum[j][l - 1];
        if (sum_at % 2) {
          odd++;
          c = j;
        }
      }
      if (odd != 1) continue;
      int mid = (l + r) / 2;
      bool found = 0;
      if (get(c, l, mid) > 0) {
        bool same = 1;
        for (int j = 0; j < D; j++) {
          if (j == c) continue;
          if (get(j, l, mid) != get(j, mid + 1, r)) {
            same = 0;
          }
        }
        if (same) found = 1;
      }
      if (get(c, mid, r) > 0) {
        bool same = 1;
        for (int j = 0; j < D; j++) {
          if (j == c) continue;
          if (get(j, l, mid - 1) != get(j, mid, r)) {
            same = 0;
          }
        }
        if (same) found = 1;
      }
      if (found) ans++;
    }
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
