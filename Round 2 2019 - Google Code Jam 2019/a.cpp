#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const long long undef = 1e18;

long long x[N], y[N];

#define point pair<long long, long long>

point num[N];

long long solver(point a, point b) {
  long long atas = b.second - a.second;
  long long bawah = b.first - a.first;
  if (bawah == 0) return undef;
  if (atas % bawah == 0) {
    return atas / bawah * 2;
  }
  if (atas == 0) return 0;
  double ret = (double) atas / bawah;
  if (ret < 0) {
    return -(abs(atas / bawah) * 2 + 1);
  } else {
    return atas / bawah * 2 + 1;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    set<long long> sy;
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", x + i, y + i);
      sy.insert(y[i]);
      if (y[i] > 1) {
        sy.insert(y[i] - 1);
      }
    }
    auto big = sy.end();
    big--;
    sy.insert(*big + 1);

    set<vector<int> > ans;
    for (auto pivot : sy) {
      // printf("pivot %lld\n", pivot);
      for (int i = 0; i < n; i++) {
        num[i] = make_pair(x[i], pivot * y[i]);
      }
      set<long long> a;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          // printf("%d %d\n", i, j);
          auto ret = solver(num[i], num[j]);
          if (ret != undef) {
            a.insert(ret);
          }
        }
      } 
      a.insert(1);
      vector<long long> v;
      for (auto it : a) v.push_back(it);

      // puts("all delimiter found");

      for (int i = 0; i < v.size(); i++) {
        if (v[i] <= 0) continue;
        long long to = (v[i] % 2? v[i] + 1 : v[i] + 2);
        if (!a.count(to)) {
          to /= 2;
          vector<pair<long long, int>> cur;
          for (int j = 0; j < n; j++) {
            cur.emplace_back(num[j].first * to + num[j].second, j);
          }
          sort(cur.begin(), cur.end());
          vector<int> ids;
          for (auto it : cur) ids.push_back(it.second);
          ans.insert(ids);
        }
      }
    }
    printf("Case #%d: %lld\n", tt, ans.size());
  }

  return 0;
}
