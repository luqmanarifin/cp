#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 10005;

int n, m, score[N], diff[M];
char s[N][M];

int main() {
  n = 100; m = 10000;

  int t, v;
  scanf("%d %d", &t, &v);
  for (int tt = 1; tt <= t; tt++) {
    memset(score, 0, sizeof(score));
    memset(diff, 0, sizeof(diff));

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
    reverse(que.begin(), que.end());

    vector<int> q;
    for (int j = 0; j < m; j++) {
      q.push_back(que[j].second);
    }
    double disc = -1; int ans = -1;
    for (int i = 0; i < n; i++) {
      int now = 0, med = -1;
      for (int j = 0; j < q.size(); j++) {
        now += s[i][q[j]] - '0';
        if (now >= score[i] / 2) {
          med = j;
          break;
        }
      }
      long long sum = 0;
      for (int j = 0; j < q.size(); j++) {
        if (s[i][q[j]] == '1') {
          sum += 1LL * (med - j) * (med - j);
        }
      }
      double cur_disc = (double) sum / score[i];
      if (cur_disc > disc) {
        disc = cur_disc;
        ans = i;
      }
    }
    
    printf("Case #%d: %d\n", tt, ans + 1);
  }

  return 0;
}
