#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const int inf = 1e9;

vector<int> num;
vector<int> p[N];
int a[N];
int to[N];

class segtree {
public:
  segtree(int _n) : n(_n) {
    d.resize(n << 2);
    build(1, 0, n - 1);
  }
  int find(int l, int r) {
    return _find(1, 0, n - 1, l, r);
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      d[p] = to[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    d[p] = min(d[p + p], d[p + p + 1]);
  }
  int _find(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= r) return d[p];
    if(r < ll || rr < l) return inf;
    int mid = (l + r) >> 1;
    return min(_find(p + p, l, mid, ll, rr), _find(p + p + 1, mid + 1, r, ll, rr));
  }
  int n;
  vector<int> d;
};

int id(int d) {
  return lower_bound(num.begin(), num.end(), d) - num.begin();
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    num.push_back(a[i]);
  }
  sort(num.begin(), num.end());
  num.resize(distance(num.begin(), unique(num.begin(), num.end())));
  for(int i = 0; i < n; i++) {
    p[id(a[i])].push_back(i);
  }
  for(int i = 0; i < n; i++) {
    int di = id(a[i]);
    int at = lower_bound(p[di].begin(), p[di].end(), i) - p[di].begin();
    to[i] = (at + k - 1 < p[di].size()? p[di][at + k - 1] : inf);
  }
  segtree seg(n);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    int to = seg.find(i, n - 1);
    ans += max(0, n - to);
  }
  cout << ans << endl;
  return 0;
}
