#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int da[] = {0, 1, 0, -1};
int db[] = {1, 0, -1, 0};

int par[N * N], sz[N * N], n, m;
char s[N][N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if(u != v) {
    sz[u] += sz[v];
    par[v] = u;
  }
}

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int f(int i, int j) {
  return i * m + j;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      par[f(i, j)] = f(i, j);
      sz[f(i, j)] = 1;
    }
  }
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') {
        int id = f(i, j);
        for(int k = 0; k < 4; k++) {
          int ti = i + da[k];
          int tj = j + db[k];
          if(!valid(ti, tj)) continue;
          int ie = f(ti, tj);
          if(s[ti][tj] == '.') {
            merge(id, ie);
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') {
        printf(".");
        continue;
      }
      vector<pair<int, int>> p;
      for(int k = 0; k < 4; k++) {
        int ti = i + da[k];
        int tj = j + db[k];
        if(!valid(ti, tj)) continue;
        if(s[ti][tj] == '.') {
          int to = find(f(ti, tj));
          p.emplace_back(to, sz[to]);
        }
      }
      sort(p.begin(), p.end());
      p.resize(distance(p.begin(), unique(p.begin(), p.end())));
      int ans = 1;
      for(auto it : p) ans += it.second;
      printf("%d", ans % 10);
    }
    printf("\n");
  }
  return 0;
}
