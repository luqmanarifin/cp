#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

long long bit[N][N];

void add(int i, int j, long long val) {
  bit[i][j] += val;
}

long long find(int i, int j) {
  return bit[i][j];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(bit, 0, sizeof(bit));
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      add(u, v, u * v);
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i) bit[i][j] += bit[i-1][j];
        if (j) bit[i][j] += bit[i][j-1];
        if (i && j) bit[i][j] -= bit[i-1][j-1];
      }
    }
    while (q--) {
      int min_x, min_y, max_x, max_y;
      scanf("%d %d %d %d", &min_x, &min_y, &max_x, &max_y);
      long long ans = find(max_x - 1, max_y - 1);
      ans -= find(min_x, max_y - 1);
      ans -= find(max_x - 1, min_y);
      ans += find(min_x, min_y);
      printf("%lld\n", ans);
    }
  }

  return 0;
}
