#include <bits/stdc++.h>

using namespace std;

int a[105][105];

int main() {
  int k, n, m;
  scanf("%d %d %d", &k, &n, &m);
  if(k > n * m) return puts("-1") * 0;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(i % 2) {
      for(int j = 0; j < m; j++) {
        cnt++;
        if(cnt <= k) {
          a[i][j] = cnt;
        }
      }
    } else {
      for(int j = m - 1; j >= 0; j--) {
        cnt++;
        if(cnt <= k) {
          a[i][j] = cnt;
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
