#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, k;
int rv[N][21], rc[N][21], v[N], c[N];
int best[N];

void init() {
  for(int i = 0; i < n; i++) {
    rv[i][0] = v[i];
    rc[i][0] = c[i];
  }
  for(int j = 1; (1 << j) <= n; j++) {
    for(int i = 0; i + (1 << j) <= n; i++) {
      rv[i][j] = max(rv[i][j - 1], rv[i + (1 << (j - 1))][j - 1]);
      rc[i][j] = min(rc[i][j - 1], rc[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int find_rv(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return max(rv[l][g], rv[r-(1<<g)+1][g]);
}

int find_rc(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return min(rc[l][g], rc[r-(1<<g)+1][g]);
}

int solve(int l, int r) {
  int vk = find_rv(l, r);
  int rk = find_rc(l, r);
  return min(100 * vk, rk);
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", v + i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  init();
  for(int i = 0; i < n; i++) {
    int l = i, r = n - 1;
    while(l + 1 < r) {
      int mid = (l + r) >> 1;
      int vk = 100 * find_rv(i, mid);
      int ck = find_rc(i, mid);
      if(vk < ck) {
        l = mid;
      } else {
        r = mid;
      }
    }
    for(int j = l; j <= r; j++) {
      best[i] = max(best[i], solve(i, j));
    }
  }
  sort(best, best + n);
  double ans = 0;
  double now = (double) k / n;
  int a = n - 1;
  int b = k - 1;
  for(int i = 0; i + k <= n; i++) {
    if(a < b) break;
    ans += now * best[i];
    now = now * (a - b) / a;
    a--;
  }
  printf("%.15f\n", ans);
  return 0;
}
