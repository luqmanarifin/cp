#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int match[N], matched[N], mark[N];
vector<int> adj[N];

// The code below finds a augmenting path:
bool dfs(int v){
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : adj[v])
    if(match[u] == -1 or dfs(match[u])) 
      return matched[v] = u, match[u] = v, true;
  return false;
}

vector<vector<int>> ori;
bool is[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  ori.assign(n, vector<int>(n));
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    ori[u][v] = ori[v][u] = 1;
  }
  srand(time(0));
  for (int iter = 0; iter < 140000; iter++) {
    memset(is, 0, sizeof(is));
    int kul = n / 2;
    while (kul) {
      int at = rand() % n;
      if (!is[at]) {
        is[at] = 1;
        kul--;
      }
    }
    //is[0] = is[1] = is[3] = 1;
    //is[2] = is[4] = is[5] = 0;
    //for (int i = 0; i < n; i++) printf("%d ", is[i]); printf("\n");
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      match[i] = matched[i] = -1;
      for (int j = 0; j < n; j++) {
        if (is[i] == 0 && is[j] && ori[i][j]) {
          adj[i].push_back(j);
        }
      }
    }
    while(true){
      memset(mark, false, sizeof mark);
      bool fnd = false;
      for(int i = 0;i < n;i ++) if(is[i] == 0 && matched[i] == -1 && !mark[i])
        fnd |= dfs(i);
      if(!fnd)
        break;
    }
    int ret = 0;
    for (int i = 0; i < n; i++) if (is[i] == 0 && matched[i] != -1) {
      ret++;
    }
    //printf("ret %d\n", ret);
    if (ret < n / 2) {
      puts("-1");
      return 0;
    }
  }
  puts("1");
  return 0;
}
