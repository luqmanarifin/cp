#include <bits/stdc++.h>

using namespace std;

pair<pair<int, int>, int> p[5005];
int dp[5005];
int last[5005];

#define x first
#define y second

void backtrack(int at) {
  if(at == 0) return;
  backtrack(last[at]);
  printf("%d ", p[at].y);
}

int main() {
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  
  int n;
  scanf("%d %d %d", &n, &p[0].first.first, &p[0].first.second);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", &p[i].first.first, &p[i].first.second);
    p[i].second = i;
  }
  sort(p + 1, p + 1 + n);
  for(int i = 1; i <= n; i++) {
    int pos = -1, maxi = -1;
    for(int j = 0; j < i; j++) {
      if(p[j].x.x < p[i].x.x && p[j].x.y < p[i].x.y && dp[j] > maxi) {
        maxi = dp[j];
        pos = j;
      }
    }
    if(maxi != -1) {
      dp[i] = maxi + 1;
      last[i] = pos;
    }
  }
  int at = 0;
  for(int i = 1; i <= n; i++) {
    if(dp[i] > dp[at]) {
      at = i;
    }
  }
  cout << dp[at] << endl;
  backtrack(at);
  
  return 0;
}
