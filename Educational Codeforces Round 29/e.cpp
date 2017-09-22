#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 2e9;

struct segtree {
  segtree(vector<int> a) : a(a){
    n = a.size();
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      num[p] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = min(num[p + p], num[p + p + 1]);
  }
  int find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return inf;
    int mid = (l + r) >> 1;
    return min(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }

  vector<int> a, num;
  int n;
};

int l[N], r[N];

map<int, int> id;
vector<int> all;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", l + i, r + i);
    all.push_back(l[i]);
    all.push_back(r[i]);
    all.push_back(r[i] + 1);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i < all.size(); i++) id[all[i]] = i;

  vector<int> dp(all.size(), 0);
  for (int i = 1; i <= n; i++) {
    dp[id[l[i]]]++;
    dp[id[r[i]] + 1]--;
  }
  for (int i = 1; i < dp.size(); i++) dp[i] += dp[i - 1];
  segtree seg(dp);
  for (int i = 1; i <= n; i++) {
    if (seg.find(id[l[i]], id[r[i]]) > 1) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}