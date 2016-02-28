#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int par[N][2];

int find(int u, int c) {
  if(par[u][c] != u) par[u][c] = find(par[u][c], c);
  return par[u][c];
}

void merge(int u, int v, int c) {
  par[find(u, c)][c] = v;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
      par[i][0] = par[i][1] = i;
    }
    long long ans = 0;
    for(long long ev = 1; ev <= m; ev++) {
      int u, v, t;
      scanf("%d %d %d", &t, &u, &v);
      t--;
      merge(u, v, t);
      
      int cur = 0;
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          if(i == j) {
            continue;
          }
          if(find(i, 0) == find(j, 0) && find(i, 1) == find(j, 1)) {
            cur++;
          }
        }
      }
      ans += ev * cur;
    }
    cout << ans << endl;
  }
  
  return 0;
}
