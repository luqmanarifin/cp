#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int par[N][3];

int find(int u, int c) {
  if(par[u][c] != u) par[u][c] = find(par[u][c], c);
  return par[u][c];
}

void merge(int u, int v, int c) {
  u = find(u, c);
  v = find(v, c);
  par[u][c] = v;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
      par[i][0] = par[i][1] = i;
    }
    long long ans = 0;
    for(long long ev = 1; ev <= m; ev++) {
      int u, v, c;
      scanf("%d %d %d", &c, &u, &v);
      c--;
      merge(u, v, c);
      
      int cur = 0;
      for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
          if(find(i, 0) == find(j, 0) && find(i, 1) == find(j, 1)) {
            cur++;
          }
        }
      }
      ans += ev * cur;
      ans %= mod;
      //cout << "after " << ev << ' ' << cur << endl;
      //printf("after event : %d %d\n", ev, cur);
    }
    cout << ans << endl;
    cerr << tt << " done!" << endl;
  }
  
  return 0;
}
