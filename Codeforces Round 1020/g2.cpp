#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<int> edge[N];
int ans[N], n, s[N], h[N], p[N];

int ask(vector<int> a) {
  printf("? 1 %d", a.size());
  for (auto it : a) printf(" %d", it);
  printf("\n");
  fflush(stdout);
  int v;
  scanf("%d", &v);
  return v;
}

void swap(int u) {
  printf("? 2 %d\n", u);
  fflush(stdout);
}

void answer() {
  printf("!");
  for (int i = 1; i <= n; i++) printf(" %d", ans[i]);
  printf("\n");
  fflush(stdout);
}

void clear() {
  for (int i = 1; i <= n; i++) edge[i].clear();
}

void find(int now, int bef, int up) {
  int v = ask({now});
  ans[now] = v - up;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    find(it, now, up + ans[now]);
  }
}

int test(vector<int> c, int now) {
  int awal = ask(c);
  swap(now);
  int akhir = ask(c);
  return abs(awal - akhir) / 2;
}

vector<int> subs(vector<int> c, int l, int r) {
  vector<int> ret;
  for (int i = l; i <= r; i++) ret.push_back(c[i]);
  return ret;
}

void dfs(int now, int bef) {
  s[now] = 1;
  h[now] = 0;
  p[now] = bef;
  int best = -1;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
    s[now] += s[it];
    if (best < s[it]) {
      best = s[it];
      h[now] = it;
    }
  }
}

int dfs_star(int now);
int dfs_line(int now) {
  vector<int> a;
  while (now != 0) {
    a.push_back(now);
    now = h[now];
  }
  if (a.size() == 1) return a[0];
  int l = 0, r = a.size() - 1;
  while (l < r) {
    int mid = (l + r - 1) >> 1;
    int len = r - l + 1;
    int lef = mid - l + 1;
    int rig = r - mid + 1;
    int v = test(subs(a, l, r), a[mid]);
    if (v == len) {
      return dfs_star(a[mid]);
    } else if (v == lef) {
      l = mid + 1;
    } else {
      assert(v == rig);
      r = mid - 1;
    }
  }
  return dfs_star(a[l]);
}

int dfs_star(int now) {
  vector<int> c;
  for (auto it : edge[now]) {
    if (it == h[now] || it == p[now]) continue;
    c.push_back(it);
  }
  c.push_back(now);
  int tot = c.size();
  int l = 0, r = tot - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    int len = mid - l + 1;
    if (test(subs(c, l, mid), now) == len) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (l == tot - 1) return now;
  return dfs_line(c[l]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs(1, 0);
    int root = dfs_line(1);
    find(root, 0, 0);

    answer();
    clear();
  }

  return 0;
}
