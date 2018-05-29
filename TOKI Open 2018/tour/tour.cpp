#include "tour.h"
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

const int N = 305;

bool mark[N];
vector<int> adj[N];
int match[N], matched[N];

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

int getShortestTour(int n, std::vector<std::string> s) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '.') {
        adj[i].push_back(j);
      }
    }
  }
  memset(match, -1, sizeof(match));
  memset(matched, -1, sizeof(matched));
  while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 0;i < n;i ++) if(matched[i] == -1 && !mark[i])
      fnd |= dfs(i);
    if(!fnd)
      break;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) if (match[i] != -1) ans++;
  ans = min(ans, n - 1);
  return 2 * (n - 1) - ans;
}
