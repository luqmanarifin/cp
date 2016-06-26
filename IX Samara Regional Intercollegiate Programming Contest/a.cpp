#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N][N];
int par[N * N];
int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};

bool done[N][N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j) {
  if(!valid(i, j) || done[i][j] || s[i][j] == '#') return;
  done[i][j] = 1;
  for(int k = 0; k < 4; k++) {
    dfs(i + da[k], j + db[k]);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < N * N; i++) {
    par[i] = i;
  }
  for(int i = 0; i + 1 < n; i++) {
    for(int j = 0; j + 1 < m; j++) {
      if(s[i][j] != '.') continue;
      if(s[i + 1][j] == '.') {
        merge(i * N + j, (i + 1) * N + j);
      }
      if(s[i][j + 1] == '.') {
        merge(i * N + j, i * N + j + 1);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') {
        dfs(i, j);
        bool ada = 0;
        for(int k = 0; k < n; k++) {
          for(int l = 0; l < m; l++) {
            if(s[k][l] == '.' && !done[k][l]) {
              ada = 1;
            }
          }
        }
        if(ada) {
          puts("Impossible");
          return 0;
        }
        goto YO;
      }
    }
  }
  YO:;
  set<int> q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') {
        for(int k = 0; k < 4; k++) {
          int ki = i + da[k];
          int kj = j + db[k];
          if(valid(ki, kj) && s[ki][kj] == '?') {
            q.insert(ki * N + kj);
          }
        }
      }
    }
  }
  
  while(!q.empty()) {
    auto it = q.begin();
    int i = *it / N;
    int j = *it % N;
    q.erase(it);
    if(s[i][j] == '?') {
      vector<int> p;
      for(int k = 0; k < 4; k++) {
        int ki = i + da[k];
        int kj = j + db[k];
        if(valid(ki, kj) && s[ki][kj] == '.') {
          p.push_back(find(ki * N + kj));
        }
      }
      if(p.empty()) {
        s[i][j] = '#';
      } else {
        bool same = 1;
        sort(p.begin(), p.end());
        for(int i = 1; i < p.size(); i++) {
          if(p[i] != p[i - 1]) {
            same = 0;
          }
        }
        if(same) {
          puts("Ambiguous");
          return 0;
        }
        s[i][j] = '.';
        for(int k = 0; k < 4; k++) {
          int ki = i + da[k];
          int kj = j + db[k];
          if(valid(ki, kj) && s[ki][kj] == '.') {
            merge(i * N + j, ki * N + kj);
          }
          if(s[ki][kj] == '?') {
            q.insert(ki * N + kj);
          }
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '?') {
        s[i][j] = '#';
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%s\n", s[i]);
  }
  return 0;
}
