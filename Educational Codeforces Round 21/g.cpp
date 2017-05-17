#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 9;
const int PRIME = 89;
const int inf = 1e9;

char s[N], t[N];
long long h[N], power[N];
int add[N];
int dp[N][2];

long long take(int l, int r) {
  if (l > r) return 0;
  long long tmp = h[r] - h[l - 1] * power[r - l + 1] % mod;
  if (tmp < 0) tmp += mod;
  return tmp;
}

int main() {
  power[0] = 1;
  for (int i = 1; i < N; i++) power[i] = power[i-1] * PRIME % mod;
  
  scanf("%s %s", s + 1, t + 1);
  //printf("%s %s\n", s + 1, t + 1);
  int ns = strlen(s + 1);
  int nt = strlen(t + 1);
  for (int i = 1; i <= nt; i++) {
    h[i] = (h[i-1] * PRIME + t[i] - 'a' + 1) % mod;
  }
  for (int i = 1; i < nt; i++) {
    add[i] = add[i - 1];
    if (take(1, nt - i) == take(1 + i, nt)) add[i]++;
    //printf("add %d %d\n", i, add[i]);
  }
  for (int i = 0; i < N; i++) dp[i][0] = dp[i][1] = -inf;
  
  dp[0][0] = 0;
  for (int i = 1; i <= ns; i++) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    if (i >= nt) {
      bool can = 1;
      //printf("cheking %d\n", i);
      for (int j = 1; j <= nt; j++) {
        //printf("%c %c\n", s[i-nt-1+j], t[j]);
        if (s[i-nt+j] != '?' && s[i-nt+j] != t[j]) {
          can = 0;
          break;
        }
      }
      if (can) {
        for (int j = 1; j < nt; j++) {
          dp[i][1] = max(dp[i][1], dp[i-j][1] + add[j]);
        }
        dp[i][1] = max(dp[i][1], dp[i-nt][0] + 1);
        dp[i][1] = max(dp[i][1], dp[i-nt][1] + 1);
      }
    }
    //printf("dp %d: %d %d\n", i, dp[i][0], dp[i][1]);
  }  
  cout << max(dp[ns][0], dp[ns][1]) << endl;
  return 0;
}
