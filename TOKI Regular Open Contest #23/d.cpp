#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

long long take_3(long long n) {
  return 1LL * n * (n - 1) * (n - 2) / 3 / 2;
}

vector<pair<long long, int>> full;
vector<pair<long long, int>> star;

vector<tuple<int, int, int>> ans;

void build_full(int start, int n) {
  for (int i = 0; i + 1 < n; i++) {
    ans.emplace_back(start + i, start + i + 1, start + n - 1);
  }
}

void build_star(int start, int n) {
  ans.emplace_back(start, start + 1, start + n - 1);
}

int main() {
  long long n;
  for (int n = 4; n <= 100000; n++) {
    long long x = n * take_3(n - 1);
    if (x > 1e18) break;
    full.emplace_back(x, n);
  }
  for (int n = 4; n <= 100000; n++) {
    star.emplace_back(take_3(n - 1), n);
  }
  
  long long k;
  scanf("%lld", &k);
  int now = 1;
  while (k > 0) {
    auto it = upper_bound(full.begin(), full.end(), make_pair(k, inf)) - full.begin() - 1;
    if (it >= 0) {
      build_full(now, full[it].second);
      now += full[it].second;
      k -= full[it].first;
    } else {
      it = upper_bound(star.begin(), star.end(), make_pair(k, inf)) - star.begin() - 1;
      assert(it >= 0);
      build_star(now, star[it].second);
      now += star[it].second;
      k -= star[it].first;
    }
  }
  printf("%d\n", ans.size());
  for (auto it : ans) {
    int a, b, c;
    tie(a, b, c) = it;
    printf("%d %d %d\n", a, b, c);
  }
  return 0;
}
