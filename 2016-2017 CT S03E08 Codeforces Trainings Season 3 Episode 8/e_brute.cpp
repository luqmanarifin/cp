#include <bits/stdc++.h>

using namespace std;

const int N = 6;

int a[N], n, sum[1 << N];
double lim;
bool ada;
double ans;

vector<pair<double, double>> all[1 << N];

void dfs(int mask) {
  if (all[mask].size()) return;
  if (__builtin_popcount(mask) == 1) {
    all[mask].emplace_back(0, 0);
    return;
  }
  for (int i = ((mask - 1) & mask); i > 0; i = ((i - 1) & mask)) {
    int j = (mask ^ i);
    dfs(i);
    dfs(j);
    double lf = (double) sum[j] / sum[mask];
    double rf = (double) sum[i] / sum[mask];
    for (auto l : all[i]) {
      for (auto r : all[j]) {
        double lef = min(-lf + l.first, rf + r.first);
        double rig = max(rf + r.second, -lf + l.second);
        all[mask].emplace_back(lef, rig);
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < (1 << N); i++) all[i].clear();
    
    scanf("%lf %d", &lim, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int mask = 0; mask < (1 << n); mask++) {
      sum[mask] = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
          sum[mask] += a[i];
        }
      }
    }
    ans = 0;
    ada = 0;
    
    int mask = (1 << n) - 1;
    /*
    for (int i = 1; i < mask; i++) {
      dfs(i);
      printf("%d\n", i);
      for (auto it : all[i]) printf("%.6f %.6f\n", it.first, it.second);
    }
    */
    for (int i = 1; i < mask; i++) {
      int j = (mask ^ i);
      dfs(i);
      dfs(j);
      double lf = (double) sum[j] / sum[mask];
      double rf = (double) sum[i] / sum[mask];
      for (auto l : all[i]) {
        for (auto r : all[j]) {
          double lef = min(-lf + l.first, rf + r.first);
          double rig = max(rf + r.second, -lf + l.second);
          double cur = rig - lef;
          if (cur < lim) {
            ada = 1;
            ans = max(ans, cur);
          }
        }
      }
    }
    if (n == 1) {
      puts("0");
    } else if (ada) {
      printf("%.15f\n", ans);
    } else {
      puts("-1");
    }
  }

  return 0;
}
