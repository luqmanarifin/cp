#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 2e5 + 5;

struct segtree {
public:
  segtree(vector<long long>& _a) {
    a = _a;
    n = a.size();
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  int get(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) {
      return num[p];
    }
    long long ret = -1, pos = -1;
    int mid = (l + r) >> 1;
    if(ll <= mid) {
      int rek = get(p << 1, l, mid, ll, rr);
      if(a[rek] > ret) {
        pos = rek;
        ret = a[rek];
      }
    }
    if(mid < rr) {
      int rek = get(p << 1 | 1, mid + 1, r, ll, rr);
      if(a[rek] > ret) {
        pos = rek;
        ret = a[rek];
      }
    }
    return pos;
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      num[p] = l;
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    num[p] = (a[num[p << 1]] >= a[num[p << 1 | 1]]? num[p << 1] : num[p << 1 | 1]);
  }
  vector<long long> a;
  vector<long long> num;
  int n;
};

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long now = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if(i < k) {
      now += a[i];
    }
  }
  vector<long long> pre;
  pre.push_back(now);
  for(int i = 1; i + k <= n; i++) {
    now -= a[i - 1];
    now += a[i + k - 1];
    pre.push_back(now);
  }
  
  segtree seg(pre);
  long long maxi = -1;
  pair<int, int> ans = {-1, -1};
  for(int i = 0; i + 2 * k <= n; i++) {
    long long cur = pre[i];
    int pos = seg.get(1, 0, pre.size() - 1, i + k, pre.size() - 1);
    if(cur + pre[pos] > maxi) {
      maxi = cur + pre[pos];
      ans = make_pair(i, pos);
    }
  }
  printf("%d %d\n", ans.first + 1, ans.second + 1);
  return 0;
}
