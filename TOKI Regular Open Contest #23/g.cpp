#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int N = 305;
const double eps = 1e-7;

struct Bit {
  Bit(int n = 0) : n(n) {
    num.resize(n);
  }
  void add(int i, int x) {
    for (; i < n; i |= i + 1) {
      num[i] += x;
    }
  }
  int find(int i) {
    int ret = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      ret += num[i];
    }
    return ret;
  }
  int n;
  vector<int> num;
};

ordered_set s[N];
int n;
vector<double> X;
pair<int, int> pos[N * N];

int determine(int a) {
  auto it = lower_bound(X.begin(), X.end(), a - eps) - X.begin();
  if (it == n) return n - 1;
  if (it == 0) return 0;
  double l = abs(X[it-1] - a);
  double r = abs(X[it] - a);
  return l < r? it - 1 : it;
}

int main() {
  scanf("%d", &n);
  double now = 1e9 / n / 2;
  for (int i = 0; i < n; i++) {
    X.push_back(now);
    now += 1e9 / n;
  }
  Bit bit(n);
  for (int i = 1; i <= n * n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    pos[i] = {u, v};
    int id = determine(u);
    bit.add(id, 1);
    s[id].insert(make_pair(v, i));
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    vector<int> cur;
    for (auto it : s[i]) {
      cur.push_back(it.second);
    }
    if (i % 2) {
      reverse(cur.begin(), cur.end());
    }
    for (auto it : cur) ans.push_back(it);
  }
  for (int i = 0; i < ans.size(); i++)  {
    printf("%d%c", ans[i], i + 1 == ans.size()? '\n' : ' ');
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x, u, v;
    scanf("%d %d %d", &x, &u, &v);
    int old_id = determine(pos[x].first);
    int new_id = determine(u);
    bit.add(old_id, -1);
    s[old_id].erase(make_pair(pos[x].second, x));

    int new_idx = s[new_id].order_of_key(make_pair(v, x));
    int cnt = bit.find(new_id - 1) + (new_id % 2? s[new_id].size() - new_idx : new_idx);
    bit.add(new_id, 1);
    s[new_id].insert(make_pair(v, x));    
    pos[x] = {u, v};
    printf("%d\n", cnt + 1);
  }

  return 0;
}
