#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ans[N];

bool sign(int x) {
  return x > 0;
}


void solve(int p, int q, int r) {
  vector<pair<int, int>> v;
  v.emplace_back(a[p], p);
  v.emplace_back(a[q], q);
  v.emplace_back(a[r], r);
  sort(v.begin(), v.end());
  bool same = 1;
  for (int i = 1; i < v.size(); i++) {
    if (sign(v[i].first) != sign(v[i-1].first)) {
      same = 0;
    }
  }
  if (same) {
    ans[v[0].second] = v[2].first;
    ans[v[1].second] = v[2].first;
    ans[v[2].second] = -(v[0].first + v[1].first);
  } else {
    if (sign(v[0].first) == sign(v[1].first)) {
      ans[v[0].second] = v[2].first;
      ans[v[1].second] = v[2].first;
      ans[v[2].second] = -(v[0].first + v[1].first);
    } else {
      ans[v[0].second] = -(v[1].first + v[2].first);
      ans[v[1].second] = v[0].first;
      ans[v[2].second] = v[0].first;
    }
  }
}

void solve(int i, int j) {
  ans[i] = -a[j];
  ans[j] = a[i];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; i += 2) {
      if (i + 3 == n) {
        solve(i, i + 1, i + 2);
        break;
      } else {
        solve(i, i + 1);
      }
    }
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], i == n - 1? '\n' : ' ');
  }

  return 0;
}
