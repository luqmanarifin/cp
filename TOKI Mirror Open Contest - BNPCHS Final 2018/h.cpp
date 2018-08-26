#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int x[N], y[N];
vector<int> start[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) start[i].clear();

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", x + i, y + i);
      start[max(0, x[i] - y[i])].push_back(i);
    }
    int ans = 0;
    for (int t = 0; t < N; t++) {
      if (!start[t].empty()) {
        int now = t;
        int til = 2e9;
        do {
          for (auto id : start[now]) {
            til = min(til, x[id] + y[id]);
          }
        } while (now < til && ++now);
        t = til;
        ans++;
      }
    }
    printf("Kasus #%d: %d\n", tt, ans);
  }

  return 0;
}
