#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

bool done[N];
vector<int> c_h, h_c, h_h;
vector<pair<int, int>> c_c;

int c_need_h[N];
int h_need_c[N];
int c_need_c[N];
int h_need_h[N];

void die() {
  puts("Anggrek </3");
  exit(0);
}
int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

set<int> edge[N];

int main() {
  for (int i = 0; i < N; i++) par[i] = i;

  int n;
  scanf("%d", &n);
  int edges = 0;
  for (int i = 0; i < n; i++) {
    char c, b;
    scanf(" %c", &c);
    if (c == 'C') {
      edges += 4;
      for (int j = 0; j < 4; j++) {
        scanf(" %c", &b);
        if (b == 'C') {
          c_need_c[i]++;
        } else {
          c_need_h[i]++;
        }
      }
    } else {
      edges += 1;
      scanf(" %c", &b);
      if (b == 'C') {
        h_need_c[i]++;
      } else {
        h_need_h[i]++;
      }
    }
  }
  if (edges % 2) die();
  for (int i = 0; i < n; i++) {
    if (c_need_h[i]) {
      c_h.push_back(i);
    }
    if (h_need_c[i]) {
      h_c.push_back(i);
    }
    if (h_need_h[i]) {
      h_h.push_back(i);
    }
    if (c_need_c[i]) {
      c_c.emplace_back(c_need_c[i], i);
    }
  }
  sort(c_c.begin(), c_c.end());
  reverse(c_c.begin(), c_c.end());
  while (!c_h.empty() && !h_c.empty()) {
    int a = c_h.back();
    int b = h_c.back();
    c_h.pop_back();
    h_c.pop_back();
    c_need_h[a]--;
    h_need_c[b]--;
    merge(a, b);
    if (c_need_h[a]) c_h.push_back(a);
    if (h_need_c[b]) h_c.push_back(b); 
  }
  while (h_h.size() >= 2) {
    int a = h_h.back();
    h_h.pop_back();
    int b = h_h.back();
    h_h.pop_back();
    merge(a, b);
  }
  int ada = c_c.size();
  if (ada) {
    int deg_max = c_c[0].first;
    if (ada < deg_max + 1) die();
    int edges = 0;
    for (auto it : c_c) edges += it.first;
    edges /= 2;
    int comp = c_c.size() - edges;
    if (comp < 1) comp = 1;
    int root = c_c[comp - 1].second;
    for (int i = comp - 1; i < c_c.size(); i++) {
      merge(root, c_c[i].second);
    }
    c_c.clear();
  }
  if (h_h.size() || c_c.size() || c_h.size() || h_c.size()) {
    die();
  }
  int comp = 0;
  for (int i = 0; i < n; i++) {
    int root = find(i);
    if (!done[root]) {
      done[root] = 1;
      comp++;
    }
  }
  cout << comp << endl;
  return 0;
}
