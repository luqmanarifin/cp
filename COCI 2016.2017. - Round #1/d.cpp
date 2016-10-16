#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> edge[N];
vector<pair<int, int>> edges;
int a[N];
bool done[N];
int h[N];

// return where - distance
pair<int, int> bfs(int from, int flag) {
  set<int> vis;
  queue<int> q;
  
  q.push(from);
  h[from] = 0;
  vis.insert(from);
  //puts("iter");
  
  int last, dist;
  while (!q.empty()) {
    int now = q.front();
    //printf("%d\n", now);
    q.pop();
    last = now;
    dist = h[now];
    done[now] = flag;
    for (auto it : edge[now]) {
      if (!vis.count(it)) {
        vis.insert(it);
        h[it] = h[now] + 1;
        q.push(it);
      }
    }
  }
  return make_pair(last, dist);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edges.emplace_back(u, v);
  }
  int mini = 1e9 + 5;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    mini = min(mini, a[i]);
  }
  bool ada = 0;
  for (auto it : edges) {
    int u = it.first;
    int v = it.second;
    if (a[u] == 1 && a[v] == 1) {
      edge[u].push_back(v);
      edge[v].push_back(u);
      ada = 1;
    }
  }
  if (!ada) {
    printf("%d/1\n", mini);
    return 0;
  }
  int best = 0;
  for (int i = 1; i <= n; i++) {
    if (done[i]) continue;
    //printf("%d size %d\n", i, edge[i].size());
    int far, dist;
    tie(far, dist) = bfs(i, 0);
    //printf("far %d: %d\n", i, far);
    tie(far, dist) = bfs(far, 1);
    best = max(best, dist);
  }
  printf("1/%d\n", best + 1);
  return 0;
}
