#include <bits/stdc++.h>

using namespace std;

const int N = 205;

char s[N][N];
int sum[N][N], to[N][N];
vector<int> kos[N][N];

int main() {
  freopen("fortmoo.in","r",stdin);
  freopen("fortmoo.out","w",stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      sum[i][j] = sum[i][j - 1] + (s[i][j] == 'X');
    }
  }
  for(int j = 1; j <= m; j++) {
    for(int l = j; l <= m; l++) {
      for(int i = 1; i <= n; i++) {
        if(sum[i][l] - sum[i][j - 1] == 0) {
          kos[j][l].push_back(i);
        }
      }
    }
  }
  for(int j = 1; j <= m; j++) {
    to[n + 1][j] = n + 1;
    for(int i = n; i >= 1; i--) {
      if(s[i][j] == '.') {
        to[i][j] = to[i + 1][j];
      } else {
        to[i][j] = i;
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      for(int l = j; l <= m; l++) {
        if(sum[i][l] - sum[i][j - 1]) break;
        int til = min(to[i][j], to[i][l]);
        int p = lower_bound(kos[j][l].begin(), kos[j][l].end(), til) - kos[j][l].begin() - 1;
        if(p >= 0 && i <= kos[j][l][p]) {
          ans = max(ans, (l - j + 1) * (kos[j][l][p] - i + 1));
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
