#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int inf = 5e8;

vector<int> to[N], from[N];
int d[N][N], b[N][N];
vector<pair<int, int>> go[N], back[N];
bool done[N];
int n;

void bfs(vector<int>* edge, int dist[N][N], vector<pair<int, int>>* ret) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      dist[i][j] = -inf;
    }
  }
  for(int i = 1; i <= n; i++) {
    memset(done, 0, sizeof(done));
    queue<int> q;
    done[i] = 1;
    q.push(i);
    dist[i][i] = 0;
    while(!q.empty()) {
      int now = q.front();
      q.pop();
      for(auto it : edge[now]) {
        if(!done[it]) {
          done[it] = 1;
          dist[i][it] = dist[i][now] + 1;
          q.push(it);
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i != j) {
        ret[i].emplace_back(dist[i][j], j);
      }
    }
    sort(ret[i].begin(), ret[i].end());
    reverse(ret[i].begin(), ret[i].end());
  }
}

pair<int, int> get(int p, vector<pair<int, int>>* ret, vector<int>& ojo) {
  for(auto it : ret[p]) {
    bool ada = 0;
    for(auto j : ojo) {
      if(it.second == j) {
        ada = 1;
        break;
      }
    }
    if(!ada) return it;
  }
  return {-inf, -inf};
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    to[u].push_back(v);
    from[v].push_back(u);
  }
  bfs(to, d, go);
  bfs(from, b, back);
  
  int ans = -inf, ai, aj, ak, al;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      assert(d[i][j] == b[j][i]);
      if(i == j) continue;
      vector<int> ojo = {i, j};
      pair<int, int> lef = get(i, back, ojo);
      pair<int, int> rig = get(j, go, ojo);
      vector<int> tmp;
      if(lef.second == rig.second) {
        
        tmp = {i, j, lef.second};
        pair<int, int> l = get(i, back, tmp);
        int cur = d[i][j] + l.first + rig.first;
        if(cur > ans) {
          ans = cur;
          ai = l.second;
          aj = i;
          ak = j;
          al = rig.second;
        }
        
        pair<int, int> r = get(j, go, tmp);
        cur = d[i][j] + lef.first + r.first;
        if(cur > ans) {
          ans = cur;
          ai = lef.second;
          aj = i;
          ak = j;
          al = r.second;
        }
        
      } else {
        int cur = d[i][j] + lef.first + rig.first;
        if(cur > ans) {
          ans = cur;
          ai = lef.second;
          aj = i;
          ak = j;
          al = rig.second;
        }
      }
    }
  }
  printf("%d %d %d %d\n", ai, aj, ak, al);
  return 0;
}