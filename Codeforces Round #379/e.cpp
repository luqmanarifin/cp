#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
int par[N];
int done[N];
int num[N];
int u[N], v[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

vector<int> edge[N];

// siapa, panjang berapa
pair<int, int> bfs(int now) {
  memset(done, 0, sizeof(done));
  queue<int> q;
  q.push(now);
  done[now] = 1;
  int who = -1, len = -1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    who = now;
    len = done[now];
    for (auto it : edge[now]) {
      if (!done[it]) {
        done[it] = done[now] + 1;
        q.push(it);
      }
    }
  }
  return {who, len};
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", u + i, v + i);
    if (a[u[i]] == a[v[i]]) {
      merge(u[i], v[i]);
    }
  }
  int node = 0;
  for (int i = 1; i <= n; i++) {
    int root = find(i);
    if (!done[root]) {
      done[root] = 1;
      num[root] = node++;
    }
  }
  for (int i = 1; i < n; i++) {
    if (a[u[i]] != a[v[i]]) {
      edge[num[find(u[i])]].push_back(num[find(v[i])]);
      edge[num[find(v[i])]].push_back(num[find(u[i])]);
    }
  }
  int far = bfs(0).first;
  int nodes = bfs(far).second;
  cout << nodes/2 << endl;
  return 0;
}
