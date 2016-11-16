#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

struct segtree {
  segtree() {
    num.resize(N << 2);
  }
  void update(int at, pair<int,int> val) {
    update(1, 0, N - 1, at, val);
  }
  void update(int p, int l, int r, int at, pair<int, int>& val) {
    if (l == r) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  pair<int, int> find(int l, int r) {
    return find(1, 0, N - 1, l, r);
  }
  pair<int, int> find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return {0, 0};
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<pair<int,int>> num;
} seg;

int w[N], c[N];
int from[N], to[N];

// MST things
vector<pair<int, int>> edge[N]; // ke mana - ID edge
int par[N];
bool is_mst[N];

// lca things
int h[N], rmq[N][20];
int lef[N], rig[N];
vector<int> st;

// queries
pair<int, int> ans[N];    // cost maximum, ID edge
vector<pair<int, int>> queries[N];  // ke mana, jawaban taruh mana

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

void dfs(int now, int bef) {
  lef[now] = rig[now] = st.size();
  st.push_back(now);
  for (auto it : edge[now]) {
    if (it.first == bef) continue;
    h[it.first] = h[now] + 1;
    dfs(it.first, now);
    rig[now] = st.size();
    st.push_back(now);
  }
}

void build_lca() {
  dfs(1, 0);
  for (int i = 0; i < st.size(); i++) rmq[i][0] = st[i];
  for (int j = 1; (1 << j) <= st.size(); j++) {
    for (int i = 0; i + (1 << j) <= st.size(); i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

void answer_queries(int now, int bef) {
  for (auto it : queries[now]) {
    int root = it.first;
    int id_ans = it.second;
    ans[id_ans] = seg.find(h[root], h[now] - 1);
  }
  for (auto it : edge[now]) {
    if (it.first == bef) continue;
    int near = it.first;
    int id = it.second;
    seg.update(h[now], make_pair(w[id], id));
    answer_queries(near, now);
  }
}

pair<int, int> maximum_path(int root, int u) {
  int p = lower_bound(queries[u].begin(), queries[u].end(), make_pair(root, -1)) - queries[u].begin();
  //printf("%d %d\n", p, queries[u].size());
  return ans[queries[u][p].second];
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;
  
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d", w + i);
  for (int i = 0; i < m; i++) scanf("%d", c + i);
  
  vector<pair<int, int>> edges;   // cost - id
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &from[i], &to[i]);
    edges.emplace_back(w[i], i);
  }
  sort(edges.begin(), edges.end());
  for (auto it : edges) {
    int i = it.second;
    int u = from[i];
    int v = to[i];
    if (find(u) != find(v)) {
      merge(u, v);
      edge[u].emplace_back(v, i);
      edge[v].emplace_back(u, i);
      is_mst[i] = 1;
    }
  }
  //for (int i = 1; i <= n; i++) for (auto it : edge[i]) if (i < it.first) printf("%d %d\n", i, it.first);
  int S;
  scanf("%d", &S);
  
  build_lca();
  //puts("lca done");
  //printf("S: "); for (auto it : st) printf("%d ", it); printf("\n");
  //for (int i = 1; i <= n; i++) printf("lef rig %d: %d %d\n", i, lef[i], rig[i]);
  //for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) printf("ntap %d %d %d\n", i, j, lca(i, j));
  long long ans = 0;
  int pt = 0;
  for (int i = 0; i < m; i++) {
    int u = from[i];
    int v = to[i];
    if (is_mst[i]) {
      ans += w[i];
    }
    int root = lca(u, v);
    //printf("lca awal %d %d: %d\n", from[i], to[i], root);
    queries[u].emplace_back(root, pt++);
    queries[v].emplace_back(root, pt++);
  }
  for (int i = 1; i <= n; i++) {
    sort(queries[i].begin(), queries[i].end());
  }
  long long mst_full = ans;
  //puts("before answer");
  answer_queries(1, 0);
  //puts("after answer");
  int entry = -1, lost = -1;
  ans = 1e18;
  for (int i = 0; i < m; i++) {
    int root = lca(from[i], to[i]);
    //printf("lca %d %d: %d\n", from[i], to[i], root);
    long long change = w[i] - S / c[i];
    pair<int, int> pol = max(maximum_path(root, from[i]), maximum_path(root, to[i]));
    //puts("maximum path");
    long long cur = mst_full + change - pol.first;
    if (cur < ans) {
      ans = cur;
      entry = i;
      lost = pol.second;
    }
  }
  printf("%I64d\n", ans);
  for (int i = 0; i < m; i++) {
    if (i == entry) {
      printf("%d %d\n", i + 1, w[i] - S / c[i]);
    } else if (is_mst[i] && i != lost) {
      printf("%d %d\n", i + 1, w[i]);
    }
  }
  return 0;
}
