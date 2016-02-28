#include <bits/stdc++.h>

using namespace std;

const int N = 4005;
const int inf = 1e9;

pair<int, int> pr[N];

struct segtree {
public:
  segtree(int n) : n(n) {
    lef.resize(N << 2);
    rig.resize(N << 2);
    build(1, 0, n - 1);
  }
  int find(int al, int ar, int bl, int br) {
    return find(1, 0, n - 1, al, ar, bl, br);
  }
private:
  void build(int p, int l, int r) {
    lef[p] = pr[l].first;
    rig[p] = pr[r].first;
    a[p].resize(r - l + 1);
    if(l == r) {
      a[p][0] = pr[l].second;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(a[p + p].begin(), a[p + p].end(), a[p + p + 1].begin(), a[p + p + 1].end(), a[p].begin());
  }
  int find(int p, int l, int r, int al, int ar, int bl, int br) {
    if(ar < lef[p] || rig[p] < al) {
      return 0;
    }
    if(al <= lef[p] && rig[p] <= ar) {
      return upper_bound(a[p].begin(), a[p].end(), br) - lower_bound(a[p].begin(), a[p].end(), bl);
    }
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, al, ar, bl, br) + find(p + p + 1, mid + 1, r, al, ar, bl, br);
  }
  int n;
  vector<int> a[N << 2];
  vector<int> lef, rig;
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> num;
  for(int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if(u > v) swap(u, v);
    pr[i] = {u, v};
    num.push_back(u);
    num.push_back(v);
  }
  sort(pr, pr + n);
  sort(num.begin(), num.end());
  num.resize(distance(num.begin(), unique(num.begin(), num.end())));
  
  segtree seg(n);
  long long ans = -1, a = -1, b = -1;
  for(int i = 0; i < num.size(); i++) {
    for(int j = i; j < num.size(); j++) {
      long long cnt = seg.find(num[i], inf, num[j], inf);
      if(cnt * num[i] * num[j] > ans) {
        ans = cnt * num[i] * num[j];
        a = num[i];
        b = num[j];
      }
    }
  }
  printf("%I64d\n%I64d %I64d\n", ans, a, b);
  return 0;
}
