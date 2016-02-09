#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
char s[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    bool all = 1;
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      for(int j = 0; j < m; j++) {
        if(s[i][j] == '*') {
          all = 0;
        }
      }
    }
    if(all) {
      puts("0");
      continue;
    }
    int ma = -1, mb = -1, na = N, nb = N;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(s[i][j] == '*') {
          ma = max(ma, i);
          mb = max(mb, j);
          na = min(na, i);
          nb = min(nb, j);
        }
      }
    }
    int la = ma - na + 1;
    int lb = mb - nb + 1;
    printf("%d\n", 1 + max(la, lb) / 2);
  }
  return 0;
}
