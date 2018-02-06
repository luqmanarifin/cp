#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> nein[N], el[N];
int par[N];
set<pair<int, int>> s;    // size, root
int ada[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if (u == v) return;
  if (el[u].size() > el[v].size()) swap(u, v);
  s.erase(make_pair(el[u].size(), u));
  s.erase(make_pair(el[v].size(), v));
  for (auto it : el[u]) {
    el[v].push_back(it);
    par[it] = v;
  }
  s.insert(make_pair(el[v].size(), v));
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    nein[u].push_back(v);
    nein[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    el[i].push_back(i);
    par[i] = i;
    s.insert(make_pair(1, i));
  }
  vector<int> done;
  //puts("sebelum");
  while (s.size() > 1) {
    //for (auto it : s) printf("%d ", it.first); printf("\n");
    int now = (s.begin())->second;
    for (auto i : el[now]) {
      for (auto it : nein[i]) {
        ada[find(it)]++;
      }
    }
    vector<int> join;
    for (auto it : s) {
      if (it.second == now) continue;
      if (1LL * el[now].size() * it.first != ada[it.second]) {
        join.push_back(it.second);
      }
      ada[it.second] = 0;
    }
    if (join.empty()) {
      //puts("join empty");
      done.push_back((s.begin())->first);
      s.erase(s.begin());
    } else {
      for (auto it : join) merge(now, it);
    }
  }
  while (!s.empty()) {
    done.push_back((s.begin())->first);
    s.erase(s.begin());
  }
  sort(done.begin(), done.end());
  printf("%d\n", done.size());
  for (auto it : done) printf("%d ", it); printf("\n");
  return 0;
}
