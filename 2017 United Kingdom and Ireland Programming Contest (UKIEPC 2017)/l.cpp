#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int x[N], y[N], h[N];
pair<int, int> p[N];
int tx, ty;

pair<int, int> simplify(pair<int, int> cok) {
  int u = cok.first;
  int v = cok.second;
  if (u == 0) {
    if (v > 0) return {0, 1};
    else return {0, -1};
  }
  if (v == 0) {
    if (u > 0) return {1, 0};
    else return {-1, 0};
  }
  int fpb = __gcd(abs(u), abs(v));
  u /= fpb;
  v /= fpb;
  return {u, v};
}

vector<pair<int, int>> all;
vector<int> lis[N];
int mp[N], bit[N];

int id(pair<int, int> v) {
  return lower_bound(all.begin(), all.end(), v) - all.begin();
}

void reset(int n) {
  for (int i = 0; i < n; i++) bit[i] = 0;
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret = max(ret, bit[i]);
  return ret;
}

void upd(int i, int v, int n) {
  for (; i < n; i |= i + 1) bit[i] = max(bit[i], v);
}

int main() {
  int n;
  scanf("%d %d %d", &tx, &ty, &n);
  vector<pair<long long, int>> s;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", x + i, y + i, h + i);
    p[i] = {x[i] - tx, y[i] - ty};
    p[i] = simplify(p[i]);
    all.push_back(p[i]);
    s.emplace_back(1LL * (x[i] - tx) * (x[i] - tx) + 1LL * (y[i] - ty) * (y[i] - ty), i);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  sort(s.begin(), s.end());
  for (auto it : s) {
    lis[id(p[it.second])].push_back(h[it.second]);
  }
  int ans = 0;
  for (int i = 0; i < all.size(); i++) {
    vector<int> num = lis[i];
    sort(num.begin(), num.end());
    num.resize(distance(num.begin(), unique(num.begin(), num.end())));
    for (int j = 0; j < num.size(); j++) mp[num[j]] = j;
    for (auto& j : lis[i]) j = mp[j];
    int sz = lis[i].size();
    reset(sz);
    for (auto it : lis[i]) {
      int bef = find(it - 1);
      upd(it, bef + 1, sz);
    }
    ans += find(sz - 1);
  }
  cout << ans << endl;
  return 0;
}
