
#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int match[N], matched[N], mark[N];
int lx[N], ly[N], rx[N], ry[N], pl, pr;
int n, m, x, y;
vector<int> adj[N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool valid(int i, int j) {
  if (i == 0 && j < x) return 0;
  if (i == n - 1 && j >= m - y) return 0;
  return 0 <= i && i < n && 0 <= j && j < m;
}

// The code below finds a augmenting path:
bool dfs(int v){// v is in X, it returns true if and only if there is an augmenting path starting from v
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : adj[v])
    if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return matched[v] = u, match[u] = v, true;
  return false;
}

int id(int i, int j) {
  return (i * m + j) / 2;
}

int main() {
  memset(match, -1, sizeof(match));
  memset(matched, -1, sizeof(matched));
  
  scanf("%d %d %d %d", &n, &m, &x, &y);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v = id(i, j);
      if ((i + j) % 2 == 0) {
        lx[pl] = i;
        ly[pl] = j;
        pl++;
      } else {
        rx[pr] = i;
        ry[pr] = j;
        pr++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!valid(i, j)) continue;
      int ori = i + j;
      if (ori % 2) continue;
      for (int k = 0; k < 4; k++) {
        int tx = i + dx[k];
        int ty = j + dy[k];
        if (!valid(tx, ty)) continue;
        //printf("%d %d: %d %d\n", i, j, tx, ty);
        adj[id(i, j)].push_back(id(tx, ty));
      }
    }
  }
  
  while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 0;i < pl;i ++) {
      int x = lx[i];
      int y = ly[i];
      if (!valid(x, y)) continue;
      if(matched[i] == -1 && !mark[i])
        fnd |= dfs(i);
    }
    if(!fnd)
      break;
  } 
  int all = n * m - x - y;
  int pairs = 0;
  for (int i = 0; i < pl; i++) {
    if (!valid(lx[i], ly[i])) continue;
    if (matched[i] != -1) pairs++;
  }
  if (pairs * 2 != all) {
    puts("NO");
  } else {
    puts("YES");
    printf("%d\n", pairs);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!valid(i, j)) continue;
        int ori = i + j;
        if (ori % 2 == 0) {
          int v = id(i, j);
          printf("%d %d %d %d\n", i + 1, j + 1, rx[matched[v]] + 1, ry[matched[v]] + 1);
        }
      }
    }
  }
  return 0;
}
