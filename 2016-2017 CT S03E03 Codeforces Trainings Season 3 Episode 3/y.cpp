#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector<int> ada[N];
int ans[N];

int main() {
  int n, t, m;
  scanf("%d %d %d", &n, &t, &m);
  for (int i = 0; i < m; i++) {
    int at, v;
    scanf("%d %d", &at, &v);
    ada[at].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (t == i) continue;
    sort(ada[i].begin(), ada[i].end());
    bool done[ada[i].size()];
    memset(done, 0, sizeof(done));
    int p = 0;
    for (int j = (int) ada[i].size() - 1; j >= 0; j--) {
      if (done[j]) break;
      if (ada[i][j] == 0) {
        puts("IMPOSSIBLE");
        return 0;
      }
      int k = ada[i][j] - 1;
      done[j] = 1;
      while (k-- && p < ada[i].size()) {
        done[p++] = 1;
      }
      ans[i]++;
    }
    for (int j = 0; j < ada[i].size(); j++) {
      if (!done[j]) {
        puts("IMPOSSIBLE");
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}