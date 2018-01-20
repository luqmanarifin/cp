#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 5e5 + 5;

bool is[N];



int main() {
  is[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  int sum = n - 1;
  while (is[sum]) sum++;
  
  vector<tuple<int, int, int>> ans;
  set<pair<int, int>> s;
  int udah = 0;
  for (int i = 2; i < n; i++) {
    s.insert(make_pair(i - 1, i));
    ans.emplace_back(i - 1, i, 1);
    udah++;
  }
  s.insert(make_pair(n - 1, n));
  ans.emplace_back(n - 1, n, sum - udah);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (s.size() == m) goto hell;
      if (s.count(make_pair(i, j))) continue;
      s.insert(make_pair(i, j));
      ans.emplace_back(i, j, inf);
    }
  }
  hell:;
  printf("%d %d\n", sum, sum);
  for (auto it : ans) {
    int u, v, w;
    tie(u, v, w) = it;
    printf("%d %d %d\n", u, v, w);
  }
  
  return 0;
}
