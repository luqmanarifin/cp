#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int w[N], l[N];
bool can[N];
vector<int> ans[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", w + i, l + i);
    can[i] = (w[i] < l[i]);
  }
  int m;
  vector<pair<int, int> > p;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int v;
    scanf("%d", &v);
    p.emplace_back(v, i);
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  for (auto it : p) {
    int now = 0;
    while (now < it.first) {
      int best = -1, at = -1;
      for (int i = 1; i <= n; i++) {
        if (!can[i]) continue;
        if (w[i] <= now) {
          if (l[i] > best) {
            best = l[i];
            at = i;
          }
        }
      }
      if (best <= now) {
        puts("impossible");
        return 0;
      }
      now = best;
      can[at] = 0;
      ans[it.second].push_back(at);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      printf("%d%c", ans[i][j], " \n"[j + 1 == ans[i].size()]);
    }
  }

  return 0;
}
