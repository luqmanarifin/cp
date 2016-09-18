#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;

struct segtree {
  segtree (vector<int>& num) : num(num) {
    a.assign(num.size() << 2, 0);
    build(1, 1, num.size());
  }
  void build(int p, int l, int r) {
    if (l == r) {
      a[p] = num[l - 1];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    a[p] = max(a[p + p], a[p + p + 1]);
  }
  
  void update(int at, int val) {
    update(1, 1, num.size(), at, val);
  }
  
  void update(int p, int l, int r, int at, int val) {
    //printf("seg %d %d %d %d %d\n", p, l, r, at, val);
    if (l == r) {
      a[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    a[p] = max(a[p + p], a[p + p + 1]);
  }
  
  int find(int l, int r) {
    return find(1, 1, num.size(), l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    //printf("%d %d %d %d %d\n", p, l, r, ll, rr);
    if (ll <= l && r <= rr) return a[p];
    if (rr < l || r < ll) return 0;
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<int> a, num;
};

int be[M];
int a[N];

int main() {
  for (int i = 0; i < M; i++) be[i] = 1;
  for (int i = 2; i < M; i++) {
    if (be[i] == 1) {
      for (long long j = i; j < M; j += i) {
        if (be[j] == 1) be[j] = i;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> num;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      num.push_back(be[a[i]]);
    }
    set<int> p;
    for (int i = 1; i <= n; i++) {
      if (a[i] != 1) {
        p.insert(i);
      }
    }
    segtree seg(num);
    while (m--) {
      int t, l, r;
      scanf("%d %d %d", &t, &l, &r);
      //printf("%d %d %d\n", t, l, r);
      if (t == 0) {
        vector<int> er;
        auto it = p.lower_bound(l);
        while (it != p.end() && *it <= r) {
          a[*it] /= be[a[*it]];
          if (a[*it] == 1) {
            er.push_back(*it);
          }
          seg.update(*it, be[a[*it]]);
          it++;
        }
        for (auto i : er) p.erase(i);
        //for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
        //for (int i = 1; i <= n; i++) printf("%d ", seg.find(i, i)); printf("\n");
      } else {
        printf("%d ", seg.find(l, r));
      }
    }
    printf("\n");
  }
  return 0;
}
