#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

long long take[4][N];
long long best[4][N];
int cnt[N];
int n, m;

long long solve(int weight, int take_dua) {
  int one = min(cnt[1], weight - 2 * take_dua);
  return take[2][take_dua] + take[1][one];
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    cnt[a]++;
    best[a][cnt[a]] = b;
  }
  for (int j = 1; j <= 3; j++) {
    sort(best[j] + 1, best[j] + 1 + cnt[j]);
    reverse(best[j] + 1, best[j] + 1 + cnt[j]);
    for (int i = 1; i <= cnt[j]; i++) {
      take[j][i] = take[j][i-1] + best[j][i];
    }
  }
  long long ans = 0;
  for (int i = 0; i <= cnt[3] && 3 * i <= m; i++) {
    int l = 0, r = min(cnt[2], (m - 3 * i) / 2);
    int sisa = m - 3 * i;
    while (r - l > 3) {
      int lf = l + (r - l) / 3;
      int rf = r - (r - l) / 3;
      if (solve(sisa, lf) > solve(sisa, rf)) {
        r = rf;
      } else {
        l = lf;
      }
    }
    for (int j = l; j <= r; j++) ans = max(ans, take[3][i] + solve(m - 3 * i, j));
  }
  cout << ans << endl;
  return 0;
}
