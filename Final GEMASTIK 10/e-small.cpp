#include <bits/stdc++.h>

using namespace std;

#define int long long

set<pair<int, int>> all;
map<int, int> cnt;

void insert(int v, int k) {
  if (cnt[v] == 0) {
    int l = v, r = v;
    vector<pair<int, int>> rem;
    auto it = all.lower_bound(make_pair(v + 1, -1));
    if (it != all.end()) {
      if (v + 1 == it->first) {
        r = it->second;
        rem.push_back(*it);
      }
    }
    if (it != all.begin()) {
      it--;
      if (it->second + 1 == v) {
        l = it->first;
        rem.push_back(*it);
      }
    }
    for (auto it : rem) all.erase(it);
    all.insert(make_pair(l, r));
  }
  cnt[v] += k;
}

void hapus(int v, int k) {
  bool needDel = (cnt[v] > 0);
  cnt[v] = max(0LL, cnt[v] - k);
  if (cnt[v] == 0 && needDel) {
    auto it = all.lower_bound(make_pair(v + 1, -1));
    vector<pair<int, int>> add; 
    it--;
    if (it->first < v) {
      add.push_back(make_pair(it->first, v - 1));
    }
    if (v < it->second) {
      add.push_back(make_pair(v + 1, it->second));
    }
    all.erase(it);
    for (auto it : add) all.insert(it);
  }
}

int get() {
  if (all.empty()) return 1;
  auto it = all.begin();
  if (it->first > 1) return 1;
  return it->second + 1;
}

main() {
  int t;
  scanf("%lld", &t);
  while (t--) {
    all.clear();
    cnt.clear();
    int q;
    scanf("%lld", &q);
    while (q--) {
      int p, l, r, k;
      scanf("%lld %lld %lld %lld", &p, &l, &r, &k);
      assert(l == r);
      if (p == 1) {
        insert(l, k);
      } else {
        hapus(l, k);
      }
      printf("%lld\n", get());
    }
  }

  return 0;
}