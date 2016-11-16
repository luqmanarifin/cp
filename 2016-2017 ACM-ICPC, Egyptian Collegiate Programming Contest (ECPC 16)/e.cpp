#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;

vector<int> edge[N];
int dist[N];
int a[N];

int main() {
  freopen("jumping.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) edge[i].clear();
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      if (i + a[i] <= n) {
        edge[i + a[i]].push_back(i);
      }
      if (i - a[i] >= 1) {
        edge[i - a[i]].push_back(i);
      }
    }
    fill(dist, dist + N, inf);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto it : edge[now]) {
        if (dist[now] + 1 < dist[it]) {
          dist[it] = dist[now] + 1;
          q.push(it);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (dist[i] == inf) dist[i] = -1;
      printf("%d\n", dist[i]);
    }
    
  }

  return 0;
}
