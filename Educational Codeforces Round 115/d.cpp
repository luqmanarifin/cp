#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 5;

vector<vector<int>> bas_lef, bas_rig;

long long cnt_lef[N], cnt_rig[N];
long long now, tot_lef, tot_rig;
int n;

void add(int x, int add_lef, int add_rig) {
  now -= cnt_lef[x] * cnt_rig[x];
  cnt_lef[x] += add_lef;
  cnt_rig[x] += add_rig;
  tot_lef += add_lef;
  tot_rig += add_rig;
  now += cnt_lef[x] * cnt_rig[x];
}

long long solve(vector<vector<int>>& a) {
  long long ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i].size();
  }
  long long rig = sum;
  for (int i = 1; i <= n; i++) {
    rig -= a[i].size();
    long long here = a[i].size();
    long long bef = sum - rig - here;
    ans += here * bef * rig;
  }
  return ans;
}

void init() {
  bas_lef = vector<vector<int>>(n + 1);
  bas_rig = vector<vector<int>>(n + 1);
  now = tot_lef = tot_rig = 0;
}

void clear() {
  for (int i = 1; i <= n; i++) {
    cnt_lef[i] = cnt_rig[i] = 0;
  }
  bas_lef.clear();
  bas_rig.clear();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      bas_lef[u].push_back(v);
      bas_rig[v].push_back(u);
      add(v, 0, 1);
    }
    long long ans = solve(bas_lef) + solve(bas_rig);
    for (int i = 1; i <= n; i++) {
      for (auto it : bas_lef[i]) add(it, 0, -1);
      for (auto x : bas_lef[i]) {
        long long dif = tot_lef * tot_rig - now;
        dif -= cnt_lef[x] * (tot_rig - cnt_rig[x]);
        dif -= cnt_rig[x] * (tot_lef - cnt_lef[x]);
        ans -= dif;
      }
      for (auto it : bas_lef[i]) add(it, 1, 0);
    }
    printf("%lld\n", ans);
    clear();
  }

  return 0;
}
