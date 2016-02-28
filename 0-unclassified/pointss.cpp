#include <bits/stdc++.h>

using namespace std;

const int offset = 1e5;
const int N = 2e5 +5;

multiset<pair<int, int>> pq[N];

struct segtree {
  segtree() {
    a.assign(offset << 2, -N);
  }
  void update(int at, int val) {
    update(1, 0, offset, at, val);
  }
  void update(int p, int l, int r, int at, int val) {
    if(l == r) {
      a[p] = max(a[p], val);
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    a[p] = max(a[p + p], a[p + p + 1]);
  }
  int find(int l, int r) {
    return find(1, 0, offset, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if(r < ll || rr < l) return -N;
    if(ll <= l && r <= rr) {
      return a[p];
    }
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<int> a;
};

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    pq[v - u + offset].insert(make_pair(u, v));
  }
  vector<pair<int, int>> p;
  for(int i = 0; i < n; i++) {
    int at;
    scanf("%d", &at);
    at += offset;
    auto it = pq[at].begin();
    if(it == pq[at].end()) {
      puts("NO");
      return 0;
    }
    p.push_back(*it);
    pq[at].erase(it);
  }
  segtree seg;
  for(int i = 0; i < n; i++) {
    int u = p[i].first;
    int v = p[i].second;
    int find = seg.find(u, offset - 1);
    if(find >= v) {
      puts("NO");
      return 0;
    }
    seg.update(u, v);
  }
  puts("YES");
  for(auto it : p) {
    printf("%d %d\n", it.first, it.second);
  }
  return 0;
}
