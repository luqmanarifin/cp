#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char sa[N], sb[N];
int dp[N][N];
bool big[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    
    scanf("%s %s", sa, sb);
    int na = strlen(sa);
    int nb = strlen(sb);
    for (int i = 0; i < na; i++) {
      big[i] = ('A' <= sa[i] && sa[i] <= 'Z');
    }
    transform(sa, sa + na, sa, ::toupper);
    transform(sb, sb + nb, sb, ::toupper);
    dp[0][0] = 1;
    for (int i = 0; i < na; i++) {
      for (int j = 0; j < nb; j++) {
        if (dp[i][j] == 0) continue;
        if (big[i]) {
          if (sa[i] == sb[j]) {
            dp[i + 1][j + 1] = 1;
          }
        } else {
          dp[i + 1][j] = 1;
          if (sa[i] == sb[j]) {
            dp[i + 1][j + 1] = 1;
          }
        }
      }
    }
    int last = -1;
    for (int i = 0; i < na; i++) {
      if (big[i]) last = i;
    }    
    bool yes = 0;
    for (int i = last + 1; i <= na; i++) {
      yes |= dp[i][nb];
    }
    puts(yes? "YES" : "NO");
  }

  return 0;
}
