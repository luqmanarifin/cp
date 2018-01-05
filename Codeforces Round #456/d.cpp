#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<int, bool> done[N];

vector<int> build(int n, int k) {
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    int l = max(1, i - k + 1);
    int r = min(i, n - k + 1);
    a.push_back(r - l + 1);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  return a;
}

int main() {
  int n, m, r, k;
  scanf("%d %d %d %d", &n, &m, &r, &k);
  auto a = build(n, r);
  auto b = build(m, r);
  set<tuple<long long, int, int>> s;
  s.insert(make_tuple(1LL * a[0] * b[0], 0, 0));
  done[0][0] = 1;
  long long tot = 0;
  while (!s.empty() && k--) {
    auto it = s.end();
    it--;
    long long gain; int i, j;
    tie(gain, i, j) = *it;
    tot += gain;
    s.erase(it);
    if (i + 1 < a.size() && !done[i+1][j]) {
      done[i+1][j] = 1;
      s.insert(make_tuple(1LL * a[i+1] * b[j], i + 1, j));
    }
    if (j + 1 < b.size() && !done[i][j+1]) {
      done[i][j+1] = 1;
      s.insert(make_tuple(1LL * a[i] * b[j+1], i, j + 1));
    }
  }
  long long all = 1LL * (n - r + 1) * (m - r + 1);
  printf("%.15f\n", (double) tot / all);
  return 0;
}
