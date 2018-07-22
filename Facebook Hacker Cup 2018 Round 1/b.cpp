#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

vector<int> s;
int a[N], b[N], n, k;

void dfs_pre(int now) {
  if (now == 0) return;
  s.push_back(now);
  dfs_pre(a[now]);
  dfs_pre(b[now]);
}

void dfs_pos(int now) {
  if (now == 0) return;
  dfs_pos(a[now]);
  dfs_pos(b[now]);
  s.push_back(now);
}

vector<int> get_pre() {
  s.clear();
  dfs_pre(1);
  return s;
}

vector<int> get_pos() {
  s.clear();
  dfs_pos(1);
  return s;
}

int par[N], ans[N], tmp[N];
bool done[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d %d", a + i, b + i);
    auto pre = get_pre();
    auto pos = get_pos();
    for (int i = 1; i <= n; i++) par[i] = i;
    //printf("pre: "); for (int i = 0; i < n; i++) printf("%d ", pre[i]); printf("\n");
    //printf("pos: "); for (int i = 0; i < n; i++) printf("%d ", pos[i]); printf("\n");
    for (int i = 0; i < pre.size(); i++) {
      merge(pre[i], pos[i]);
    }
    memset(done, 0, sizeof(done));
    int label = 0;
    for (int i = 1; i <= n; i++) {
      int now = find(i);
      if (!done[now]) {
        done[now] = 1;
        label = min(label + 1, k);
        ans[i] = tmp[now] = label;
      } else {
        ans[i] = tmp[now];
      }
    }
    printf("Case #%d:", tt);
    if (label < k) {
      printf(" Impossible\n");
    } else {
      for (int i = 1; i <= n; i++) printf(" %d", ans[i]); printf("\n");
    }
    fprintf(stderr, "%d done!\n", tt);
  }

  return 0;
}
