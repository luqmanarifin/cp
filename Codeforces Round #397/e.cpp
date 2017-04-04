#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N], d[N];
int b[N], dist[N], n;

int iterate(int now, int t) {
  while (t--) now = b[now];
  return now;
}

void dfs(int now, int bef) {
  dist[now] = dist[bef] + 1;
  b[now] = bef;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
  }
}

// node - distance
pair<int, int> get_farthest(int now) {
  dist[now] = 0;
  dfs(now, 0);
  int far = 0, p = -1;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > far) {
      far = dist[i];
      p = i;
    }    
  }
  return {p, far};
}

int get_middle() {
  pair<int, int> far = get_farthest(1);
  //printf("far %d %d\n", far.first, far.second);
  pair<int, int> farthest = get_farthest(far.first);
  //printf("far %d %d\n", farthest.first, farthest.second);
  //for (int i = 1; i <= n; i++) printf("%d bef %d\n", i, b[i]);
  return iterate(farthest.first, farthest.second / 2);
}

int valid(int now, int bef = 0) {
  //printf("now %d\n", now);
  vector<int> c;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    int cur = valid(it, now);
    if (cur == -1) return -1;
    c.push_back(cur + 1);
  }
  sort(c.begin(), c.end());
  c.resize(distance(c.begin(), unique(c.begin(), c.end())));
  //printf("now %d proses\n", now);
  d[now] = c;
  if (bef != 0 && c.size() > 1) return -1;
  if (bef == 0 && c.size() > 2) return -1;
  if (c.empty()) c.push_back(0);
  d[now] = c;
  return c[0];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int root = get_middle();
  //printf("root %d\n", root);
  if (valid(root) == -1) {
    puts("-1");
  } else {
    //puts("ngentot");
    int ans;
    //for (auto it : d[root]) printf("%d ", it);
    //printf("size %d\n", d[root].size());
    assert(d[root].size() <= 2);
    if (d[root].size() == 1) {
      ans = d[root][0];
    } else {
      ans = d[root][0] + d[root][1];
    }
    while (ans % 2 == 0) ans /= 2;
    printf("%d\n", ans);
  }
  return 0;
}
