#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

vector<int> edge[N];

int ans[N];
vector<pair<int, int>> que[N];    // ke - id

int dist[2][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int queries;
  scanf("%d", &queries);
  for (int i = 0; i < queries; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    que[u].emplace_back(v, i);
  }
  
  for (int st = 1; st <= n; st++) {
    if (que[st].empty()) continue;
    fill(dist[0], dist[0] + N, inf);
    fill(dist[1], dist[1] + N, inf);
    
    queue<pair<int, int> > q;
    dist[0][st] = 0;
    q.emplace(0, st);
    while (!q.empty()) {
      int s, now;
      tie(s, now) = q.front();
      q.pop();
      for (auto it : edge[now]) {
        if (dist[s^1][it] > dist[s][now] + 1) {
          dist[s^1][it] = dist[s][now] + 1;
          q.emplace(s^1, it);
        }        
      }
    }
    for (auto it : que[st]) {
      int to, id;
      tie(to, id) = it;
      ans[id] = dist[0][to];
    }
  }
  for (int i = 0; i < queries; i++) {
    if (ans[i] == inf) {
      puts("NO");
    } else {
      printf("%d\n", ans[i] / 2);
    }
  }
  return 0;
}
