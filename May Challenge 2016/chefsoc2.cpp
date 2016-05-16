#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1005;

long long dp[N][N];
bool done[N][N];
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    s--;
    for(int i = 0; i < m; i++) {
      scanf("%d", a + i);
    }
    
    memset(dp, 0, sizeof(dp));
    memset(done, 0, sizeof(done));
    
    queue<pair<int, int>> q;
    done[s][0] = 1;
    dp[s][0] = 1;
    q.emplace(s, 0);
    while(!q.empty()) {
      int now, h;
      tie(now, h) = q.front();
      q.pop();
      if(h == m) break;
      {
        int e = now + a[h];
        int f = h + 1;
        if(0 <= e && e < n) {
          dp[e][f] += dp[now][h];
          dp[e][f] %= mod;
          if(!done[e][f]) {
            done[e][f] = 1;
            q.emplace(e, f);
          }
        }
      }
      {
        int e = now - a[h];
        int f = h + 1;
        if(0 <= e && e < n) {
          dp[e][f] += dp[now][h];
          dp[e][f] %= mod;
          if(!done[e][f]) {
            done[e][f] = 1;
            q.emplace(e, f);
          }
        }
      }
    }
    for(int i = 0; i < n; i++) {
      printf("%lld ", dp[i][m]);
    }
    printf("\n");
  }
  
  return 0;
}