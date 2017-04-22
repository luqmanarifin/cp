#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const double eps = 1e-9;

struct item {
  item(int v, double t, double x) : v(v), t(t), x(x) {}
  int v;
  double t;
  double x;
};

vector<item> p[N];
int k[N], s[N];

double find(int a, int b, double d) {
  return (double) a * d / (b - a);
}

bool equal(double a, double b) {
  return abs(a - b) < eps;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tt = 1; tt <= tc; tt++) {
    for (int i = 0; i < N; i++) p[i].clear();
    
    int d, n;
    scanf("%d %d", &d, &n);
    vector<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", k + i, s + i);
      all.emplace_back(k[i], s[i]);
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < n; i++) {
      p[i].emplace_back(item(all[i].second, 0, all[i].first));
    }
    for (int i = n - 1; i >= 0; i--) {
      for (auto it : p[i + 1]) {
        item now = p[i].back();
        if (!equal(now.t, it.t)) {
          now.x += (it.t - now.t) * now.v;
          now.t = it.t;
        }
        //printf("%d %d %d\n", i, now.v, it.v);
        if (now.v > it.v) {
          //printf("woi anjing %d\n", i);
          double add = find(it.v, now.v, it.x - now.x);
          double t = (double) add / it.v;
          if (it.x + add <= d) {
            p[i].push_back(item(it.v, it.t + t, it.x + add));
          }
        }
      }
    }
    item last = p[0].back();
    //printf("%d %.15f %.15f\n", last.v, last.t, last.x);
    double time_all = last.t + (equal(last.x, d)? 0 : (double) (d - last.x) / last.v);
    printf("Case #%d: %.15f\n", tt, (double) d / time_all);
  }

  return 0;
}
