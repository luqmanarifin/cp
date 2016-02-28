#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int x[N], y[N][N], z[N];
int a[N], b[N][N], c[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(z, 0, sizeof(z));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    
    int n;
    scanf("%d %s", &n, s + 1);
    
    for(int i = 1; i <= n; i++) {
      x[i] = x[i - 1];
      a[i] = a[i - 1];
      if(s[i] == 'S') x[i]++;
      if(s[i] == 'P') a[i]++;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = i; j <= n; j++) {
        y[i][j] = y[i][j - 1];
        b[i][j] = b[i][j - 1];
        if(s[j] == 'R') y[i][j]++;
        if(s[j] == 'S') b[i][j]++;
      }
    }
    for(int i = n; i >= 1; i--) {
      z[i] = z[i + 1];
      c[i] = c[i + 1];
      if(s[i] == 'P') z[i]++;
      if(s[i] == 'R') c[i]++;
    }

    
    int ans = 0;
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= n && i + j <= n; j++) {
        int me = x[i] + y[i + 1][i + j] + z[i + j + 1];
        int you = a[i] + b[i + 1][i + j] + c[i + j + 1];
        if(me > you) {
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
