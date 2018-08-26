#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int rmq[N][20];
int a[N];

int find(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return max(rmq[l][g], rmq[r-(1<<g)+1][g]);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i), rmq[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        rmq[i][j] = max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
      }
    }
    printf("Kasus #%d:", tt);
    for (int i = 0; i < n; i++) {
      int ans = 0;
      if (i - 1 >= 0 && a[i-1] < a[i]) {
        int l = 0, r = i - 1;
        while (l < r) {
          int mid = (l + r) >> 1;
          if (find(mid, i - 1) < a[i]) {
            r = mid;
          } else {
            l = mid + 1;
          }
        }
        ans += i - l;
      }
      if (i + 1 < n && a[i+1] < a[i]) {
        int l = i + 1, r = n - 1;
        while (l < r) {
          int mid = (l + r + 1) >> 1;
          if (find(i + 1, mid) < a[i]) {
            l = mid;
          } else {
            r = mid - 1;
          }
        }
        ans += l - i;
      }
      printf(" %d", ans);
    }
    printf("\n");
  }

  return 0;
}
