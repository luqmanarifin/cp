#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int p[N], v[N];
int op[2][2];

int main() {
  op[0][0] = 1;
  op[0][1] = 0;
  op[1][0] = 1;
  op[1][1] = 1;

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(v, 0, sizeof(v));

    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) scanf("%d", p + i);
    for (int i = 0; i <= n + 1; i++) {
      v[i] = 0;
    }
    for (int i = 1; i <= n + 1; i++) {
      v[i] = op[v[i]][v[i-1]];
    }
    printf("Case #%d: ", tt);
    if (v[n + 1]) {
      printf("%d\n", 0);
    } else {
      printf("%d\n%d\n", 1, 0);
    }
  }

  return 0;
}
