#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int MAGIC = 450;
const int MAX = 105;

int par[500][MAX], di[500][MAX], push[500];
int a[N], n, be[MAX], asli[MAX];

int find(int block, int u) {
  return par[block][u] = (par[block][u] == u? u : find(block, par[block][u]));
}

void merge(int block, int u, int v) {
  u = find(block, u);
  v = find(block, v);
  par[block][u] = v;
}

void change(int block, int from, int to) {
  int u = di[block][from];
  int v = di[block][to];
  //printf("%d %d\n", u, v);
  if (u == -1) return;
  push[block] = 1;
  if (v == -1) {
    di[block][to] = u;
    di[block][from] = -1;
  } else {
    merge(block, u, v);
    assert(find(block, u) == find(block, v));
    //printf("root %d\n", find(block, u));
    di[block][to] = find(block, u);
    di[block][from] = -1;
  }
}

void lazy(int block) {
  if (!push[block]) return;
  for (int i = 1; i <= 100; i++) {
    if (di[block][i] != -1) {
      asli[di[block][i]] = i;
    }
  }
  for (int i = 1; i <= 100; i++) {
    be[i] = asli[find(block, i)];
    //printf("%d -> %d\n", i, be[i]);
  }
  int from = block * MAGIC, to = min(n, (block + 1) * MAGIC - 1);
  for (int i = from; i <= to; i++) {
    a[i] = be[a[i]];
  }
  for (int i = 1; i <= 100; i++) {
    par[block][i] = i;
    di[block][i] = i;
  }
  push[block] = 0;
}

void change(int l, int r, int from, int to) {
  int bl = l / MAGIC;
  int br = r / MAGIC;
  if (bl == br) {
    lazy(br);
    for (int i = l; i <= r; i++) if (a[i] == from) a[i] = to;
  } else if (bl + 1 == br) {
    change(l, br * MAGIC - 1, from, to);
    change(br * MAGIC, r, from, to);
  } else {
    change(l, (bl + 1) * MAGIC - 1, from, to);
    for (int i = bl + 1; i < br; i++) change(i, from, to);
    change(br * MAGIC, r, from, to);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < MAGIC; i++) {
    for (int j = 1; j <= 100; j++) {
      par[i][j] = j;
      di[i][j] = j;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, x, y;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    l--; r--;
    change(l, r, x, y);
    //for (int i = 0; i * MAGIC < n; i++) lazy(i);
    //for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
  }
  for (int i = 0; i * MAGIC < n; i++) lazy(i);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);

  return 0;
}
