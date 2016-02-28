/**
 * pertama kali ngoding HLD + persistent segment tree + LCA
 *
 * roto
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int ambil;

struct node {
  node() : count(0), left(NULL), right(NULL) {}
  node(int cnt, node* l, node* r) : count(cnt), left(l), right(r) {}
  node* insert(int, int, int);
  int count;
  node* left;
  node* right;
};

node* null = new node(0, NULL, NULL);

node* node::insert(int l, int r, int x) {
  if(l <= x && x <= r) {
    if(l == r) {
      return new node(this->count + 1, null, null);
    }
    int mid = (l + r) >> 1;
    return new node(this->count + 1, this->left->insert(l, mid, x), this->right->insert(mid + 1, r, x));
  }
  return this;
}

// a versi lama, b versi varu
int query(node* a, node* b, int l, int r, int k) {
  if(l == r) return l;
  int count = b->left->count - a->left->count;
  int mid = (l + r) >> 1;
  if(k <= count) {
    return query(a->left, b->left, l, mid, k);
  } else {
    return query(a->right, b->right, mid + 1, r, k - count);
  }
}

// question related
int n;
vector<int> city[N];
vector<int> edge[N];

// hld related
int comp[N], idx[N], dad[N], cnt[N];
vector<int> hld[N];
vector<int> ans;
int num_comp;

// persistent segment tree related
vector<node*> pst[N]; 
vector<int> save[N];  // menyimpan orang dengan ID berapa aja dalam sekomponen HLD
int idp[N];           // pos orang tertentu pada array di comp HLD

// LCA related
vector<int> tour;
int rmq[N << 1][20];
int pos[N], h[N];

void dfs(int now, int bef) {
  h[now] = h[bef] + 1;
  tour.push_back(now);
  for(auto it : edge[now]) {
    if(it == bef) continue;
    dfs(it, now);
    tour.push_back(now);
  }
}

void build_lca() {
  dfs(1, 0);
  for(int i = 0; i < tour.size(); i++) {
    pos[tour[i]] = i;
  }
  for(int i = 0; i < tour.size(); i++) {
    rmq[i][0] = tour[i];
  }
  for(int j = 1; (1 << j) <= tour.size(); j++) {
    for(int i = 0; i < tour.size(); i++) {
      rmq[i][j] = (h[rmq[i][j - 1]] < h[rmq[i + (1<<(j-1))][j - 1]]? rmq[i][j - 1] : rmq[i + (1<<(j-1))][j - 1]);
    }
  }
}

void dfs_count(int now, int bef) {
  for(auto it : edge[now]) {
    if(it == bef) continue;
    dfs_count(it, now);
    cnt[now] += cnt[it];
  }
  cnt[now]++;
}

void dfs_hld(int now, int bef) {
  dad[now] = bef;
  comp[now] = num_comp;
  idx[now] = hld[num_comp].size();
  hld[num_comp].push_back(now);
  
  int maxi = -1, p = -1;  
  for(auto it : edge[now]) {
    if(it == bef) continue;
    if(maxi < cnt[it]) {
      maxi = cnt[it];
      p = it;
    }
  }
  if(maxi == -1) return;
  dfs_hld(p, now);
  for(auto it : edge[now]) {
    if(it == bef || it == p) continue;
    num_comp++;
    dfs_hld(it, now);
  }
}

void build_hld() {
  dfs_count(1, 0);
  dfs_hld(1, 0);
}

void build_pst() {
  null->left = null; null->right = null;
  for(int i = 0; i <= num_comp; i++) {
    for(auto it : hld[i]) {
      for(auto id : city[it]) {
        save[i].push_back(id);
      }
    }
    sort(save[i].begin(), save[i].end());
    for(int j = 0; j < save[i].size(); j++) {
      idp[save[i][j]] = j;
    }
    pst[i].resize(hld[i].size());
    for(int j = 0; j < pst[i].size(); j++) {
      pst[i][j] = (j? pst[i][j - 1] : null);
      for(auto id : city[hld[i][j]]) {
        pst[i][j] = pst[i][j]->insert(0, (int) save[i].size() - 1, idp[id]);
      }
    }
  }
}

// mengambil <ambil> buah ID orang terbaik dari node u ke v
// prerequisite : u dan v satu comp, u di atas v
vector<int> get(int u, int v) {
  assert(comp[u] == comp[v]);
  vector<int> mkth;
  int c = comp[u];
  node* left = idx[u]? pst[c][idx[u] - 1] : null;
  node* right = pst[c][idx[v]];
  int size_max = min(ambil, right->count - left->count);
  for(int i = 1; i <= size_max; i++) {
    mkth.push_back(save[c][query(left, right, 0, (int) save[c].size() - 1, i)]);
  }
  return mkth;
}

void build() {
  build_lca();
  build_hld();
  build_pst();
}

int lca(int u, int v) {
  int l = min(pos[u], pos[v]);
  int r = max(pos[u], pos[v]);
  int c = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][c]] < h[rmq[r-(1<<c)+1][c]]? rmq[l][c] : rmq[r-(1<<c)+1][c];
}

void route(int root, int u) {
  while(comp[u] != comp[root]) {
    vector<int> ret = get(hld[comp[u]][0], u);
    vector<int> tmp(ret.size() + ans.size());
    merge(ans.begin(), ans.end(), ret.begin(), ret.end(), tmp.begin());
    ans = tmp;
    ans.resize(min((int)ans.size(), ambil));
    u = dad[hld[comp[u]][0]];
  }
  if(u != root) {
    vector<int> ret = get(hld[comp[root]][idx[root] + 1], u);
    vector<int> tmp(ret.size() + ans.size());
    merge(ans.begin(), ans.end(), ret.begin(), ret.end(), tmp.begin());
    ans = tmp;
    ans.resize(min((int)ans.size(), ambil));
  }
}

void solve(int u, int v) {
  ans.clear();
  int root = lca(u, v);
  ans = city[root];
  ans.resize(min((int)ans.size(), ambil));
  route(root, u);
  route(root, v);
  printf("%d ", ans.size());
  for(auto it : ans) {
    printf("%d ", it);
  }
  printf("\n");
}

int main() {
  int m, q;
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for(int i = 1; i <= m; i++) {
    int at;
    scanf("%d", &at);
    city[at].push_back(i);
  }
  for(int i = 1; i <= n; i++) {
    sort(city[i].begin(), city[i].end());
  }
  build();
  while(q--) {
    int u, v;
    scanf("%d %d %d", &u, &v, &ambil);
    solve(u, v);
  }
  return 0;
}
