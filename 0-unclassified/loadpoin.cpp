#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

struct segtree {
  segtree(vector<pair<int, int>> _ori) : ori(_ori){
    build(1, 0, ori.size() - 1);
  }
  int query(int ll, int rr, int u, int v) {
    return query(1, 0, ori.size() - 1, ll, rr, u, v);
  }
  void build(int p, int l, int r) {
    a[p] = new int[r - l + 1];
    if(l == r) {
      a[p][0] = ori[l].second;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(a[p + p], a[p + p] + mid + 1 - l, a[p + p + 1], a[p + p + 1] + r - mid, a[p]);
  }
  int query(int p, int l, int r, int ll, int rr, int u, int v) {
    if(rr < ori[l].first || ori[r].first < ll) return 0;
    if(ll <= ori[l].first && ori[r].first <= rr) return upper_bound(a[p], a[p] + r-l+1, v) - lower_bound(a[p], a[p] + r-l+1, u);
    int mid = (l + r) >> 1;
    return query(p + p, l, mid, ll, rr, u, v) + query(p + p + 1, mid + 1, r, ll, rr, u, v);
  }
  vector<pair<int, int>> ori;
  int* a[N << 2];
};

vector<pair<int, int>> p;
vector<int> pa, pb;
int pt;
segtree* seg;

int solve(int mid) {
  int ans = 0;
  ans = max(ans, seg->query(pt, inf, -inf, mid));
  ans = max(ans, seg->query(pt, inf, mid, inf));
  ans = max(ans, seg->query(-inf, pt, -inf, mid));
  ans = max(ans, seg->query(-inf, pt, mid, inf));
  return ans;
}

int main() {
  freopen("balancing.in","r",stdin); freopen("balancing.out","w",stdout);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    p.emplace_back(a, b);
    pa.push_back(a);
    pb.push_back(b);
  }
  pa.push_back(inf);
  pb.push_back(inf);
  sort(p.begin(), p.end());
  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());
  pa.resize(distance(pa.begin(), unique(pa.begin(), pa.end())));
  pb.resize(distance(pb.begin(), unique(pb.begin(), pb.end())));
  
  seg = new segtree(p);
  int ans = inf;
  for(auto it : pa) {
    pt = it - 1;
    int l = 0, r = pb.size() - 1;
    while(r - l >= 3) {
      int lef = l + (r - l) / 3;
      int rig = r - (r - l) / 3;
      if(solve(pb[lef] - 1) < solve(pb[rig] - 1)) {
        r = rig;
      } else {
        l = lef;
      }
    }
    for(int i = l; i <= r; i++) {
      ans = min(ans, solve(pb[i] - 1));
    }
  }
  cout << ans << endl;
  return 0;
}