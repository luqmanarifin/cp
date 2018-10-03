#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

char a[N], b[N];
long long dist[256][256];

int main() {
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      dist[i][j] = inf;
    }
    dist[i][i] = 0;
  }

  int k;
  scanf("%s %s %d", a, b, &k);
  int n = strlen(a);
  while (k--) {
    char c, d; int cost;
    scanf(" %c %c %d", &c, &d, &cost);
    dist[c][d] = min(dist[c][d], 1LL * cost);
  }
  for (int k = 0; k < 256; k++) {
    for (int i = 0; i < 256; i++) {
      for (int j = 0; j < 256; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (dist[a[i]][b[i]] >= inf) {
      puts("-1");
      return 0;
    }
    ans += dist[a[i]][b[i]];
  }
  cout << ans << endl;
  return 0;
}
