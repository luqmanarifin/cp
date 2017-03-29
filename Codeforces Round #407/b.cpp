#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> edge[N];
int n, m;
bool vis[N], coli[N];

void dfs(int now) {
  if (vis[now]) return;
  vis[now] = 1;
  for (auto it : edge[now]) dfs(it);
}

bool connected() {
  //puts("lala");
  for (int i = 1; i <= n; i++) {
    if (edge[i].size()) {
      dfs(i);
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    //printf("%d %d\n", i, vis[i]);
    if (edge[i].size() && !vis[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  int self = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    if (u != v) {
      edge[v].push_back(u);
    } else {
      coli[u] = 1;
      self++;
    }
  }
  //puts("wtf");
  if (m < 2 || !connected()) {
    puts("0");
    return 0;
  }
  long long ans = 1LL * (m - self) * self + 1LL * self * (self - 1) / 2;
  for (int i = 1; i <= n; i++) {
    long long real_deg = edge[i].size() - coli[i];
    ans += 1LL * real_deg * (real_deg - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
