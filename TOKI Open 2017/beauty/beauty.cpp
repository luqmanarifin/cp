#include "beauty.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

/****** Tarjan’s SCC *******/
// node normal
vector< int > num, low, S, vis;
int cntr, numCC;
vector<int> adj[N];
int par[N];                     // golongan [compress] 

// node compress
vector<tuple<int, int, int>> edge[N]; // ke [compress], pinpoint musuh [normal], pinpoint diri[normal]
int pin[N], revpin[N];

void tarjanSCC(int v, int bef = -1) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : adj[v]) {
    if (u == bef) continue;
    if(num[u] == -1)
      tarjanSCC(u, v);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    printf("SCC %d: ", numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      printf("%d ", u);
      par[u] = numCC;
      if(u == v)
        break;
    }
    printf("\n");
    numCC++;
  }
}

// compress
int comp[N], id[N], sub[N], num_comp, val[N], dad[N], lef[N], rig[N], h[N];

// rmq shits
vector<int> pre;
int rmq[N][20];

struct segtree {
  segtree() {}
  segtree(vector<int> _a) : a(_a) {
    num.resize(a.size() << 2);
    build(1, 0, (int) a.size() - 1);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      num[p] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = max(num[p+p], num[p+p+1]);
  }
  int find(int l, int r) {
    return find(1, 0, a.size() - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return max(find(p+p, l, mid, ll, rr), find(p+p+1, mid + 1, r, ll, rr));
  }

  vector<int> a, num;
};

// id componen
vector<int> el[N], max_lef[N], max_rig[N];
segtree seg[N];

void dfs_pre(int now, int bef = -1) {
  lef[now] = pre.size();
  if (bef >= 0) h[now] = h[bef] + 1;
  pre.push_back(now);
  sub[now] = 1;
  for (auto it : edge[now]) {
    int near, pp, rp;
    tie(near, pp, rp) = it;
    if (near == bef) continue;
    pin[near] = pp;
    revpin[near] = rp;
    dfs_pre(near, now);
    sub[now] += sub[near];
    rig[now] = pre.size();
    pre.push_back(now);
  }
}

void dfs(int now, int bef = -1) {
  int best = -1, p = -1;
  dad[now] = bef;
  id[now] = el[num_comp].size();
  el[num_comp].push_back(now);
  for (auto it : edge[now]) {
    int near;
    tie(near, ignore, ignore) = it;
    if (near == bef) continue;
    if (sub[near] > best) {
      best = sub[near];
      p = near;
    }
  }
  if (p == -1) {
    num_comp++;
    return;
  }
  dfs(p, now);
  for (auto it : edge[now]) {
    int near;
    tie(near, ignore, ignore) = it;
    if (near == bef || near == p) continue;
    dfs(near, now);
  }
}

// u & v compressed node
int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

// root & u compressed
// root eksklusif, u inklusif
int solve(int root, int u, int& bef_root) {
  if (root == u) return 0;
  if (comp[root] == comp[u]) {
    bef_root = el[comp[root]][id[root] + 1];
    return seg[comp[root]].find(id[root] + 1, id[u]);
  }
  int f = el[comp[u]][0];
  bef_root = f;
  return max(max_lef[comp[u]][id[u]], solve(root, dad[f], bef_root));
}

std::vector<int> getMaximumBeauty(int n, int m, int q, std::vector<int> t, 
    std::vector<int> u, std::vector<int> v,
    std::vector<int> a, std::vector<int> b) {
  for (int i = 0; i < q; i++) {
    a[i]--;
    b[i]--;
  }
  for (int i = 0; i < m; i++) {
    u[i]--;
    v[i]--;
    adj[u[i]].push_back(v[i]);
    adj[v[i]].push_back(u[i]);
  }

// In MAIN();
  num.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, 0);
  cntr = numCC = 0;
  for (int i = 0; i<n; i++)
    if(num[i] == -1)
      tarjanSCC(i);

  for (int i = 0; i < n; i++) {
    val[par[i]] = max(val[par[i]], t[i]);
  }
  for (int i = 0; i < m; i++) {
    if (par[u[i]] != par[v[i]]) {
      edge[par[u[i]]].emplace_back(par[v[i]], v[i], u[i]);
    }
  }
  dfs_pre(0);
  dfs(0);
  for (int c = 0; c < num_comp; c++) {
    vector<int> v;
    for (auto it : el[c]) {
      v.push_back(val[it]);
      max_lef[c].push_back(val[it]);
      max_rig[c].push_back(val[it]);
    }
    for (int i = 1; i < max_lef[c].size(); i++) {
      max_lef[c][i] = max(max_lef[c][i], max_lef[c][i-1]);
    }      
    for (int i = (int)max_rig[c].size() - 2; i >= 0; i--) {
      max_rig[c][i] = max(max_rig[c][i], max_rig[c][i+1]);
    }
    seg[c] = segtree(v);
    printf("comp %d: ", c);
    for (auto it :)
  }
  for (int i = 0; i < pre.size(); i++) rmq[i][0] = pre[i];
  for (int j = 1; (1 << j) <= pre.size(); j++) {
    for (int i = 0; i + (1 << j) <= pre.size(); i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
  vector<int> ans;
  for (int i = 0; i < q; i++) {
    if (a[i] == b[i]) {
      ans.push_back(t[a[i]]);
    } else if (par[a[i]] == par[b[i]]) {
      ans.push_back(val[par[a[i]]]);
    } else {
      int u = par[a[i]];
      int v = par[b[i]];
      if (dad[u] == v) {
        JANCOK:;
        int ret = 0;
        if (pin[u] == a[i]) {
          ret = t[a[i]];
        } else {
          ret = val[u];
        }
        if (revpin[u] == b[i]) {
          ret = max(ret, t[b[i]]);
        } else {
          ret = max(ret, val[v]);
        }
        ans.push_back(ret);
      } else if (dad[v] == u) {
        swap(u, v);
        swap(a[i], b[i]);
        goto JANCOK;
      } else {
        int root = lca(u, v);
        if (root == u) {
          TAEK:;
          int bef_root;
          int ret = solve(root, dad[v], bef_root);
          if (revpin[bef_root] == a[i]) {
            ret = max(ret, t[a[i]]);
          } else {
            ret = max(ret, val[root]);
          }
          if (pin[v] == b[i]) {
            ret = max(ret, t[b[i]]);
          } else {
            ret = max(ret, val[v]);
          }
          ans.push_back(ret);
        } else if (root == v) {
          swap(u, v);
          swap(a[i], b[i]);
          goto TAEK;
        } else {
          int tmp;
          int ret = max(solve(root, u, tmp), solve(root, v, tmp));
          if (pin[u] == a[i]) {
            ret = max(ret, t[a[i]]);
          } else {
            ret = max(ret, val[u]);
          }
          if (pin[v] == b[i]) {
            ret = max(ret, t[b[i]]);
          } else {
            ret = max(ret, val[v]);
          }
          ans.push_back(ret);
        }
      }
    }
  }
  return ans;
}
