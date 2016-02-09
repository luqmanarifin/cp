#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int a[N], n;

struct segtree {
public:
  segtree() {
    num.assign(n << 2, vector<int>());
    build(1, 1, n);
  }
  // finding number of element < val between l <= i <= r
  int get(int l, int r, int val) {
    if(l > r) return 0;
    return _get(1, 1, n, l, r, val);
  }
private:
  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    if(l == r) {
      num[p][0] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p+p].begin(), num[p+p].end(), num[p+p+1].begin(), num[p+p+1].end(), num[p].begin());
  }
  int _get(int p, int l, int r, int ll, int rr, int val) {
    if(r < ll || rr < l) return 0;
    if(ll <= l && r <= rr) return lower_bound(num[p].begin(), num[p].end(), val) - num[p].begin();
    int mid = (l + r) >> 1;
    return _get(p + p, l, mid, ll, rr, val) + _get(p + p + 1, mid + 1, r, ll, rr, val);
  }
  vector<vector<int>> num;
};

void brute() {
  int now = 0, pp = -1, qq = -1;
  for(int p = 1; p <= n; p++) {
    for(int q = p + 1; q <= n; q++) {
      int cur = (a[p] < a[q]? 1 : -1);
      for(int i = p + 1; i < q; i++) {
        if(a[i] < a[p]) {
          cur--;
        } else {
          cur++;
        }
        if(a[i] < a[q]) {
          cur++;
        } else {
          cur--;
        }
      }
      if(cur < now) {
        now = cur;
        pp = p;
        qq = q;
      }
    }
  }
  if(now == 0) {
    puts("Cool Array");
  } else {
    //printf("dapet %d\n", now);
    printf("%d %d\n", pp, qq);
  }
}

segtree* seg;

// swapping(l, r)
long long find(int p, int q) {
  long long dif = 0;
  if(p != q) {
    int len = q - p - 1;
    int less = seg->get(p + 1, q - 1, a[p]);
    dif -= less;
    dif += len - less;
    
    less = seg->get(p + 1, q - 1, a[q]);
    dif += less;
    dif -= len - less;
    if(a[p] > a[q]) {
      dif--;
    } else {
      dif++;
    }
  }
  return dif;
}

int main() {
  scanf("%d", &n);
  
  long long awal = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  if(n <= 200) {
    brute();
    return 0;
  }
  seg = new segtree();
  vector<tuple<long long, int, int>> num;
  for(int i = 1; i <= n; i++) {
    int p = a[i];
    int q = i;
    if(p > q) {
      swap(p, q);
    }
    for(int j = i + 1; j <= n; j++) {
      printf("%lld ", find(i, j));
    }
    printf("\n");
    long long dif = find(p, q);
    if(dif < 0) {
      num.emplace_back(dif, p, q);
    }
  }
  if(num.empty()) {
    puts("Cool Array");
    return 0;
  }
  sort(num.begin(), num.end());
  int p, q;
  tie(ignore, p, q) = num[0];
  printf("%d %d\n", p, q);
  return 0;
}
