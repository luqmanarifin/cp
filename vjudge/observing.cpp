#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct node {
  node(node* _lef, node* _rig, long long _num, long long _add, long long _lazy) {
    lef = _lef;
    rig = _rig;
    num = _num;
    add = _add;
    lazy = _lazy;
  }
  node(node* o) {
    lef = o->lef;
    rig = o->rig;
    num = o->num;
    add = o->add;
    lazy = o->lazy;
  }
  long long add, lazy, num;
  node* lef;
  node* rig;
};

node* null = new node(NULL, NULL, 0, 0, 0);

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

node* insert(node* now, int l, int r, int ll, int rr, long long _add, long long _lazy) {
  node* ret = new node(now);
  if (l == ll && r == rr) {
    ret->add += _add;
    ret->lazy += _lazy;
    return ret;
  }
  int mid = (l + r) >> 1;
  if (ll <= mid && mid < rr) {
    ret->lef = insert(ret->lef, l, mid, ll, mid, _add + (rr - mid) * _lazy, _lazy);
    ret->rig = insert(ret->rig, mid + 1, r, mid + 1, rr, _add, _lazy);
  } else if (ll <= mid) {
    ret->lef = insert(ret->lef, l, mid, ll, rr, _add, _lazy);
  } else {
    ret->rig = insert(ret->rig, mid + 1, r, ll, rr, _add, _lazy);
  }
  ret->num = ret->lef->num + ret->lef->add * (mid - l + 1) + ret->lef->lazy * sum(mid - l);
  ret->num += ret->rig->num + ret->rig->add * (r - mid) + ret->rig->lazy * sum(r - mid - 1);
  return ret;
}

long long find(node* now, int l, int r, int ll, int rr) {
  //printf("asu %d %d %d %d\n", l, r, ll, rr);
  if (ll == l && r == rr) return now->num + now->add * (r - l + 1) + sum(r - l) * now->lazy;
  if (r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  long long ret = now->add * (rr - ll + 1) + (sum(r - ll) - sum(r - rr - 1)) * now->lazy;
  if (ll <= mid && mid < rr) {
    ret += find(now->lef, l, mid, ll, mid);
    ret += find(now->rig, mid + 1, r, mid + 1, rr);
  } else {
    ret += find(now->lef, l, mid, ll, rr);
    ret += find(now->rig, mid + 1, r, ll, rr);
  }
  return ret;
}

// versioning HLD
node* nodes[N];
int pt, n;

// HLD
vector<int> edge[N], el[N];
int sub[N], comp[N], id[N], num_comp, dad[N], off[N];

// LCA
int rmq[N * 2][20], h[N], lef[N], rig[N];
vector<int> pre;

void dfs(int now, int bef) {
  dad[now] = bef;
  sub[now] = 1;
  h[now] = h[bef] + 1;
  lef[now] = rig[now] = pre.size();
  pre.push_back(now);
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
    sub[now] += sub[it];
    rig[now] = pre.size();
    pre.push_back(now);
  }
}

void hld(int now, int bef) {
  int best = -1, p = -1;
  id[now] = el[num_comp].size();
  comp[now] = num_comp;
  el[num_comp].push_back(now);
  for (auto it : edge[now]) {
    if (it == bef) continue;
    if (sub[it] > best) {
      best = sub[it];
      p = it;
    }
  }
  if (p == -1) {
    num_comp++;
    return;
  }
  hld(p, now);
  for (auto it : edge[now]) {
    if (it == bef || it == p) continue;
    hld(it, now);
  }
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

void update(int root, int x, int a, int b) {
  if (root == x) return;
  int from, to = id[x];
  if (comp[root] != comp[x]) {
    from = 0;
  } else {
    from = id[root] + 1;
  }
  //printf("from to %d %d: %d %d\n", from, to, a, b);
  nodes[pt] = insert(nodes[pt], 0, n - 1, off[comp[x]] + from, off[comp[x]] + to, a, b);
  //printf("insert done\n");
  if (comp[root] != comp[x]) {
    update(root, dad[el[comp[x]][0]], a + (id[x] + 1) * b, b);
  }
}

long long solve(int root, int x) {
  if (root == x) return 0;
  int from, to = id[x];
  if (comp[root] != comp[x]) {
    from = 0;
  } else {
    from = id[root] + 1;
  }
  //printf("seg %d %d\n", off[comp[x]] + from, off[comp[x]] + to);
  long long ret = find(nodes[pt], 0, n - 1, off[comp[x]] + from, off[comp[x]] + to);
  if (comp[root] != comp[x]) {
    ret += solve(root, dad[el[comp[x]][0]]);
  }
  return ret;
}

int main() {
  null->lef = null->rig = null;
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  hld(1, 0);
  comp[0] = -1;
  for (int i = 0; i < pre.size(); i++) rmq[i][0] = pre[i];
  for (int j = 1; (1 << j) <= pre.size(); j++) {
    for (int i = 0; i + (1 << j) <= pre.size(); i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }

  for (int c = 0; c < num_comp; c++) {
    if (c) off[c] = off[c - 1] + el[c - 1].size();
    //printf("%d: ", c);
    //for (auto it : el[c]) printf("%d ", it); printf("\n");
  }
  /*
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      printf("lca %d %d: %d\n", i, j, lca(i, j));
    }
  }
  */
  //puts("build done");
  long long lastans = 0;
  int change = 0;
  nodes[0] = null;
  while (q--) {
    char c;
    int x, y, a, b;
    scanf(" %c", &c);
    if (c == 'c') {
      scanf("%d %d %d %d", &x, &y, &a, &b);
      x = (x + lastans) % n + 1;
      y = (y + lastans) % n + 1;
      //printf("x %d y %d\n", x, y);
      
      nodes[++change] = nodes[pt];
      pt = change;
      int root = lca(x, y);
      int dist = h[x] + h[y] - 2 * h[root];
      update(root, x, a, b);
      update(dad[root], y, a + dist * b, -b);
      //for (int i = 1; i <= n; i++) printf("%lld ", solve(dad[i], i)); printf("\n");
      
    } else if (c == 'q') {
      scanf("%d %d", &x, &y);
      x = (x + lastans) % n + 1;
      y = (y + lastans) % n + 1;
      int root = lca(x, y);
      //printf("lca %d\n", root);
      //printf("asking %d %d\n", x, y);
      lastans = solve(root, x) + solve(dad[root], y);
      printf("%lld\n", lastans);
      
    } else {
      scanf("%d", &x);
      x = (x + lastans) % (change + 1);
      pt = x;
    }
    //puts("done");
    
    //for (int i = 1; i <= n; i++) printf("%lld ", solve(dad[i], i)); printf("\n");
  }

  return 0;
}
