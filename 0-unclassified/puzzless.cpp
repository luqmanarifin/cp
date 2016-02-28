#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int dp[26][26];
char s[N];

int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    scanf("%s", s);
    int len = strlen(s);
    int from = s[0] - 'a';
    int to = s[len - 1] - 'a';
    int tmp[26];
    for(int i = 0; i < 26; i++) {
      tmp[i] = 0;
      if(i == from || dp[i][from]) {
        tmp[i] = dp[i][from] + len;
      }
    }
    for(int i = 0; i < 26; i++) {
      dp[i][to] = max(dp[i][to], tmp[i]);
    }
  }
  int ans = 0;
  for(int i = 0; i < 26; i++) {
    ans = max(ans, dp[i][i]);
  }
  cout << ans << endl;
  return 0;
}
