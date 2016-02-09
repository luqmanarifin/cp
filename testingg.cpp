#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int p[N * N];
char s[N][N];

int main() {
  int tt = 1001;
  long long state = 0;
  int nx = 0, mx = 0, gx = 0, cx = 0;
  while(tt--) {
    int n, m, k;
    scanf("%d %d %d", &m, &n, &k);
    nx = max(nx, n);
    mx = max(mx, m);
    int g = 0;
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      for(int j = 0; j < m; j++) {
        if(s[i][j] == 'E') {
          g++;
        }
      }
    }
    cx = max(cx, k);
    gx = max(gx, k);
    state += 1LL * n * m * (1 << k) * (1 << g);
    //printf("%d %d %d\n", n, m, (1 << k));
  }
  printf("%d\n", scanf("%d", &tt));
  assert(scanf("%d", &tt));
  cout << state << endl;
  printf("%d %d %d %d", nx, mx, cx, gx);
  return 0;
}
