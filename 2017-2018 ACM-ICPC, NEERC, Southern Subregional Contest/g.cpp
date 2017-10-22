#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int t[N], a[N], b[N], n, m, dir[N], s;
vector<int> g[N];
bool vis[N];

void minimize(int v) {
  for (int i : g[v]) {
    if (t[i] == 1) continue;
    if (dir[i] != -1) continue;
    if (a[i] == v)
      dir[i] = 0;
    else
      dir[i] = 1;
  }
}


void maximize(int v) {
  for (int i : g[v]) {
    if (t[i] == 1) continue;
    if (dir[i] != -1) continue;
    if (a[i] == v)
      dir[i] = 1;
    else
      dir[i] = 0;
  }
}

int get(int i) {
  if (t[i] == 1)
    return b[i];
  if (dir[i] == -1)
    return -1;
  if (dir[i] == 0)
    return a[i];
  else
    return b[i];
}

int main() {
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", t+i, a+i, b+i);
    if (t[i] == 1)
      g[a[i]].push_back(i);
    else {
      g[a[i]].push_back(i);
      g[b[i]].push_back(i);
    }
  }
  queue<int> que;
  int ans = 0;
  memset(dir, -1, sizeof dir);
  memset(vis, 0, sizeof vis);
  que.push(s);
  maximize(s);
  vis[s] = 1;
  while (!que.empty()) {
    ans++;
    int v = que.front();
    que.pop();
    for (int i : g[v]) {
      int u = get(i);
      if (u == -1 || u == v) continue;
      if (vis[u]) continue;
      maximize(u);
      que.push(u);
      vis[u] = 1;
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < m; i++) {
    if (t[i] == 1) continue;
    if (dir[i] == 1)
      printf("+");
    else
      printf("-");
  }
  ans = 0;
  memset(dir, -1, sizeof dir);
  memset(vis, 0, sizeof vis);
  que.push(s);
  minimize(s);
  vis[s] = 1;
  while (!que.empty()) {
    ans++;
    int v = que.front();
    que.pop();
    for (int i : g[v]) {
      int u = get(i);
      if (u == -1 || u == v) continue;
      if (vis[u]) continue;
      minimize(u);
      que.push(u);
      vis[u] = 1;
    }
  }
  printf("\n");
  printf("%d\n", ans);
  for (int i = 0; i < m; i++) {
    if (t[i] == 1) continue;
    if (dir[i] == 1)
      printf("+");
    else
      printf("-");
  }
  printf("\n");
  return 0;
}
