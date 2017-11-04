#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e4 + 5;
const int mod = 1e9 + 7;

/*
perlu tau:
- ada string, nimnya berapa
- panjang len, validnya berapa
- panjang len, nim x, ada berapa
*/

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int dp[N][26][32][2]; 
int cnt[N][32];

int ans[32], tmp[32];

// bit, grundy
int lift[40][32];
char s[N];

main() {
  for (int j = 0; j < 26; j++) {
    dp[1][j][25 - j][1]++;
    dp[1][j][0][0]++;
  }
  for (int i = 1; i + 1 < N; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 32; k++) {
        
        for (int l = 0; l <= j; l++) {
          add(dp[i + 1][l][k ^ (j - l)][1], dp[i][j][k][0]);
          add(dp[i + 1][l][k][0], dp[i][j][k][1]);
        }
        
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 32; k++) {
        add(cnt[i][k], dp[i][j][k][1]);
      }
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 32; j++) {
      add(cnt[i][j], cnt[i - 1][j]);
    }
  }
  
  int t;
  scanf("%lld", &t);
  while (t--) {
    int n, l;
    scanf("%lld %lld %s", &n, &l, s);
    for (int i = 0; i < 32; i++) {
      lift[0][i] = cnt[l][i];
      //printf("%lld: %lld\n", i, lift[0][i]);
    }
    for (int i = 0; i + 1 < 40; i++) {
      for (int j = 0; j < 32; j++) lift[i + 1][j] = 0;
      for (int j = 0; j < 32; j++) {
        for (int k = 0; k < 32; k++) {
          lift[i + 1][j ^ k] += 1LL * lift[i][j] * lift[i][k];
          lift[i + 1][j ^ k] %= mod;
        }
      }
    }
    n--;
    
    int nim = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      if (i % 2 == 0) {
        if (i + 1 < len) {
          nim ^= s[i + 1] - s[i];
        } else {
          nim ^= 'z' - s[i];
        }
      }
    }
    //printf("nim %d\n", nim);
    memset(ans, 0, sizeof(ans));
    ans[nim] = 1;
    for (int i = 0; i < 31; i++) {
      if (n & (1 << i)) {
        memset(tmp, 0, sizeof(tmp));
        for (int j = 0; j < 32; j++) {
          for (int k = 0; k < 32; k++) {
            tmp[j ^ k] += 1LL * ans[j] * lift[i][k];
            tmp[j ^ k] %= mod;
          }
        }
        for (int j = 0; j < 32; j++) {
          ans[j] = tmp[j];
        }
      }
    }
    int pipin = 0;
    for (int i = 1; i < 32; i++) add(pipin, ans[i]);
    
    printf("%lld\n", pipin);
  }
  return 0;
}