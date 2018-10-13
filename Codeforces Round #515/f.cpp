#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;

#define point pair<int, int>

map<int, vector<point> > mp;
long long dp[N][2];

int dist(point a, point b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void upd(long long& at, long long val) {
  at = min(at, val);
}

bool cmp(point l, point r) {
  if (l.first != r.first) return l.first < r.first;
  return l.second > r.second;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    a.push_back(max(x, y));
    mp[max(x, y)].emplace_back(x, y);
  }
  a.push_back(0);
  mp[0].emplace_back(0, 0);
  sort(a.begin(), a.end());
  a.resize(distance(a.begin(), unique(a.begin(), a.end())));
  for (auto i : a) {
    sort(mp[i].begin(), mp[i].end(), cmp);
  }
  for (int it = 1; it < a.size(); it++) {
    auto i = a[it];
    auto j = a[it - 1];
    int base = dist(mp[i][0], mp[i].back());
    dp[it][0] = dp[it][1] = inf;
    upd(dp[it][1], dp[it-1][0] + dist(mp[j][0], mp[i][0]) + base);
    upd(dp[it][1], dp[it-1][1] + dist(mp[j].back(), mp[i][0]) + base);
    upd(dp[it][0], dp[it-1][0] + dist(mp[j][0], mp[i].back()) + base);
    upd(dp[it][0], dp[it-1][1] + dist(mp[j].back(), mp[i].back()) + base);
    // printf("%lld %lld\n", dp[it][0], dp[it][1]);
  }
  cout << min(dp[a.size()-1][0], dp[a.size()-1][1]) << endl;
  return 0;
}
