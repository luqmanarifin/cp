#include <bits/stdc++.h>

using namespace std;

const int N = 205; 

int cnt[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    if (u > v) swap(u, v);
    cnt[u][v]++;
  }
  int best = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      best = max(best, cnt[i][j]);
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (best == cnt[i][j]) {
        ans = max(ans, i * j);
      }
      // cout << ' ' << i << ' ' << j << ' ' << mul[i][j] << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
  