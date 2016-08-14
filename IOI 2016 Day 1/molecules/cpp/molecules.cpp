#include "molecules.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long s[N];

long long get(int l, int r) {
  return s[r] - (l - 1 >= 0? s[l - 1] : 0);
}

std::vector<int> find_subset(int l, int u, std::vector<int> w) {
  vector<pair<int, int>> a;
  for (int i = 0; i < w.size(); i++) {
    a.emplace_back(w[i], i);
  }
  int n = w.size();
  sort(a.begin(), a.end());
  s[0] = a[0].first;
  for (int i = 1; i < n; i++) {
    s[i] = s[i - 1] + a[i].first;
  }
  
  long long sm = 0, bg = 0;
  for (int k = 1; k <= w.size(); k++) {
    sm += a[k - 1].first;
    bg += a[n - k].first;
    if (l <= bg && sm <= u) {
      for (int i = 0; i + k <= n; i++) {
        long long now = get(i, i + k - 1);
        if (l <= now && now <= u) {
          vector<int> ans;
          for (int j = i; j < i + k; j++) {
            ans.push_back(a[j].second);
          }
          return ans;
        }
      }
      assert(0);
    }
  }
  return vector<int>();
}
