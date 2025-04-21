#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], n;
int pa[N][20], pb[N][20];

int to_add(int x, int y) {
  int l = 1, r = N;
  while (l < r) {
    int mid = (l + r) >> 1;
    int x_now = x + mid;
    int y_now = y + mid;
    if (x_now >= (y_now + 1) / 2) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
 
int jump_right(int x, int k) {
  while (k) {
    int z = __builtin_clz(k) ^ 31;
    x = pa[x][z];
    if (x > n) return N;
    k -= (1 << z);
  }
  return x;
}
 
int jump_left(int x, int k) {
  while (k) {
    int z = __builtin_clz(k) ^ 31;
    x = pb[x][z];
    if (x < 1) return 0;
    k -= (1 << z);
  }
  return x;
}
 
int find_to_right(int start) {
  int x = 0, y = 0, now = start;
  while (x == 0 || x < (y + 1) / 2) {
    int add = to_add(x, y);
    if (now + add > n) {
      return N;
    }
    int to = jump_right(now, add);
    if (to > n) return N;
    x += add;
    y += to - now;
    now = to;
  }
  return now;
}
 
int find_to_left(int start) {
  int x = 0, y = 0, now = start;
  while (x == 0 || x < (y + 1) / 2) {
    int add = to_add(x, y);
    if (now - add < 1) {
      return 0;
    }
    int to = jump_left(now, add);
    if (to < 1) return 0;
    x += add;
    y += now - to;
    now = to;
  }
  return now;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
    }
    int now = N;
    for (int i = n; i >= 0; i--) {
      pa[i][0] = now;
      if (a[i] <= k) {
        now = i;
      }
      // printf("pa %d %d: %d\n", i, 0, pa[i][0]);
    }
    now = 0;
    for (int i = 1; i <= n + 1; i++) {
      pb[i][0] = now;
      if (a[i] <= k) {
        now = i;
      }
      // printf("pb %d %d: %d\n", i, 0, pb[i][0]);
    }
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 0; i <= n + 1; i++) {
        int g = pa[i][j-1];
        pa[i][j] = (g <= n? pa[g][j-1] : N);

        int h = pb[i][j-1];
        pb[i][j] = (h >= 1? pb[h][j-1] : 0);
        // printf("pa haha %d %d: %d\n", i, j, pa[i][j]);
        // printf("pb haha %d %d: %d\n", i, j, pb[i][j]);
      }
    }

    // left & right
    int best_left = find_to_right(0);
    int best_right = find_to_left(n + 1);
    if (best_left + 1 < best_right) {
      puts("YES");
      continue;
    }

    // left & center
    int cnt = 0;
    bool found = 0;
    for (int i = 1; i < n; i++) {
      cnt += (a[i] <= k);
      int len = i;
      if (cnt >= (len + 1) / 2) {
        int rig = find_to_right(i);
        if (rig < n) {
          found = 1;
          break;
        }
      }
    }
    if (found) {
      puts("YES");
      continue;
    }

    // right & center
    cnt = 0;
    for (int i = n; i > 1; i--) {
      cnt += (a[i] <= k);
      int len = n - i + 1;
      if (cnt >= (len + 1) / 2) {
        int lef = find_to_left(i);
        if (lef > 1) {
          found = 1;
          break;
        }
      }
    }
    if (found) {
      puts("YES");
      continue;
    }

    puts("NO");
  }

  return 0;
}
