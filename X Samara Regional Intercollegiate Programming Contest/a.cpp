#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

struct segtree {
  segtree(int n) : n(n) {
    a.assign(n << 2, {-inf, -1});
  }
  void update(int at, pair<int, int> val) {
    update(1, 0, n - 1, at, val);
  }  
  void update(int p, int l, int r, int at, pair<int, int> val) {
    if (l == r) {
      a[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    a[p] = max(a[p + p], a[p + p + 1]);
  }
  pair<int, int> find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  pair<int, int> find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return a[p];
    if (r < ll || rr < l) return {-inf, -1};
    int mid = (l + r) >> 1;
    return max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  // dapet berapa, using mana
  vector<pair<int, int>> a;
  int n;
};

int at[N];
string s[N];
int bound[N], low[N], got[N];

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  // lowest, gain, id
  vector<tuple<int, int, int>> p;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    int lowest = 0, now = 0;
    for (int j = 0; j < s[i].length(); j++) {
      if (s[i][j] == '(') {
        now++;
      } else {
        now--;
      }
      lowest = min(lowest, now);
    }
    low[i] = -lowest;
    got[i] = now;
    p.emplace_back(-lowest, now, i);
  }
  sort(p.begin(), p.end());
  segtree seg(n);
  memset(bound, -1, sizeof(bound));
  for (int i = 0; i < p.size(); i++) {
    int lowest, gain, id;
    tie(lowest, gain, id) = p[i];
    at[id] = i;
    seg.update(i, {i, id});
    bound[lowest] = max(bound[lowest], i);
  }
  for (int i = 1; i < N; i++) bound[i] = max(bound[i], bound[i - 1]);
  
  int now = 0;
  vector<int> ans;
  while (ans.size() < n) {
    if (bound[now] == -1) break;
    pair<int, int> ret = seg.find(0, bound[now]);
    int id = ret.second;
    int gain = got[id];
    if (id == -1) break;
    now += gain;
    ans.push_back(id);
    seg.update(at[id], {-inf, -1});
  }
  if (ans.size() < n || now != 0) {
    puts("NO");
  } else {
    puts("YES");
    for (auto it : ans) printf("%d ", it);
  }

  return 0;
}
