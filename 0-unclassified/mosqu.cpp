#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct frog {
  int pos, id, cnt;
  long long len;
  frog() : pos(0), len(0), id(0), cnt(0) {}
  frog(int pos, long long len, int id) : pos(pos), len(len), id(id), cnt(0) {}
  bool operator< (frog other) const {
    return pos < other.pos;
  }
  long long range() {
    return pos + len;
  }
};

frog a[N];
long long bit[N];
int n;

bool cmp(frog a, frog b) {
  return a.id < b.id;
}

long long find(int i) {
  long long ret = -1;
  for(; i >= 0; i = (i & (i + 1)) - 1) {
    ret = max(ret, bit[i]);
  }
  return ret;
}

void add(int i, long long val) {
  for(; i <= n; i |= i + 1) {
    bit[i] = max(bit[i], val);
  }
}

int can(int p) {
  int l = 0, r = n;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(p < a[mid].pos) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}  

bool del(int p, int v) {
  int lim = can(p);
  int l = 0, r = lim;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(p <= find(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if(l == lim) return 0;
  a[l].cnt++;
  a[l].len += v;
  add(l, a[l].range());
  return 1;
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) {
    int pos, len;
    scanf("%d %d", &pos, &len);
    a[i] = frog(pos, len, i);
  }
  sort(a, a + n);
  for(int i = 0; i < n; i++) {
    add(i, a[i].range());
  }
  multiset<pair<int, int>> ada;
  while(q--) {
    int p, v;
    scanf("%d %d", &p, &v);
    ada.insert(make_pair(p, v));
    
    vector<pair<int, int>> lost;
    auto it = ada.lower_bound({p, v});
    while(it != ada.end()) {
      if(del(it->first, it->second)) {
        lost.push_back(*it);
        it++;
      } else {
        break;
      }
    }
    for(auto it : lost) {
      ada.erase(ada.find(it));
    }
  }
  sort(a, a + n, cmp);
  for(int i = 0; i < n; i++) {
    printf("%d %I64d\n", a[i].cnt, a[i].len);
  }
  return 0;
}
