#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    for (int i = 0; i < (N << 2); i++) {
      num[i] = 0;
    }
  }
  void combine(int p, int l, int r) {
    if (l == r) {
      // printf("fixing %d\n", l);
      if (v[p].empty()) {
        num[p] = 0;
      } else {
        auto it = v[p].end();
        it--;
        num[p] = *it;
      }
      // printf("%d: %d\n", l, num[p]);
    } else {
      num[p] = max(num[p + p], num[p + p + 1]);
    }
  }
  void insert(int i, int val) {
    insert(1, 0, n - 1, i, val);
  }
  void insert(int p, int l, int r, int i, int val) {
    if (l == r) {
      v[p].insert(val);
      combine(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
      insert(p + p, l, mid, i, val);
    } else {
      insert(p + p + 1, mid + 1, r, i, val);
    }
    combine(p, l, r);
  }
  void remove(int i, int val) {
    // printf("removing %d %d\n", i, val);
    remove(1, 0, n - 1, i, val);
  }
  void remove(int p, int l, int r, int i, int val) {
    if (l == r) {
      v[p].erase(v[p].find(val));
      combine(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
      remove(p + p, l, mid, i, val);
    } else {
      remove(p + p + 1, mid + 1, r, i, val);
    }
    combine(p, l, r);
  }
  int find(int l, int r) {
    if (l > r) return 0;
    return find(1, 0, n - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    int mid = (l + r) >> 1, ret = 0;
    if (ll <= mid) {
      ret = max(ret, find(p + p, l, mid, ll, rr));
    }
    if (mid < rr) {
      ret = max(ret, find(p + p + 1, mid + 1, r, ll, rr));
    }
    return ret;
  }
  multiset<int> v[N << 2];
  int num[N << 2], n;
};

vector<long long> all;

int id(int val) {
  return lower_bound(all.begin(), all.end(), val) - all.begin();
}

int main() {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  vector<pair<long long, long long> > p;
  for (int i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    all.push_back(x);
    all.push_back(y);
    p.emplace_back(x, y);
    ans = max(ans, x * y);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  segtree seg(all.size());
  int all_size = all.size();

  // puts("segtree done");

  for (int i = 0; i < n; i++) {
    int x = p[i].first;
    int y = p[i].second;
    int idx = id(x);
    int idy = id(y);

    seg.insert(idx, y);
    seg.insert(idy, x);
  } 

  // puts("segtree init done");
  // for (int j = 0; j < all_size; j++) printf("%d %d\n", all[j], seg.find(j, j));
  // puts("");

  for (int i = 0; i < n; i++) {
    int x = p[i].first;
    int y = p[i].second;
    int idx = id(x);
    int idy = id(y);

    seg.remove(idx, y);
    seg.remove(idy, x);

    int best_x = min(y, seg.find(idx, all_size - 1));
    int best_y = min(x, seg.find(idy, all_size - 1));
    // printf("removing %d: %d %d\n", i, x, y);
    // for (int j = 0; j < all_size; j++) printf("%d %d\n", all[j], seg.find(j, j));
    // printf("best x %d %d\n", x, best_x);
    // printf("best y %d %d\n", y, best_y);
    // puts("");

    ans = max(ans, 2LL * x * best_x);
    ans = max(ans, 2LL * y * best_y);

    seg.insert(idx, y);
    seg.insert(idy, x);
  }
  cout << ans / 2 << (ans % 2 ? ".5" : ".0") << endl;
  return 0;
}
