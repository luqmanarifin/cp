#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<int> edge[N];
vector<pair<int, int>> edges;
vector<int> a;

void dfs(int now, int bef = -1) {
  if (bef != -1) {
    edges.emplace_back(bef, now);
  }
  for (auto it : edge[now]) {
    if (bef == it) continue;
    dfs(it, now);
  }
}

int ask(int l, int r) {
  set<int> s;
  for (int i = l; i <= r; i++) s.insert(a[i]);
  printf("? %d", s.size());
  for (auto it : s) printf(" %d", it);
  printf("\n");
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v;
}

void answer(int u, int v) {
  printf("! %d %d\n", u, v);
  fflush(stdout);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1);
  for (int i = 0; i < edges.size(); i++) {
    if (i == 0 || edges[i-1].second != edges[i].first) {
      a.push_back(edges[i].first);
    }
    a.push_back(edges[i].second);
  }
  int l = 0, r = a.size() - 1;
  int all = ask(l, r);
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (ask(l, mid) == all) {
      r = mid;
    } else {
      l = mid;
    }
  }
  answer(a[l], a[r]);
  return 0;
}
