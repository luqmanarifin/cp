#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

char s[N][N];
int n, m;
int dp[N][N][4];

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

int main() {
  int K;
  scanf("%d %d %d", &n, &m, &K);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  int s1, s2, f1, f2;
  scanf("%d %d %d %d", &s1, &s2, &f1, &f2);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 4; k++) dp[i][j][k] = inf;
    }
  }
  queue<tuple<int, int, int>> q;
  for (int k = 0; k < 4; k++) {
    dp[s1][s2][k] = 0;
    q.emplace(s1, s2, k);
  }
  while (!q.empty()) {
    int ni, nj, nk;
    tie(ni, nj, nk) = q.front();
    //printf("%d %d %d: %d\n", ni, nj, nk, dp[ni][nj][nk]);
    q.pop();
    if (ni == f1 && nj == f2) {
      cout << dp[ni][nj][nk] << endl;
      return 0;
    }
    for (int k = 0; k < 4; k++) {
      for (int i = 1; i <= K; i++) {
        int ti = ni + i * dx[k];
        int tj = nj + i * dy[k];
        if (!valid(ti, tj) || s[ti][tj] == '#') break;
        if (dp[ti][tj][k] > dp[ni][nj][nk] + 1) {
          dp[ti][tj][k] = dp[ni][nj][nk] + 1;
          q.emplace(ti, tj, k);
        } else {
          break;
        }
      }
    }
  }
  puts("-1");
  //cout << find(1, 1, 1, 4) << endl;
  return 0;
}
