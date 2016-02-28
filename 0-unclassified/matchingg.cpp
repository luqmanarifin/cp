#include <bits/stdc++.h>

using namespace std;

const long long prime = 71;
const long long mod = 2e9 + 89;

// 0 normal, 1 kebalik
long long h[1005][505][2];
char s[1005][505];
int len[1005];
long long power[505];

int main() {
  power[0] = 1;
  for(int i = 1; i < 505; i++) {
    power[i] = power[i - 1] * prime % mod;
  }
  
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i] + 1);
      len[i] = strlen(s[i] + 1);
    }
    for(int i = 0; i < n; i++) {
      h[i][0][0] = h[i][len[i] + 1][1] = 0;
      for(int j = 1; j <= len[i]; j++) {
        h[i][j][0] = (h[i][j - 1][0] * prime + s[i][j] - 'a' + 1) % mod;
      }
      for(int j = len[i]; j >= 1; j--) {
        h[i][j][1] = (h[i][j + 1][1] * prime + s[i][j] - 'a' + 1) % mod;
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i == j) continue;
        int m = min(len[i], len[j]);
        
        if(h[i][m][0] == h[j][len[j] - m + 1][1]) {
          int leni = len[i] - m;
          long long li = (h[i][m + leni/2][0] - h[i][m][0] * power[leni/2]) % mod;
          long long ri = h[i][len[i] - leni/2 + 1][1];
          if(li < 0) li += mod;
          
          int lenj = len[j] - m;
          long long lj = h[j][lenj / 2][0];
          long long rj = (h[j][len[j]-m+1-lenj/2][1] - h[j][len[j]-m+1][1] * power[lenj/2]) % mod;
          if(rj < 0) rj += mod;
          
          if(li == ri && lj == rj) {
            //printf("%s %s %d %d\n", s[i] + 1, s[j] + 1, h[i][m][0], h[j][len[j] - m + 1][1]);
            ans++;
          }
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
