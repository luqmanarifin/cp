#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct segtree {
  segtree() {
    
  }
  segtree(vector<int> _num) : num(_num) {
    a.assign(num.size() << 2, 0);
    b.assign(num.size() << 2, 0);
    push.assign(num.size() << 2, 0);
    build(1, 0, num.size() - 1);
  }
  void relaks(int p, int l, int r) {
    if (push[p]) {
      if (l < r) {
        push[p + p] += push[p];
        push[p + p + 1] += push[p];
      }
      int mid = (l + r) >> 1;
      a[p] += 2*push[p]*b[p] + (r-l+1)*push[p]*push[p];
      b[p] += (r-l+1)*push[p];
      push[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    a[p] = a[p + p] + a[p + p + 1];
    b[p] = b[p + p] + b[p + p + 1];
  }
  void build(int p, int l, int r) {
    if (l == r) {
      a[p] = 1LL * num[l] * num[l];
      b[p] = num[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void update(int l, int r, int v) {
    update(1, 0, num.size() - 1, l, r, v);
  }
  void update(int p, int l, int r, int ll, int rr, int v) {
    relaks(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] += v;
      relaks(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, v);
    update(p + p + 1, mid + 1, r, ll, rr, v);
    combine(p, l, r);
  }
  long long find(int l, int r) {
    return find(1, 0, num.size() - 1, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    relaks(p, l, r);
    if (ll <= l && r <= rr) return a[p];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    long long ret = find(p + p, l, mid, ll, rr);
    ret += find(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    return ret;
  }
  vector<long long> a, b;   // a sq, b sum biasa
  vector<int> push, num;
};

vector<int> edge[N];
int lef[N], rig[N], h[N];
vector<int> f;

vector<int> query[N];
int ask[N];
long long ans[N];

segtree* seg;

void dfs(int now) {
  lef[now] = f.size();
  f.push_back(h[now]);
  for (auto it : edge[now]) {
    h[it] = h[now] + 1;
    dfs(it);
  }
  rig[now] = f.size() - 1;
}

void answer(int now) {
  for (auto id : query[now]) {
    int at = ask[id];
    ans[id] = seg->find(lef[at], rig[at]);
  }
  for (auto it : edge[now]) {
    seg->update(lef[it], rig[it], -1);
    seg->update(0, lef[it] - 1, +1);
    seg->update(rig[it] + 1, f.size() - 1, +1);
    answer(it);
    seg->update(lef[it], rig[it], +1);
    seg->update(0, lef[it] - 1, -1);
    seg->update(rig[it] + 1, f.size() - 1, -1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int v;
    scanf("%d", &v);
    edge[v].push_back(i);
  }
  dfs(1);
  seg = new segtree(f);
  
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    query[u].push_back(i);
    ask[i] = v;
  }
  
  answer(1);
  for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
  return 0;
}
