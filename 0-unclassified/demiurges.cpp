#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

// 0 sekecil mungkin, 1 segede mungkin
int a[N][2], b[N], h[N];
vector<int> edge[N];

void dfs(int now, int p) {
  h[now] = h[p] + 1;
  bool ada = 0;
  for(auto it : edge[now]) {
    if(it == p) continue;
    dfs(it, now);
    b[now] += b[it];
    ada = 1;
  }
  if(!ada) {
    a[now][0] = a[now][1] = b[now] = 1;
  }
}

void build(int now, int p) {
  int maks = -inf, mini = inf;
  int ada = 0, sum = 0;
  for(auto it : edge[now]) {
    if(it == p) continue;
    build(it, now);
    if(h[now] % 2) {
      mini = min(mini, b[it] - a[it][1]);
      sum += a[it][0];
    } else {
      mini = min(mini, a[it][0]);
      sum += b[it] - a[it][1];
    }
    ada++;
  }
  if(!ada) return;
  if(h[now] % 2) {
    a[now][0] = sum;
    a[now][1] = b[now] - mini;
  } else {
    a[now][0] = mini;
    a[now][1] = b[now] - sum - ada + 1;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  build(1, 0);
  printf("%d %d\n", a[1][1], a[1][0]);
  return 0;
}
