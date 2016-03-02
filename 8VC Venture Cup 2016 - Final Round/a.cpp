#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[N][N];

int main() {
  int r, c, n, mini;
  scanf("%d %d %d %d", &r, &c, &n, &mini);
  for(int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u][v] = 1;
  }
  int ans = 0;
  //printf("COK %d\n", k);
  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
      for(int k = i; k <= r; k++) {
        for(int l = j; l <= c; l++) {
          int cnt = 0;
          for(int p = i; p <= k; p++) {
            for(int q = j; q <= l; q++) {
              cnt += a[p][q];
            }
          }
          //printf("%d %d %d %d %d\n", i, j, k, l, cnt);
          ans += (cnt >= mini);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
