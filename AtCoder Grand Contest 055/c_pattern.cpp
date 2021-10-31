#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

long long mod = 1e9 + 7;

long long c[N][N];

int lis(vector<int> a) {
  int ret = 0;
  vector<int> v(a.size());
  for (int i = 0; i < a.size(); i++) {
    v[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        v[i] = max(v[i], v[j] + 1);
      }
    }
    ret = max(ret, v[i]);
  }
  return ret;
}

int cnt[10][10];  // base - fill in

int main() {
  for (int i = 1; i < N; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    }
  }

  int n = 7;
  vector<int> p;
  for (int i = 1; i <= n; i++) p.push_back(i);
  set<vector<int>> s;
  do {
    vector<int> a;
    for (int i = 0; i < p.size(); i++) {
      vector<int> v;
      for (int j = 0; j < p.size(); j++) {
        if (i == j) continue;
        v.push_back(p[j]);
      }
      a.push_back(lis(v));
    }
    bool good = 1;
    for (auto it : a) if (it <= 1) good = 0;
    if (good) {
      s.insert(a);
    }
  } while (next_permutation(p.begin(), p.end()));
  for (auto v : s) {
    int mn = 1e9;
    for (auto it : v) mn = min(mn, it);
    int seed = 0, fill = 0;
    for (int i = 0; i < v.size(); i++) {
      int shift = v.size() - i - 1;
      seed += ((v[i] - mn) << shift);
    }
    cnt[mn][__builtin_popcount(seed)]++;
    for (auto it : v) printf("%d ", it); printf("- %d\n", seed);
  }
  for (int base = 2; base <= n - 3; base++) {
    int fill_min = n - 1 - base;
    for (int i = fill_min; i < n; i++) {
      printf("base %d fill %d: combin %d actual %d\n", base, i, c[n][i], cnt[base][i]);
    }
  }
  return 0;
}
