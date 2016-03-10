#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

char junk[105];
int a[1005], d[1005];
int dp[N];

int main() {
  scanf("%s", junk);
  int n, m, k;
  scanf("%d %d %d", &m, &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", a + i, d + i);
    a[i]--;
  }
  fill(dp, dp + N, 1e9);
  int mini = 1e9;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(d[i] == d[j]) {
        mini = min(mini, min(abs(a[i] - a[j]), m - abs(a[i] - a[j])));
      } else {
        int u = (d[i] == 1? a[i] : a[j]);
        int v = (d[i] == 1? a[j] : a[i]);
        int sh = m - u;
        u = (u + sh) % m;
        v = (v + sh) % m;
        dp[v] = 0;
        dp[(v + m) % (2 * m)] = 0;
      }
    }
  }
  queue<int> q;
  for(int i = 0; i < 2 * m; i++) {
    dp[i] = min(dp[i], mini);
    if(dp[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    int u = (now + 1) % (2 * m);
    if(dp[u] > dp[now] + 1) {
      dp[u] = dp[now] + 1;
      q.push(u);
    }
    u = (now + 2 * m - 1) % (2 * m);
    if(dp[u] > dp[now] + 1) {
      dp[u] = dp[now] + 1;
      q.push(u);
    }
  }
  while(k--) {
    int t;
    scanf("%d", &t);
    t %= m;
    printf("%d\n", dp[t << 1]);
  }
  return 0;
}
