#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int par[N], a[N], b[N], aw[N];
vector<pair<int, int>> edge[N];

int find_cost(int u, int v) {
  int id = lower_bound(edge[u].begin(), edge[u].end(), make_pair(v, -1)) - edge[u].begin();
  if(id < 0 || id >= edge[u].size()) return 0;
  return edge[u][id].second;
}

int find(int u) {
  return u == par[u]? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

// HLD component
int comp[N], dad[N], cnt[N], id[N];
vector<int> el[N];
int num_comp;
// COMP - POS - LOG
vector<vector<vector<int>>> hld;

void dfs_cnt(int now, int p) {
  cnt[now] = 1;
  for(auto it : edge[now]) {
    if(it.first == p) continue;
    dfs_cnt(it.first, now);
    cnt[now] += cnt[it.first];
  }
}

void dfs_hld(int now, int p) {
  comp[now] = num_comp;
  dad[now] = p;
  el[num_comp].push_back(now);
  
  int best = 0, pt = -1;
  for(auto it : edge[now]) {
    if(it.first == p) continue;
    if(cnt[it.first] > best) {
      best = cnt[it.first];
      pt = it.first;
    }
  }
  if(pt == -1) return;
  dfs_hld(pt, now);
  
  for(auto it : edge[now]) {
    if(it.first == p || it.first == pt) continue;
    ++num_comp;
    dfs_hld(it.first, now);
  }
}

void build_hld() {
  dfs_cnt(1, 0);
  dfs_hld(1, 0);
  for(int c = 0; c <= num_comp; c++) {
    for(int i = 0; i < el[c].size(); i++) {
      id[el[c][i]] = i;
    }
  }
  hld.resize(num_comp + 1);
  for(int c = 0; c <= num_comp; c++) {
    hld[c].resize(el[c].size());
    for(int i = 0; i < el[c].size(); i++) {
      hld[c][i].resize(20);
    }
    for(int i = 0; i < el[c].size(); i++) {
      hld[c][i][0] = find_cost(i? el[c][i-1] : dad[el[c][i]], el[c][i]);
    }
  }
  for(int c = 0; c <= num_comp; c++) {
    for(int j = 1; (1 << j) <= el[c].size(); j++) {
      for(int i = 0; i + (1<<j) <= el[c].size(); i++) {
        hld[c][i][j] = max(hld[c][i][j-1], hld[c][i+(1<<(j-1))][j-1]);
      }
    }
  }
}

int get_max(int c, int l, int r) {
  if(l > r) return 0;
  int g = __builtin_clz(r - l + 1) ^ 31;
  return max(hld[c][l][g], hld[c][r-(1<<g)+1][g]);
}

// dijamin from adalah ancestor
int get_max(int from, int to) {
  int ret = 0;
  while(comp[to] != comp[from]) {
    ret = max(ret, get_max(comp[to], 0, id[to]));
    to = dad[el[comp[to]][0]];
  }
  ret = max(ret, get_max(comp[to], id[from] + 1, id[to]));
  return ret;
}

int rmq[2 * N][20], pos[N], h[N], pcnt;

void dfs_lca(int now, int p) {
  rmq[pcnt][0] = now;
  pos[now] = pcnt++;
  h[now] = h[p] + 1;
  for(auto it : edge[now]) {
    if(it.first == p) continue;
    dfs_lca(it.first, now);
    rmq[pcnt++][0] = now;
  }
}

void build_lca() {
  dfs_lca(1, 0);
  for(int j = 1; (1<<j) <= pcnt; j++) {
    for(int i = 0; i + (1 << j) < pcnt; i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
}

int lca(int u, int v) {
  int l = min(pos[u], pos[v]);
  int r = max(pos[u], pos[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

int main() {
  for(int i = 0; i < N; i++) {
    par[i] = i;
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  vector<tuple<int, int, int>> edges;
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d", a + i, b + i, aw + i);
    edges.emplace_back(aw[i], a[i], b[i]);
  }
  sort(edges.begin(), edges.end());
  long long mst = 0;
  for(auto it : edges) {
    int cost, u, v;
    tie(cost, u, v) = it;
    if(find(u) != find(v)) {
      mst += cost;
      merge(u, v);
      //printf("%d %d\n", u, v);
      edge[u].push_back(make_pair(v, cost));
      edge[v].push_back(make_pair(u, cost));
    }
  }
  for(int i = 1; i <= n; i++) {
    sort(edge[i].begin(), edge[i].end());
  }
  build_hld();
  build_lca();
  for(int i = 0; i < m; i++) {
    int anc = lca(a[i], b[i]);
    int del = max(get_max(anc, a[i]), get_max(anc, b[i]));
    //printf("lca %d, dgn %d %d, dgn %d %d\n", anc, a[i], get_max(anc, a[i]), b[i], get_max(anc, b[i]));
    printf("%I64d\n", mst + aw[i] - del);
  }
  
  return 0;
}
