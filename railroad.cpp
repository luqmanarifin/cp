#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edgeu[N], edged[N], edge[N];
int to[N];
int f[N], up[N], down[N];
int a[N], b[N];
int dist[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(to, 0, sizeof(to));
    memset(f, 0, sizeof(f));
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(dist, 0, sizeof(dist));
    for(int i = 0; i < N; i++) {
      edge[i].clear();
      edgeu[i].clear();
      edged[i].clear();
    }
    
    int fork = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
      char c;
      int x, y, z;
      scanf(" %c %d %d %d", &c, &x, &y, &z);
      if(c == 'F') {
        fork++;
        edgeu[x].push_back(y);
        edged[x].push_back(z);
        to[y]++; to[z]++;
        f[x] = fork;
        a[fork] = y;
        b[fork] = z;
      } else {
        edgeu[x].push_back(z);
        edged[y].push_back(z);
        to[z] += 2;
      }
    }
    stack<int> st;
    for(int i = 1; i <= n; i++) {
      if(to[i] == 0) {
        st.push(i);
      }
    }
    up[1] = 1;
    down[1] = 2;
    int node = 2;
    while(!st.empty()) {
      int now = st.top();
      st.pop();
      if(f[now]) {
        ++node;
        down[a[f[now]]] = node;
        up[b[f[now]]] = node;
      }
      edge[up[now]].push_back(down[now]);
      for(auto it : edgeu[now]) {
        up[it] = up[now];
        to[it]--;
        if(to[it] == 0) {
          st.push(it);
        }
      }
      for(auto it : edged[now]) {
        down[it] = down[now];
        to[it]--;
        if(to[it] == 0) {
          st.push(it);
        }
      }
    }
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    while(!pq.empty()) {
      int cost, now;
      tie(cost, now) = pq.top();
      pq.pop();
      if(dist[now] != cost) continue;
      for(auto it : edge[now]) {
        int ncos = cost + 1;
        if(ncos > dist[it]) {
          dist[it] = ncos;
          pq.emplace(ncos, it);
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= node; i++) {
      ans = max(ans, dist[i]);
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
