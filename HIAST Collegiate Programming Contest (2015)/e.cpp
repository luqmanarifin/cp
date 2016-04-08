#include <bits/stdc++.h>

using namespace std;

const int N = 14;

bool bad[N][N], done[N];
int a[N][N], ans, n, m, k;
int udah;

void dfs(int i, int j) {
  if(j > m) return dfs(i + 1, 1);
  if(i > n) {
    ans += udah == k;
    return;
  }
  dfs(i, j + 1);
  for(int t = 1; t <= k; t++) {
    if(!done[t] && !bad[t][a[i - 1][j]] && !bad[t][a[i][j - 1]]) {
      done[t] = 1;
      a[i][j] = t;
      udah++;
      dfs(i, j + 1);
      udah--;
      a[i][j] = 0;
      done[t] = 0;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(bad, 0, sizeof(bad));
    memset(done, 0, sizeof(done));
    memset(a, 0, sizeof(a));
    
    int p;
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for(int i = 0; i < p; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      bad[u][v] = bad[v][u] = 1;
    }
    ans = 0;
    dfs(1, 1);
    if(ans == 0) {
      puts("impossible");
    } else {
      cout << ans << endl;
    }
  }
  
  return 0;
}