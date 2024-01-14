#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

map<long long, int> mp;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    mp.clear();
    long long size = 0;
    vector<pair<long long, long long>> v;

    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
      int b, x;
      scanf("%d %d", &b, &x);
      if (b == 1) {
        // printf("answer of %lld: %d\n", size, x);
        mp[size] = x;
        size++;

      } else {
        if (size >= inf) continue;
        if ((inf + size - 1) / size <= x + 1) {
          v.emplace_back(size, inf);
          size = inf;
        } else if (size * (x + 1) >= inf) {
          v.emplace_back(size, inf);
          size = inf;
        } else {
          v.emplace_back(size, (x + 1) * size);
          size *= (x + 1);
        }
      }
    }
    reverse(v.begin(), v.end());
    // for (auto it : v) printf("carry %lld %lld\n", it.first, it.second);

    vector<int> ans;
    for (int i = 0; i < q; i++) {
      long long x;
      scanf("%lld", &x);
      x--;
      bool found = 0;
      if (mp.count(x)) {
        found = 1;
        ans.push_back(mp[x]);
      }
      for (auto it : v) {
        if (found) break;
        if (x < it.second) {
          // printf("from %lld\n", x);
          x %= it.first;
          // printf("now become %lld\n", x);
          if (mp.count(x)) {
            ans.push_back(mp[x]);
            found = 1;
            break;
          }
        }
      }
      // printf("question %d: %d\n", i + 1, found);
      assert(found);
    }
    for (int i = 0; i < q; i++) printf("%d%c", ans[i], i + 1 == q? '\n' : ' ');
  }

  return 0;
}
