#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
const long long mod = 1e9 + 7;

int a[N];
char s[N];
int y[N];
int dp[N];
bool ada[N];

int main() {
  int n, m;
  scanf("%d %d %s", &n, &m, s);
  for(int i = 0; i < m; i++) {
    scanf("%d", y + i);
    y[i]--;
  }
  int len = strlen(s);
  for(int i = 1; i < len; i++) {
    int j = a[i - 1];
    while(j && s[j] != s[i]) {
      j = a[j - 1];
    }
    if(s[i] == s[j]) {
      a[i] = j + 1;
    }
  }
  int now = a[len - 1];
  while(now) {
    ada[now] = 1;
    now = a[now - 1];
  }
  int last = -1, can = 1;
  for(int i = 0; i < m; i++) {
    if(y[i] <= last) {
      int find = last - y[i] + 1;
      if(!ada[find]) {
        can = 0;
      }
    }
    dp[y[i]]++;
    dp[y[i] + len]--;
    last = y[i] + len - 1;
  }
  if(!can) {
    puts("0");
    return 0;
  }
  long long ans = 1;
  for(int i = 0; i < n; i++) {
    if(i) dp[i] += dp[i - 1];
    if(dp[i] == 0) {
      ans *= 26;
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
