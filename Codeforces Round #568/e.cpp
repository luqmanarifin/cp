#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

char s[N][N];
char sim[N][N];
pair<int, int> mn[26], mx[26];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 26; i++) {
      mn[i] = mx[i] = make_pair(-1, -1);
    }
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int maxi = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] != '.') {
          int c = s[i][j] - 'a';
          auto p = make_pair(i, j);
          if (mn[c].first == -1) {
            mn[c] = p;
            mx[c] = p;
          } else {
            mn[c] = min(mn[c], p);
            mx[c] = max(mx[c], p);
          }
          maxi = max(maxi, c);
        }          
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sim[i][j] = '.';
      }
    }
    for (int k = 0; k < 26; k++) {
      // printf("%d %d %d %d\n", mn[k].first+1, mn[k].second+1, mx[k].first+1, mx[k].second+1);
      if (mn[k].first == -1) continue;
      if (mn[k].first != mx[k].first) {
        for (int i = mn[k].first; i <= mx[k].first; i++) {
          sim[i][mn[k].second] = (k + 'a');
        }
      } else {
        for (int j = mn[k].second; j <= mx[k].second; j++) {
          sim[mn[k].first][j] = (k + 'a');
        }
      }

      // for (int i = 0; i < n; i++) {
      //   for (int j = 0; j < m; j++) {
      //     printf("%c", sim[i][j]);
      //   }
      //   printf("\n");
      // }
      // printf("\n");
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] != sim[i][j]) {
          ok = 0;
        }
      }
    } 
    if (!ok) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    printf("%d\n", maxi + 1);
    for (int i = 0; i <= maxi; i++) {
      if (mn[i].first == -1) {
        printf("%d %d %d %d\n", mn[maxi].first+1, mn[maxi].second+1, mx[maxi].first+1, mx[maxi].second+1);
        continue;
      }
      printf("%d %d %d %d\n", mn[i].first+1, mn[i].second+1, mx[i].first+1, mx[i].second+1);
    }
  }

  return 0;
}
