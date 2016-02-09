#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N][N];
int l[N][N], r[N][N], u[N][N], d[N][N];
int e[N][N], f[N][N], g[N][N], h[N][N];
int n, m;

int pe[N][N], pf[N][N], pg[N][N], ph[N][N];
int pl[N][N], pr[N][N], pu[N][N], pd[N][N];
bool done[N][N];

void build() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      l[i][j] = r[i][j] = u[i][j] = d[i][j] = (s[i][j] == '#');
      e[i][j] = f[i][j] = g[i][j] = h[i][j] = (s[i][j] == '#');
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      l[i][j] += l[i][j - 1];
      u[i][j] += u[i - 1][j];
      if(s[i][j] == '.') {
        l[i][j] = 0;
        u[i][j] = 0;
      }
    }
  }
  for(int i = n; i >= 1; i--) {
    for(int j = m; j >= 1; j--) {
      r[i][j] += r[i][j + 1];
      d[i][j] += d[i + 1][j];
      if(s[i][j] == '.') {
        r[i][j] = 0;
        d[i][j] = 0;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      e[i][j] = max(e[i][j], min(l[i][j], e[i - 1][j] + 1));
      f[i][j] = max(f[i][j], min(r[i][j], f[i - 1][j] + 1));
    }
  }
  for(int i = n; i >= 1; i--) {
    for(int j = m; j >= 1; j--) {
      g[i][j] = max(g[i][j], min(r[i][j], g[i + 1][j] + 1));
      h[i][j] = max(h[i][j], min(l[i][j], h[i + 1][j] + 1));
    }
  }
  /*
  printf("\nE:\n");
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      printf("%d", e[i][j]);
    }
    printf("\n");
  }
  printf("\nF:\n");
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      printf("%d", f[i][j]);
    }
    printf("\n");
  }
  printf("\nG:\n");
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      printf("%d", g[i][j]);
    }
    printf("\n");
  }
  printf("\nH:\n");
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      printf("%d", h[i][j]);
    }
    printf("\n");
  }
  */
}

bool bisa(int len) {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      pe[i][j] = pf[i][j] = pg[i][j] = ph[i][j] = 0;
      pl[i][j] = pr[i][j] = pu[i][j] = pd[i][j] = 0;
      done[i][j] = 0;
      
      if(e[i][j] >= len) pe[i][j] = len;
      if(f[i][j] >= len) pf[i][j] = len;
      if(g[i][j] >= len) pg[i][j] = len;
      if(h[i][j] >= len) ph[i][j] = len;
      /*
      if(len == 4) {
        if(pe[i][j] or pf[i][j] or pg[i][j] or ph[i][j]) {
          printf("o");
        } else {
          printf(".");
        }
      }
      */
    }
    //printf("\n");
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      ph[i][j] = max(ph[i][j], ph[i - 1][j] - 1);
      pg[i][j] = max(pg[i][j], pg[i - 1][j] - 1);
      pl[i][j] = ph[i][j];
      pr[i][j] = pg[i][j];
    }
  }
  for(int i = n; i >= 1; i--) {
    for(int j = m; j >= 1; j--) {
      pe[i][j] = max(pe[i][j], pe[i + 1][j] - 1);
      pf[i][j] = max(pf[i][j], pf[i + 1][j] - 1);
      pl[i][j] = max(pl[i][j], pe[i][j]);
      pr[i][j] = max(pr[i][j], pf[i][j]);
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      pr[i][j] = max(pr[i][j], pr[i][j - 1] - 1);
      if(pr[i][j]) done[i][j] = 1;
    }
  }
  for(int i = n; i >= 1; i--) {
    for(int j = m; j >= 1; j--) {
      pl[i][j] = max(pl[i][j], pl[i][j + 1] - 1);
      if(pl[i][j]) done[i][j] = 1;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(s[i][j] == '#' && done[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  bool ada = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for(int j = 1; j <= m; j++) {
      if(s[i][j] == '#') {
        ada = 1;
      }
    }
  }
  assert(ada);
  //printf("\n");
  build();
  int lef = 1, rig = min(n, m);
  while(lef < rig) {
    int mid = (lef + rig + 1) >> 1;
    if(bisa(mid)) {
      lef = mid;
    } else {
      rig = mid - 1;
    }
  }
  cout << lef << endl;
  return 0;
}
