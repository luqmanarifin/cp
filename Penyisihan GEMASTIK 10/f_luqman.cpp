
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 55;

long long dp[N][1 << 13];
char s[N];
int ada[11];
int n, dig, len;

void add(long long& a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    memset(s, 0, sizeof(s));

    scanf("%s %d %d", s + 1, &n, &dig);
    len = strlen(s + 1);
    for (int i = 1; i <= len; i++) s[i] -= 'a';
    int to = (1 << (len + 1));

    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < to; j++) {
        if (dp[i][j] == 0) continue;
        for (int k = 0; k < dig; k++) {
          for (int l = 0; l < dig; l++) {
            int cur = 1;
            if (j & (1 << len)) {
              cur |= (1 << len);
            }
            for (int m = 0; m < len; m++) {
              if (j & (1 << m)) {
                if (k == s[m+1] || l == s[m+1]) {
                  cur |= (1 << (m + 1));
                }
                if (m + 2 <= len && ((k == s[m+1] && l == s[m+2]) || (k == s[m+2] && l == s[m+1]))) {
                  cur |= (1 << (m + 2));
                }
              }
            }
            //printf("%d extend %d %d: %d\n", j, k, l, cur);
            add(dp[i + 1][cur], dp[i][j]);
          }
        }
      }
    }
    long long ans = 0;
    for (int j = 0; j < to; j++) {
      if (j & (1 << len)) {
        add(ans, dp[n][j]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
