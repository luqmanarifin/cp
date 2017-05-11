#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

priority_queue<int> pq[5][5];
int p[N], a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);

  for (int i = 0; i < n; i++) {
    pq[a[i]][b[i]].push(-p[i]);
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    vector<tuple<int, int, int>> v;
    int at;
    scanf("%d", &at);
    for (int i = 1; i <= 3; i++) {
      if (!pq[i][at].empty()) v.emplace_back(-pq[i][at].top(), i, at);
      if (!pq[at][i].empty()) v.emplace_back(-pq[at][i].top(), at, i);
    }
    sort(v.begin(), v.end());
    if (v.empty()) {
      printf("-1 ");
    } else {
      int s, t, val;
      tie(val, s, t) = v[0];
      printf("%d ", val);
      pq[s][t].pop();
    }
  }

  return 0;
}
