#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 10005;

int n, m, score[N], diff[M], solve_diff[N];
long long disc[N];
char s[N][M];
bool is_hard[M], is_good[N];

int main() {
  n = 100; m = 10000;

  int t, v;
  scanf("%d %d", &t, &v);
  for (int tt = 1; tt <= t; tt++) {
    memset(score, 0, sizeof(score));
    memset(diff, 0, sizeof(diff));
    memset(disc, 0, sizeof(disc));
    memset(is_hard, 0, sizeof(is_hard));
    memset(is_good, 0, sizeof(is_good));
    memset(solve_diff, 0, sizeof(solve_diff));

    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1') {
          score[i]++;
          diff[j]++;
        }
      }
    }
    vector<pair<int, int>> que; // score, index
    for (int j = 0; j < m; j++) {
      que.emplace_back(diff[j], j);
    }
    sort(que.begin(), que.end());
    for (int j = 0; j < 500; j++) is_hard[que[j].second] = 1;

    vector<pair<int, int>> players;
    for (int i = 0; i < n; i++) players.emplace_back(score[i], i);
    sort(players.begin(), players.end());
    reverse(players.begin(), players.end());

    for (int i = 0; i < 20; i++) {
      is_good[players[i].second] = 1;
      // printf("%d: %d\n", players[i].second + 1, players[i].first);
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (is_hard[j] && s[i][j] == '1') {
          solve_diff[i]++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      // if (!is_good[i]) {
      //   printf("%d: %d\n", i + 1, solve_diff[i]);
      // }
      if (!is_good[i] && solve_diff[i] > 200) {
        ans = i;
      }
    }
    if (ans == -1) {
      int mx = -1;
      for (int i = 0; i < n; i++) {
        if (solve_diff[i] > mx) {
          mx = solve_diff[i];
          ans = i;
        }
      }
    }
    
    printf("Case #%d: %d\n", tt, ans + 1);
  }

  return 0;
}
