#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int T, n;
vector<pair<int, int>> q[N];    // t, id

vector<int> x;

// ada berapa - pas kapan
pair<int, int> solve(bool jawab = 0, int at = 0) {
  int ans = -1, p = -1;
  int time = 0;
  
  priority_queue<pair<int, int>> pq;
  set<pair<int, int>> s;
  for (int i = n; i >= 1; i--) {
    for (auto it : q[i]) {
      pq.push(it);
      time += it.first;
    }
    while (pq.size() > i || time > T) {
      auto it = pq.top();
      pq.pop();
      s.insert(it);
      time -= it.first;
    }
    while (pq.size() + 1 <= i && !s.empty() && time + (s.begin())->first <= T) {
      auto it = *(s.begin());
      s.erase(it);
      pq.push(it);
      time += it.first;
    }
    //printf("iterasi %d pq size %d\n", i, pq.size());
    if ((int) pq.size() > ans) {
      ans = (int) pq.size();
      p = i;
    }
    if (jawab && at == i) {
      while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        x.push_back(it.second);
      }
      return {ans, i};
    }
  }
  //printf("%d %d\n", ans, p);
  return {ans, p};
}

int main() {
  scanf("%d %d", &n, &T);
  for (int i = 0; i < n; i++) {
    int a, t;
    scanf("%d %d", &a, &t);
    q[a].emplace_back(t, i + 1);
  }
  auto ans = solve();
  solve(1, ans.second);
  printf("%d\n%d\n", ans.first, x.size());
  for (auto it : x) printf("%d ", it); printf("\n");
  return 0;
}
