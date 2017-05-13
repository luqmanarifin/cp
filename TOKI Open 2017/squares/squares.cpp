#include "squares.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
const int inf = 1e9;

int x[N], y[N];
int ans[N];
pair<int, int> p[N];
bool die[N];
multiset<int> can[N];

long long getTotalArea(int n, std::vector<int> X, std::vector<int> Y) {
  for (int i = 0; i < n; i++) {
    x[i] = X[i];
    y[i] = Y[i];
  }
  fill(ans, ans + N, inf);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cur = max(abs(x[i] - x[j]), abs(y[i] - y[j]));
      can[i].insert(cur);
      can[j].insert(cur);
    }
  }
  long long ret = 0;
  while (1) {
    int p = -1, best = inf;
    for (int i = 0; i < n; i++) if (!die[i]) {
      int cur = *(can[i].begin());
      if (cur < best) {
        best = cur;
        p = i;
      }
    }
    if (p == -1) break;
    ret += 1LL * best * best;
    die[p] = 1;
    for (int i = 0; i < n; i++) {
      if (die[i]) continue;
      int d = max(abs(x[p] - x[i]), abs(y[p] - y[i]));
      can[i].erase(can[i].find(d));
      can[i].insert(2 * d - best);
    }
  }
  return ret;
}
