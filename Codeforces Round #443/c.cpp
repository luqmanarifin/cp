
#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

struct group {
  group() {}
  group(vector<int> a) {
    lo = hi = a;
    size = 1;
  }
  void join(group other) {
    size += other.size;
    for (int i = 0; i < lo.size(); i++) {
      lo[i] = min(lo[i], other.lo[i]);
      hi[i] = max(hi[i], other.hi[i]);
    }
  }
  bool operator< (const group& other) const {
    return lo[0] < other.lo[0];
  }
  bool operator== (const group& other) const {
    if (size != other.size) return 0;
    for (int i = 0; i < lo.size(); i++) {
      if (lo[i] != other.lo[i]) return 0;
      if (hi[i] != other.hi[i]) return 0;
    }
    return 1;
  }
  vector<int> lo, hi;
  int size;
};

// apakah A menang lawan B
bool win(group a, group b) {
  for (int i = 0; i < a.lo.size(); i++) {
    if (a.hi[i] > b.lo[i]) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  multiset<group> s;
  for (int i = 0; i < n; i++) {
    vector<int> a;
    for (int j = 0; j < m; j++) {
      int v;
      scanf("%d", &v);
      a.push_back(v);
    }
    group now(a);
    for (int j = 0; j < m; j++) {
      while (1) {
        auto it = s.lower_bound(now);
        if (it != s.end() && win(*it, now) && win(now, *it)) {
          //printf("join %d ama %d\n", now.lo[0], it->lo[0]);
          now.join(*it);
          s.erase(it);
        } else if (it != s.begin()) {
          it--;
          if (win(*it, now) && win(now, *it)) {
            now.join(*it);
            s.erase(it);
          } else {
            break;
          }
        } else {
          break;
        }
      }
    }
    s.insert(now);
    auto it = s.end();
    it--;
    printf("%d\n", it->size);
  }

  return 0;
}
