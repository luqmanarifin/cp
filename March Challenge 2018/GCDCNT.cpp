
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int N = 1e5 + 5;

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set s[N];

int last[N], a[N];
vector<int> dict[N];

vector<int> get_primes(int v) {
  set<int> primes;
  vector<int> p;
  while (v > 1) {
    primes.insert(last[v]);
    v /= last[v];
  }
  for (auto it : primes) p.push_back(it);
  return p;
}

int main() {
  for (int i = 2; i < N; i++) {
    if (last[i] == 0) {
      for (int j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  for (int i = 1; i < N; i++) dict[i] = get_primes(i);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    vector<int> p = dict[a[i]];
    for (int mask = 1; mask < (1 << p.size()); mask++) {
      int now = 1;
      for (int j = 0; j < p.size(); j++) if (mask & (1 << j)) now *= p[j];
      s[now].insert(i);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, l, r, v;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &l, &v);
      for (int mask = 1; mask < (1 << dict[a[l]].size()); mask++) {
        int now = 1;
        for (int j = 0; j < dict[a[l]].size(); j++) if (mask & (1 << j)) now *= dict[a[l]][j];
        s[now].erase(l);
      }
      a[l] = v;
      for (int mask = 1; mask < (1 << dict[a[l]].size()); mask++) {
        int now = 1;
        for (int j = 0; j < dict[a[l]].size(); j++) if (mask & (1 << j)) now *= dict[a[l]][j];
        s[now].insert(l);
      }
    } else {
      scanf("%d %d %d", &l, &r, &v);
      vector<int> p = dict[v];
      int ans = r - l + 1;
      for (int mask = 1; mask < (1 << p.size()); mask++) {
        int now = 1;
        for (int j = 0; j < p.size(); j++) if (mask & (1 << j)) now *= p[j];
        int add = s[now].order_of_key(r + 1) - s[now].order_of_key(l);
        if (__builtin_popcount(mask) % 2) {
          ans -= add;
        } else {
          ans += add;
        }
      }
      printf("%d\n", ans);
    }
  }
  
  return 0;
}
