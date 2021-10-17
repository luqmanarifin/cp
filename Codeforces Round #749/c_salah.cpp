#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 6;
 
vector<string> s;
vector<vector<int>> a;  // lowest column this cell can reach
vector<vector<int>> b;  // biggest column this cell need to exit from top
 
char buf[N];
 
set<pair<int, int>> mp[N];  // column to (a, b)
 
vector<pair<int, int>> convert(set<pair<int, int>> x) {
  vector<pair<int, int>> res;
  for (auto it : x) {
    res.push_back(it);
  } 
  return res;
}
 
vector<pair<int, int>> combine(vector<pair<int, int>> c, vector<pair<int, int>> d = vector<pair<int, int>>(0)) {
  set<pair<int, int>> uni;
  for (auto it : c) uni.insert(it);
  for (auto it : d) uni.insert(it);
  auto res = convert(uni);
  for (int i = (int) res.size() - 2; i >= 0; i--) {
    res[i].second = min(res[i].second, res[i+1].second);
  }
  return res;
}
 
struct segtree {
  segtree(int n) : n(n) {
    num.resize((n + 1) << 2);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      num[p] = combine(convert(mp[l]));
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = combine(num[p + p], num[p + p + 1]);
  }
  bool find(int l, int r, int x) {
    return find(1, 1, n, l, r, x);
  }
  bool find(int p, int l, int r, int ll, int rr, int x) {
    if (ll <= l && r <= rr) {
      auto it = lower_bound(num[p].begin(), num[p].end(), make_pair(x + 1, -1));
      if (it != num[p].end()) {
        return it->second < x;
      }
      return 0;
    }
    int mid = (l + r) >> 1, ret = 0;
    if (ll <= mid) {
      ret |= find(p + p, l, mid, ll, rr, x);
    }
    if (mid < rr) {
      ret |= find(p + p + 1, mid + 1, r, ll, rr, x);
    }
    return ret;
  }
  int n;
  vector<vector<pair<int, int>>> num;
};
 
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  s = vector<string>(n + 1);
  a = vector<vector<int>>(n + 1, vector<int>(m + 1));
  b = vector<vector<int>>(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    scanf("%s", buf);
    s[i] = '.' + string(buf);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = j;
      b[i][j] = 0;
      if (j == 1) {
        a[i][j] = 0;
      }
      if (i == 1) {
        b[i][j] = j;
      }
      if (i > 1 && s[i-1][j] == '.') {
        a[i][j] = min(a[i][j], a[i-1][j]);
        b[i][j] = max(b[i][j], b[i-1][j]);
      }
      if (j > 1 && s[i][j-1] == '.') {
        a[i][j] = min(a[i][j], a[i][j-1]);
        b[i][j] = max(b[i][j], b[i][j-1]);
      }
      mp[j].insert(make_pair(a[i][j], b[i][j]));
      // printf("%d %d: %d %d\n", i, j, a[i][j], b[i][j]);
    }
  }
  segtree seg(m);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    puts(seg.find(l, r, l)? "NO" : "YES");
  }
  return 0;
}