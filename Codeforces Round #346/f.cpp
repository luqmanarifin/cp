#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};

long long k;
int n, m;
int a[N][N];

int u[N * N], v[N * N], pt, lim;
bool vis[N][N];

int ans[N][N];

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

void dfs(int i, int j) {
  if(!valid(i, j) || vis[i][j] || a[i][j] < lim) return;
  u[pt] = i;
  v[pt] = j;
  pt++;
  vis[i][j] = 1;
  for(int p = 0; p < 4; p++) {
    int ta = i + da[p];
    int tb = j + db[p];
    dfs(ta, tb);
  }
}

int rem;

void fill(int i, int j) {
  if(!valid(i, j) || vis[i][j] || a[i][j] < lim || rem == 0) return;
  vis[i][j] = 1;
  ans[i][j] = lim;
  rem--;
  for(int p = 0; p < 4; p++) {
    int ta = i + da[p];
    int tb = j + db[p];
    fill(ta, tb);
  }
}

int main() {
  scanf("%d %d %I64d", &n, &m, &k);
  set<int> can;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      if(k % a[i][j] == 0 && k / a[i][j] <= n * m) {
        can.insert(a[i][j]);
      }
    }
  }
  for(auto it : can) {
    memset(vis, 0, sizeof(vis));
    lim = it;
    int need = k / it;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        pt = 0;
        dfs(i, j);
        bool ada = 0;
        for(int p = 0; p < pt; p++) {
          if(a[u[p]][v[p]] == it) {
            ada = 1;
          }
        }
        if(pt >= need && ada) {
          puts("YES");
          memset(vis, 0, sizeof(vis));
          rem = need;
          for(int p = 0; p < pt; p++) {
            if(a[u[p]][v[p]] == it) {
              fill(u[p], v[p]);
            }
          }
          for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
              printf("%d ", ans[i][j]);
            }
            printf("\n");
          }
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}
