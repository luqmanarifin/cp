#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int> ii;

const int N = 5e5 + 5;
const long long inf = 1e18;

int a[N], n; 
ii b[N], c[N];
int bit[N];

struct segtree {
public:
  segtree() {
    num.assign(n << 2, vector<int>());
    build(1, 1, n);
  }
  // finding number of element < val between l <= i <= r
  int get(int l, int r, int va, int vb) {
    if(l > r) return 0;
    return _get(1, 1, n, l, r, va, vb);
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
  int _get(int p, int l, int r, int ll, int rr, int va, int vb) {
    if(r < ll || rr < l) return 0;
    if(ll <= l && r <= rr) return lower_bound(num[p].begin(), num[p].end(), vb) - lower_bound(num[p].begin(), num[p].end(), va);
    int mid = (l + r) >> 1;
    return _get(p + p, l, mid, ll, rr, va, vb) + _get(p + p + 1, mid + 1, r, ll, rr, va, vb);
  }
  vector<vector<int>> num;
};

void updr(int x) {
  for(; x; x -= x&(-x)) bit[x]++;
}
int getr(int x) {
  int ret = 0;
  for(; x <= n; x += x&(-x)) ret += bit[x];
  return ret;
}
void updl(int x) {
  for(; x <= n; x += x&(-x)) bit[x]++;
}
int getl(int x) {
  int ret = 0; 
  for(; x; x -= x&(-x)) ret += bit[x];
  return ret;
}

segtree* seg;

// swapping(l, r)
long long find(int p, int q) {
  long long dif = 0;
  if(p != q) {
    if(a[p] > a[q]) {
      dif = -2 * seg->get(p + 1, q - 1, a[q], a[p]) - 1;
    } else {
      dif = inf;
    }
  }
  return dif;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i<=n; i++)
    scanf("%d", a+i);
  seg = new segtree();
  for(int i = 1; i<=n; i++) {
    updr(a[i]);
    b[i] = make_pair(-getr(a[i]), i);
  }
  for(int i = 0; i<= n; i++) bit[i] = 0;
  for(int i = n; i>=1; i--) {
    updl(a[i]);
    c[i] = make_pair(-getl(a[i]), i);
  }
  sort(b+1, b+n+1);
  sort(c+1, c+n+1);
  for(int j = 1; j <= n; j++) {
    for(int i = 1; i<=1; i++) {
      if(c[j].second < b[i].second && a[c[j].second] > a[b[i].second] ) {
        int p = min(c[j].second, b[i].second);
        int q = max(c[j].second, b[i].second);
        printf("%d %d\n", p, q);
        return 0;
      }
    }
  }
  puts("Cool Array");
  return 0;
}