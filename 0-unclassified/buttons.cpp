#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int inf = 1e9;

queue<int> q;
int dp[N];

int main() {
  for(int i = 0; i < N; i++) {
    dp[i] = inf;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  dp[n] = 0;
  q.push(n);
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    if(now == m) {
      cout << dp[now] << endl;
      return 0;
    }
    if(now * 2 < N && dp[now] + 1 < dp[now * 2]) {
      q.push(now * 2);
      dp[now * 2] = dp[now] + 1;
    }
    if(now - 1 > 0 && dp[now] + 1 < dp[now - 1]) {
      q.push(now - 1);
      dp[now - 1] = dp[now] + 1;
    }
  }
  
  return 0;
}