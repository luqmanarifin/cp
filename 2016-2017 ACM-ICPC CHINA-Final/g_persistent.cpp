#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct node {
  node(node* lef, node* rig, pair<int, int> num) : lef(lef), rig(rig), num(num) {}
  pair<int, int> num;
  node* lef;
  node* rig;
};

node* null;
pair<int, int> zonk;
node* nodes[N];

node* change(node* now, int l, int r, int ll, int rr, pair<int, int> num) {
  if (ll <= l && r <= rr) return new node(null, null, num);
  if (r < ll || rr < l) return now;
  int mid = (l + r) >> 1;
  return new node(change(now->lef, l, mid, ll, rr, num), change(now->rig, mid + 1, r, ll, rr, num), zonk);
}

pair<int, int> find(node* now, int l, int r, int at) {
  if (node->num != zonk) return node->num;
  int mid = (l + r) >> 1;
  if (at <= mid) {
    return find(node->lef, l, mid, at);
  } else {
    return find(node->rig, mid + 1, r, at);
  }
}

int par[N];

int dsu(int u) {
  return par[u] = (par[u] == u? u : dsu(par[u]));
}

void merge(int u, int v) {
  par[dsu(u)] = dsu(v);
}

map<int, int> ans[N];
vector<pair<int, int>> ask[N];
int l[N], r[N];

int a[N], u[N], v[N], w[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d %d", u + i, v + i, w + i);
      edges.emplace_back(w[i], u[i], v[i]);
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++) {
      tie(w[i + 1], u[i + 1], v[i + 1]) = edges[i];
    }
    for (int i = 1; i <= m; i++) {
      
    }
    
    printf("Case #%d:\n", tc);
  }
  return 0;
}