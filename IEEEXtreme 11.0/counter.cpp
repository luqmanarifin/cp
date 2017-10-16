#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];
int rmq[N][20];

int get(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return min(rmq[l][g], rmq[r-(1<<g)+1][g]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    rmq[i][0] = a[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    int l = u, r = v;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (get(mid, v) < a[v]) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if (get(l, v) == a[v]) {
      puts("0");
    } else {
      printf("%d\n", v - l + 1);
    }
  }

  return 0;
}
