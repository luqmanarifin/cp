#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int d[] = {0, 0, 3, 2, 4, 1};
int gmt[] = {0, 1, 10, -5, -8, 7};

int jarak(int u, int v) {
  if (u == v) return 0;
  if (u == 1) return d[v];
  else if (v == 1) return d[u];
  else return d[u] + d[v];
}

int a[N];

int main() {
  /*
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      printf("%d %d: %d\n", i, j, jarak(i, j));
    }
  }
  */
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int now = 17;
    for (int i = 1; i < n; i++) now += jarak(a[i-1], a[i]);
    now += gmt[a[n-1]] - gmt[a[0]];
    now %= 24;
    if (now < 0) now += 24;
    if (now < 12) {
      printf("%d%d.00 AM\n", now / 10, now % 10);
    } else {
      now -= 12;
      if (now == 0) {
        puts("12.00 PM");
      } else {
        printf("%d%d.00 PM\n", now / 10, now % 10);
      }
    }    
  }

  return 0;
}
