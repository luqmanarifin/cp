#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

class PalindromePath {
public:
  vector<vector<int>> dist;
  vector<vector<pair<int, char>>> edge;
  vector<vector<bool>> adj;
  
  int shortestLength(int n, vector<int> a, vector<int> b, string c) {
    edge.resize(n);
    dist.resize(n, vector<int>(n));
    adj.resize(n, vector<bool>(n));
    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        dist[i][j] = inf;
      }
      adj[i][i] = 1;
    }
    int m = a.size();
    for(int i = 0; i < m; i++) {
      edge[a[i]].emplace_back(b[i], c[i]);
      edge[b[i]].emplace_back(a[i], c[i]);
      adj[a[i]][b[i]] = 1;
      adj[b[i]][a[i]] = 1;
    }
    queue<pair<int, int>> q;
    dist[0][1] = 0;
    q.emplace(0, 1);
    vector<int> ans;
    while(!q.empty()) {
      int u, v;
      tie(u, v) = q.front();
      q.pop();
      int cost = dist[u][v];
      if(u == v) {
        ans.push_back(cost);
        continue;
      }
      if(adj[u][v]) {
        ans.push_back(cost + 1);
        continue;
      }
      for(auto p : edge[u]) {
        int pn = p.first;
        int pc = p.second;
        for(auto r : edge[v]) {
          int qn = r.first;
          int qc = r.second;
          if(pc == qc && dist[pn][qn] > cost + 2) {
            dist[pn][qn] = cost + 2;
            q.emplace(pn, qn);
          }          
        }
      }
    }
    sort(ans.begin(), ans.end());
    if(!ans.empty()) return ans[0];
    return -1;
  }
};
/*

int main() {
  int n = 5;
  vector<int> a = {2,2,0,3,4};
  vector<int> b = {0,1,3,4,1};
  string c = "abxyx";
  PalindromePath PalindromePath;
  cout << PalindromePath.shortestLength() << endl;
  
  return 0;
}
*/