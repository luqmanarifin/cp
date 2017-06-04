#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e5 + 5;
 
int sum[N << 2];
vector< int > g[N];
int st[N], fn[N], flat[N], tmpst = 0;
int n, ans[N];
 
void pre(int v, int par = -1) {
  flat[tmpst] = v;
  st[v] = tmpst++;
  for (int u : g[v]) if (u != par) {
    pre(u, v);
  }
  fn[v] = tmpst;
}
void build(int id = 1, int l = 0, int r = n) {
  sum[id] = 0;
  if (r-l < 2)
    return;
  int mid = (l + r)/2, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void update(int x, int y, int c, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    sum[id] += c;
    return;
  }
  int mid = (l + r)/2, il = id << 1, ir = il | 1;
  update(x, y, c, il, l, mid);
  update(x, y, c, ir, mid, r);
}
int get(int x, int id = 1, int l = 0, int r = n) {
  if (r - l < 2) return sum[id];
  int mid = (l + r)/2, il = id << 1, ir = il | 1;
  int ret = sum[id];
  if (x < mid)
    ret += get(x, il, l, mid);
  else 
    ret += get(x, ir, mid, r);
  return ret;
}
void dfs(int v, int par = -1) {
  ans[v] = get(st[v]);
  update(st[v], fn[v], 1);
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
  }
  update(st[v], fn[v], -1);
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    tmpst = 0;
    pre(0);
    build();
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
      printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
} 