
#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 5;

struct item {
  item() {}
  item(int l, int r, int cnt) : lef(l), rig(r), cnt(cnt) {}
  int lef, rig;
  int cnt;
};

item num[N << 2];
pair<int, int> all[N];
int pt;
int push[N << 2];

int id(int u) {
  return lower_bound(all, all + pt, make_pair(u, -1)) - all;
}

void build(int p, int l, int r) {
  if (l == r) {
    num[p] = item(all[l].first, all[l].second, all[l].second - all[l].first + 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  num[p].lef = num[p+p].lef;
  num[p].rig = num[p+p+1].rig;
  num[p].cnt = num[p+p].cnt + num[p+p+1].cnt;
}

void relax(int p, int l, int r) {
  if (push[p]) {
    if (l < r) {
      push[p + p] = push[p + p + 1] = push[p];
    }
    if (push[p] == 1) {
      num[p].cnt = 0;
    } else {
      num[p].cnt = num[p].rig - num[p].lef + 1;
    }
    push[p] = 0;
  }
}

void update(int p, int l, int r, int ll, int rr, int val) {
  relax(p, l, r);
  if (ll <= l && r <= rr) {
    push[p] = val;
    relax(p, l, r);
    return;
  }
  if (r < ll || rr < l) return;
  int mid = (l + r) >> 1;
  update(p + p, l, mid, ll, rr, val);
  update(p + p + 1, mid + 1, r, ll, rr, val);
  num[p].cnt = num[p+p].cnt + num[p+p+1].cnt;
}

int find(int p, int l, int r, int ll, int rr) {
  relax(p, l, r);
  if (ll <= l && r <= rr) return num[p].cnt;
  if (r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  int ret = find(p + p, l, mid, ll, rr) + find(p + p + 1, mid + 1, r, ll, rr);
  num[p].cnt = num[p+p].cnt + num[p+p+1].cnt;
  return ret;
}

int t[N], l[N], r[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> no = {0, n};
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", l + i, r + i, t + i);
    no.push_back(l[i]-1);
    no.push_back(r[i]);
  }
  sort(no.begin(), no.end());
  no.resize(distance(no.begin(), unique(no.begin(), no.end())));
  for (int i = 1; i < no.size(); i++) {
    all[pt++] = make_pair(no[i-1]+1, no[i]);
  }
  build(1, 0, pt - 1);
  int ans = n;
  for (int i = 0; i < q; i++) {
    int cnt = r[i] - l[i] + 1;
    int idl = id(l[i]);
    int idr = id(r[i]+1)-1;
    if (t[i] == 1) {
      int working_day = find(1, 0, pt - 1, idl, idr);
      ans -= working_day;
    } else {
      int non_working_day = cnt - find(1, 0, pt - 1, idl, idr);
      ans += non_working_day;
    }
    update(1, 0, pt - 1, idl, idr, t[i]);
    printf("%d\n", ans);
  }
  
  return 0;
}
