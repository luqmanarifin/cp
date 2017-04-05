#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int inf = 2e9;

struct segtree {
  segtree(int n) : n(n) {
    a.assign(n << 2, -1);
  }
  void update(int at, int val) {
    update(1, 0, n - 1, at, val);
  }
  void update(int p, int l, int r, int at, int val) {
    a[p] = max(a[p], val);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
  }
  int find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return a[p];
    if (r < ll || rr < l) return -1;
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<int> a;
  int n;
};

int bit[N];

void update(int i, int val) {
  for (; i >= 0; i = (i & (i + 1)) - 1) bit[i] = min(bit[i], val);
}

int find(int i) {
  int ret = inf;
  for (; i < N; i |= i + 1) ret = min(ret, bit[i]);
  return ret;
}

int a[N], ans[N], to[N];
vector<int> que[N];

int main() {
  for (int i = 0; i < N; i++) bit[i] = inf;

  int n;
  scanf("%d", &n);
  vector<int> all;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    all.push_back(a[i]);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l; --r;
    to[i] = l;
    que[r].push_back(i);
  }

  segtree seg(all.size());
  for (int i = 0; i < n; i++) {
    int id_now = lower_bound(all.begin(), all.end(), a[i]) - all.begin();

    int up = inf;
    while (a[i] < up) {
      int id_up = lower_bound(all.begin(), all.end(), up) - all.begin() - 1;
      //printf("%d %d %d\n", i, up, id_up);
      if (id_up < id_now) break;
      int id = seg.find(id_now, id_up);
      //printf("emangnya %d %d %d\n", id_now, id_up, id);
      if (id < 0) break;
      up = a[id];
      //printf("%d up %d\n", i, up);
      assert(up >= a[i]);
      update(id, up - a[i]);
      up = (a[i] + up + 1) / 2;
    }

    int down = -1;
    while (a[i] > down) {
      int id_down = upper_bound(all.begin(), all.end(), down) - all.begin();
      if (id_down > id_now) break;
      int id = seg.find(id_down, id_now);
      if (id < 0) break;
      down = a[id];
      assert(a[i] >= down);
      update(id, a[i] - down);
      down = (a[i] + down) / 2;
    }
    for (auto it : que[i]) ans[it] = find(to[it]);
    seg.update(id_now, i);
    //printf("upd %d %d\n\n", id_now, i);
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);

  return 0;
}
