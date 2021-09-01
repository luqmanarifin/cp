#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int inf = 1e9;

char s[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    int best = inf;
    set<vector<pair<int, int>>> ways;
    for (int i = 0; i < n; i++) {
      bool can = 1;
      int count = 0;
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'O') {
          can = 0;
          break;
        }
        if (s[i][j] == 'X') count++;
      }
      if (!can) continue;
      int cur = n - count;
      if (cur > best) continue;
      if (cur < best) {
        best = cur;
        ways.clear();
      }
      vector<pair<int, int>> way;
      for (int j = 0; j < n; j++) {
        if (s[i][j] != 'X') {
          way.emplace_back(i, j);
        }
      }
      ways.insert(way);
    }
    for (int j = 0; j < n; j++) {
      bool can = 1;
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (s[i][j] == 'O') {
          can = 0;
          break;
        }
        if (s[i][j] == 'X') count++;
      }
      if (!can) continue;
      int cur = n - count;
      if (cur > best) continue;
      if (cur < best) {
        best = cur;
        ways.clear();
      }
      vector<pair<int, int>> way;
      for (int i = 0; i < n; i++) {
        if (s[i][j] != 'X') {
          way.emplace_back(i, j);
        }
      }
      ways.insert(way);
    }
    printf("Case #%d: ", tt);
    if (best == inf) {
      printf("Impossible\n");
    } else {
      printf("%d %d\n", best, ways.size());
    }
  }

  return 0;
}
