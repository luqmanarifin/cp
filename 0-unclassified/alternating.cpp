#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

int dp[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      dp[i] = inf;
    }
    
    int n, k;
    scanf("%d %d %s", &n, &k, s + 1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
      bool al = 1;
      dp[i] = dp[i - 1] + 1;
      for(int j = i; j >= 1 && i - j + 1 <= k; j--) {
        if(j != i && s[j] == s[j + 1]) {
          al = 0;
        }
        if(al == 0) {
          dp[i] = min(dp[i], dp[j - 1] + 1);
        }
      }
    }
    printf("%d\n", dp[n] - 1);
  }
  
  return 0;
}
