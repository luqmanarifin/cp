#include <bits/stdc++.h>

using namespace std;

const int N = 320;

int a[N][N];
int num[N * N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
    for(int j = 1; j < N; j++) {
      a[i % j][j] += num[i];
    }
  }
  while(q--) {
    int p, q;
    scanf("%d %d", &p, &q);
    if(q < N) {
      printf("%d\n", a[p][q]);
    } else {
      int ans = 0;
      for(int i = p; i < n; i += q) {
        ans += num[i];
      }
      printf("%d\n", ans);
    }
  }
  
  return 0;
}
