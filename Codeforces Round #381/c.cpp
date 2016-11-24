#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long inf = 1e18;

int a[N], LEF[N], RIG[N];

struct rmq {
  rmq(int n, bool asc) : n(n), asc(asc) {
    num.resize(n << 2);
    add.resize(n << 2);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    add[p] = 0;
    if (l == r) {
      num[p] = a[l] + (asc? -l : +l);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = min(num[p + p], num[p + p + 1]);
  }
  void add_range(int l, int r, int val) {
    add_range(1, 1, n, l, r, val);
  }
  void add_range(int p, int l, int r, int ll, int rr, int val) {
    if (ll <= l && r <= rr) {
      add[p] += val;
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    add_range(p + p, l, mid, ll, rr, val);
    add_range(p + p + 1, mid + 1, r, ll, rr, val);
    num[p] = min(num[p + p] + add[p + p], num[p + p + 1] + add[p + p + 1]);
  }
  long long find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p] + add[p];
    if (r < ll || rr < l) return inf;
    int mid = (l + r) >> 1;
    return min(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr)) + add[p];
  }
  bool asc;
  int n;
  vector<long long> num, add; 
};

struct segtree {
  segtree(int n) : n(n) {
    num.resize(n << 2);
    L.resize(n << 2);
    R.resize(n << 2);
    lazy_L.resize(n << 2);
    lazy_R.resize(n << 2);
    build(1, 1, n);
  }
  void relax(int p, int l, int r) {
    //printf("relax %d %d %d: %d %d\n", p, l, r, L[p], R[p]);
    if (lazy_L[p] != -1) {
      if (l < r) {
        lazy_L[p + p] = lazy_L[p];
        lazy_L[p + p + 1] = lazy_L[p];
      }
      //printf("BEF %d %d %d %d-%d\n", l, r, num[p], R[p], L[p]);
      L[p] = lazy_L[p];
      num[p] = R[p] - L[p];
      //if (num[p] != 0) printf("JANCOK %d %d %d %d-%d\n", l, r, num[p], R[p], L[p]);
      lazy_L[p] = -1;
    }
    if (lazy_R[p] != -1) {
      if (l < r) {
        lazy_R[p + p] = lazy_R[p];
        lazy_R[p + p + 1] = lazy_R[p];
      }
      R[p] = lazy_R[p];
      num[p] = R[p] - L[p];
      lazy_R[p] = -1;
    }
  }
  void combine(int p, int l, int r) {
    L[p] = min(L[p + p], L[p + p + 1]);
    R[p] = max(R[p + p], R[p + p + 1]);
    //printf("combine %d %d: %d %d\n", l, r, L[p], R[p]);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  void build(int p, int l, int r) {
    lazy_L[p] = -1;
    lazy_R[p] = -1;
    if (l == r) {
      L[p] = LEF[l];
      R[p] = RIG[l];
      num[p] = R[p] - L[p];
      //printf("build %d %d %d\n", l, L[p], R[p]);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void update_L(int l, int r, int val) {
    update_L(1, 1, n, l, r, val);
  }
  void update_L(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      //printf("update L %d %d %d %d %d\n", l, r, ll, rr, val);
      lazy_L[p] = val;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    //printf("update L %d %d %d %d %d\n", l, r, ll, rr, val);
    int mid = (l + r) >> 1;
    update_L(p + p, l, mid, ll, rr, val);
    update_L(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  void update_R(int l, int r, int val) {
    update_R(1, 1, n, l, r, val);
  }
  void update_R(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      //printf("update R %d %d %d %d\n", l, r, ll, rr);
      lazy_R[p] = val;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    //printf("update R %d %d %d %d\n", l, r, ll, rr);
    int mid = (l + r) >> 1;
    update_R(p + p, l, mid, ll, rr, val);
    update_R(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  int find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    int ret = max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
    combine(p, l, r);
    return ret;
  }
  int n;
  vector<int> num, L, R, lazy_L, lazy_R;
};

int n;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  rmq asc(n, 1), des(n, 0);
  for (int i = 1; i <= n; i++) {
    long long asc_val = asc.find(i, i);
    long long des_val = des.find(i, i);
    
    int l = i, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (des.find(i, mid) == des.find(mid, mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    RIG[i] = l;
    
    l = 1; r = i;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (asc.find(mid, i) == asc.find(mid, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    LEF[i] = l;
  }
  for (int i = 1; i <= n; i++) printf("%d %d %d\n", i, LEF[i], RIG[i]);
  segtree seg(n);
  printf("pra %d\n", seg.find(1, n) + 1);
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int lef, rig, add;
    scanf("%d %d %d", &lef, &rig, &add);
    asc.add_range(lef, rig, add);
    des.add_range(lef, rig, add);
    
    long long asc_val = asc.find(lef, lef);
    long long des_val = des.find(rig, rig);
    
    int l = lef, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (asc.find(lef, mid) == asc_val) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    int until_R = l;
    
    l = 1; r = rig;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (des.find(mid, rig) == des_val) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    int until_L = l;
    
    l = 1; r = lef;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (asc.find(mid, lef) == asc.find(mid, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    int from_L = l;
    
    l = rig; r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (des.find(rig, mid) == des.find(mid, mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    int from_R = l;
    
    printf("%d %d : %d %d\n", from_L, until_R, until_L, from_R);
    seg.update_L(from_L, until_R, from_L);
    seg.update_R(until_L, from_R, from_R);
    //for (int i = 1; i <= n; i++) printf("%d ", seg.find(i, i)); printf("\n");
    printf("%d\n", seg.find(1, n) + 1);
  }

  return 0;
}
