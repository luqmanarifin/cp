#include <bits/stdc++.h>

using namespace std;

void solve(long long n) {
  printf("%I64d %I64d\n", n / 2, (n - 1) / 2);
}

void solve(long long k, map<long long, long long> m) {
  vector<pair<long long, long long>> v;
  long long tot = 0;
  for (auto it : m) {
    v.emplace_back(it.first, it.second);
    tot += it.second;
  }
  reverse(v.begin(), v.end());
  if (k <= tot) {
    for (auto it : v) {
      if (k > it.second) {
        k -= it.second;
      } else {
        solve(it.first);
        break;
      }
    }
  } else {
    map<long long, long long> m_new;
    for (auto it : v) {
      m_new[it.first / 2] += it.second;
      m_new[(it.first - 1) / 2] += it.second;
    }
    solve(k - tot, m_new);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    printf("Case #%d: ", tt);
    map<long long, long long> m;
    m[n] = 1;
    solve(k, m);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
