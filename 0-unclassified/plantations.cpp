// kadalbonek
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long inf = 1e18;

long long a[N][N];
long long b[N][N], c[N][N];

int get_b(int i, int j, int len) {
  return b[i + len - 1][j + len - 1] - b[i - 1][j - 1];
}

int get_c(int i, int j, int len) {
  return c[i + len - 1][j - len + 1] - c[i - 1][j + 1];
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    
    int n, w;
    scanf("%d %d", &n, &w);
    long long mini = inf;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        scanf("%I64d", &a[i][j]);
        mini = min(mini, a[i][j]);
      }
    }
    if(w < mini) {
      puts("0");
      continue;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        b[i][j] = b[i - 1][j - 1] + a[i][j];
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = n; j >= 1; j--) {
        c[i][j] = c[i - 1][j + 1] + a[i][j];
      }
    }
    int l = 0, r = (n % 2? n : n - 1) / 2;
    while(l < r) {
      int mid = (l + r + 1) >> 1;
      int size = mid * 2 + 1;
      bool ada = 0;
      for(int i = 1; i <= n - size + 1; i++) {
        for(int j = 1; j <= n - size + 1; j++) {
          if(get_b(i, j, size) + get_c(i, j + size - 1, size) - a[i + size / 2][j + size / 2] <= w) {
            ada = 1;
            goto next;
          }
        }
      }
      next:;
      if(ada) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    int ans = l * 2 + 1;
    if(n >= 2) {
      l = 0, r = (n % 2? n - 1 : n) / 2;
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        int size = mid * 2;
        bool ada = 0;
        for(int i = 1; i <= n - size + 1; i++) {
          for(int j = 1; j <= n - size + 1; j++) {
            if(get_b(i, j, size) + get_c(i, j + size - 1, size) <= w) {
              ada = 1;
              goto nextcak;
            }
          }
        }
        nextcak:;
        if(ada) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      ans = max(ans, l * 2);
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
