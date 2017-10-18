#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, s1, s2;
int mini[N][20], maxi[N][20], a[N];

int to[N];

int find_min(int l, int r) {
  int g = __builtin_clz(r-l+1) ^ 31;
  return min(mini[l][g], mini[r-(1<<g)+1][g]);
}

int find_max(int l, int r) {
  int g = __builtin_clz(r-l+1) ^ 31;
  return max(maxi[l][g], maxi[r-(1<<g)+1][g]);
}

int start(int v, int d) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (find_min(1, mid) >= v - d && find_max(1, mid) <= v + d) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

bool can(int d) {
  for (int i = 1; i <= n; i++) {
    int l = i, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (find_min(i, mid) >= a[i] - d && find_max(i, mid) <= a[i] + d) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    to[i] = l;
  }
  to[0] = max(start(s1, d), start(s2, d));
  //printf("%d: ", d); printf("%d-%d ", start(s1, d), start(s2, d)); for (int i = 1; i <= n; i++) printf("%d ", to[i]); printf("\n");
  int p = 0, til = to[0];
  while (p < n) {
    til = max(til, to[p]);
    if (p == til) break;
    p++;
  }
  return p == n;
}

int main() {
  scanf("%d %d %d", &n, &s1, &s2);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), mini[i][0] = maxi[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i+(1<<j)-1 <= n; i++) {
      mini[i][j] = min(mini[i][j-1], mini[i+(1<<(j-1))][j-1]);
      maxi[i][j] = max(maxi[i][j-1], maxi[i+(1<<(j-1))][j-1]);
    }
  }
  
  int l = abs(s1 - s2), r = 1e9 + 5;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  //printf("mini maxi %d %d\n", find_min(1, 1), find_max(1, 1));
  return 0;
}
