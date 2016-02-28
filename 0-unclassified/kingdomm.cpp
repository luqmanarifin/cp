#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 1e4 + 1e3;

vector<int> edge[N], cap[N], c[N];
int p[N], dist[N];
int s, t;
int mincost;

int id(int from, int to) {
  return lower_bound(edge[from].begin(), edge[to].end(), to) - edge[from].begin();
}

int main() {
  int a, b, h;
  scanf("%d %d %d", &n, &m, &h);
  s = a + b + h;
  t = s + 1;
  int n = t + 1;
  for(int i = 0; i < h; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    edge[i].push_back(h + u);
    edge[i].push_back(h + a + v);
    edge[h + u].push_back(i);
    edge[h + a + v].push_back(i);
  }
  for(int i = 0; i < h; i++) {
    edge[s].push_back(i);
    edge[i].push_back(s);
  }
  for(int i = 0; i < a; i++) {
    edge[h + i].push_back(t);
    edge[t].push_back(h + i);
  }
  for(int i = 0; i < b; i++) {
    edge[h + a + i].push_back(t);
    edge[t].push_back(h + a + i);
  }
  for(int i = 0; i < n; i++) {
    sort(edge[i].begin(), edge[i].end());
    cap[i].resize(edge[i].size());
    c[i].resize(edge[i].size());
  }
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < edge[i].size(); j++) {
      if(edge[i][j] != s && edge[i][j] != t) {
        int to = edge[i][j];
        c[i][j] = 1;
        c[to][id(to, i)] = -1;
        cap[i][j] = inf;
      }
    }
  }
  for(int i = h; i < h + a; i++) {
    cap[i].back() = inf;
  }
  for(int i = h + a; i < h + a + b; i++) {
    cap[i].back() = inf;
  }
  int mf = 0;
  for(int i = 0; i < h; i++) {
    cap[s][id(s, i)] = 1;
    while(1) {
      for(int i = 0; i < n; i++) {
        p[i] = -1;
        dist[i] = inf;
      }
      dist[s] = 0;
      
      set<pair<int, int>> pq;
      pq.insert(make_pair(dist[s], s));
      while(!pq.empty()) {
        auto it = pq.begin();
        int cost = it->first;
        int now = it->second;
        pq.erase(it);
        if(dist[now] != cost) continue;
        if(now == t) break;
        for(int j = 0; j < edge[now].size(); j++) {
          int ncos = cost + c[now][j];
          int near = edge[now][j];
          if(cap[now][j] > 0 && ncos < dist[near]) {
            pq.erase(make_pair(dist[near], near));
            dist[near] = ncos;
            p[near] = now;
            pq.insert(make_pair(dist[near], near));
          }
        }
      }
      assert(mf == i + 1);
      augment(t, inf);
    }
  }
  return 0;
}
