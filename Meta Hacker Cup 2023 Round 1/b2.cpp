#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

map<pair<int, int>, int> mp;
map<pair<int, int>, int> to;

int solve(int now, int x) {
  auto c = make_pair(now, x);
  if (mp.count(c)) return mp[c];
  if (x == 0) {
    if (now == 1) return 0;
    return inf;
  }
  int ans = inf;
  for (int i = min(now, x); i >= 1; i--) {
    if (now % i == 0) {
      int ret = solve(now / i, x - i);
      if (ret != inf && ret + 1 < ans) {
        ans = ret + 1;
        to[c] = i;
      }
    }
  }
  return mp[c] = ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    int done = solve(n, 41);
    
    printf("Case #%d: ", tt);
    if (done != inf) {
      vector<int> ans;
      int now = n, sum = 41;
      while (sum > 0) {
        int x = to[make_pair(now, sum)];
        ans.push_back(x);
        now /= x;
        sum -= x;
      }

      printf("%d", ans.size());
      for (auto it : ans) printf(" %d", it);
      printf("\n");
    } else {
      printf("-1\n");
    }
    cerr << tt << " done!" << endl;
  }

  return 0;
}
