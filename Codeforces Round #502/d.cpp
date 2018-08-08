#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int LEN = 15;
const int M = (1 << 12) + 5;

int ans[M][105], cost[LEN];
char s[N][LEN];
int cnt[N];
char buf[LEN];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", cost + i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", s[i]);
    int v = 0;
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '1') {
        v += (1 << j);
      }
    }
    cnt[v]++;
  }
  // i dari sono, j dari query
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      int dif = 0;
      for (int k = 0; k < n; k++) {
        if ((i & (1 << k)) == (j & (1 << k))) {
          dif += cost[k];
        }
      }
      // printf("pre %d %d: %d\n", i, j, dif);
      if (dif <= 100) {
        ans[j][dif] += cnt[i];
      }
    }
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 1; j <= 100; j++) {
      ans[i][j] += ans[i][j-1];
    }
  }
  for (int i = 0; i < q; i++) {
    int k;
    scanf("%s %d", buf, &k);
    int v = 0;
    for (int j = 0; j < n; j++) {
      if (buf[j] == '1') {
        v += (1 << j);
      }
    }
    printf("%d\n", ans[v][k]);
  }

  return 0;
}
