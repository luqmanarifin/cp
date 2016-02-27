#include <bits/stdc++.h>

using namespace std;

const int N = 20;

long double a[N][N];
long double dp[1 << N];
bool done[1 << N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(dp, 0, sizeof(dp));
    memset(done, 0, sizeof(done));
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        double b;
        scanf("%lf", &b);
        a[i][j] = (long double) b;
      }
    }
    queue<int> q;
    done[(1 << n) - 1] = 1;
    dp[(1 << n) - 1] = 1;
    q.push((1 << n) - 1);
    while(!q.empty()) {
      int mask = q.front();
      q.pop();
      vector<int> p;
      for(int i = 0; i < n; i++) {
        if(mask & (1 << i)) {
          p.push_back(i);
        }
      }
      int pem = p.size() * (p.size() - 1) / 2;
      for(int i = 0; i < p.size(); i++) {
        for(int j = i + 1; j < p.size(); j++) {
          int u = p[i];
          int v = p[j];
          dp[mask ^ (1 << u)] += dp[mask] * a[v][u] / pem;
          dp[mask ^ (1 << v)] += dp[mask] * a[u][v] / pem;
        }
      }
      for(auto it : p) {
        int at = (mask ^ (1 << it));
        if(!done[at]) {
          q.push(at);
          done[at] = 1;
        }
      }
    }
    printf("Case %d:", tt);
    for(int i = 0; i < n; i++) printf(" %.6f", (double)dp[1 << i]); printf("\n");
  }
  
  return 0;
}
