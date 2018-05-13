#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int ans[N], s[N], d[N], c[N];
vector<int> start_at[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", s + i, d + i, c + i);
    ans[d[i]] = m + 1;
    start_at[s[i]].push_back(i);
  }
  // deadline kapan, exam ID
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= n; i++) {
    for (auto it : start_at[i]) {
      for (int j = 0; j < c[it]; j++) {
        pq.emplace(-d[it], it);
      }
    }
    if (ans[i] == 0 && !pq.empty()) {
      int id = pq.top().second;
      pq.pop();
      if (i < d[id]) {
        ans[i] = id;
      } else {
        puts("-1");
        return 0;
      }
    }
  }
  if (!pq.empty()) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

  return 0;
}
