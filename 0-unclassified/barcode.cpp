#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int a[1005][2];
char s[1005];
int dp[1005][2];

int main() {
  int n, m, x, y;
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for(int i = 0; i < n; i++) {
    scanf("%s", &s[1]);
    for(int j = 1; j <= m; j++) {
      if(s[j] == '.') a[j][0]++;
      else a[j][1]++;
    }
  }
  for(int i = 1; i <= m; i++) {
    a[i][0] += a[i - 1][0];
    a[i][1] += a[i - 1][1];
  }
  for(int i = 0; i < 1005; i++)
    for(int j = 0; j < 2; j++)
      dp[i][j] = inf;
      
      
  dp[0][0] = dp[0][1] = 0;
  for(int i = 1; i <= m; i++) {
    for(int j = x; j <= y && i - j >= 0; j++) {
      dp[i][1] = min(dp[i][1], dp[i - j][0] + a[i][1] - a[i - j][1]);
      dp[i][0] = min(dp[i][0], dp[i - j][1] + a[i][0] - a[i - j][0]);
    }
  }
  cout << min(dp[m][0], dp[m][1]) << endl;
  
  return 0;
}