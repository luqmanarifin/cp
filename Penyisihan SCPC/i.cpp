#include <bits/stdc++.h>

using namespace std;

#define byte unsigned char

const byte inf = 255;
const int N = 102;

byte dp[N][N][N][N];
int n, m;
char s[N][N];
vector<int> wi[N][N], wj[N][N];
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != 'x';
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        wi[i][j].clear();
        wj[i][j].clear();
        for (int k = 0; k < N; k++) {
          for (int l = 0; l < N; l++) {
            dp[i][j][k][l] = inf;
          }
        }
      }
    }
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int ai, aj, bi, bj;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'A') {
          ai = i;
          aj = j;
        }
        if (s[i][j] == 'B') {
          bi = i;
          bj = j;
        }
        for (int k = 0; k < 4; k++) {
          int ti = i + di[k];
          int tj = j + dj[k];
          if (!valid(ti, tj)) continue;
          wi[i][j].push_back(ti);
          wj[i][j].push_back(tj);
        }
      }
    }
    dp[ai][aj][bi][bj] = 0;
    queue<tuple<int, int, int, int>> q;
    q.emplace(ai, aj, bi, bj);
    while (!q.empty()) {
      int ani, anj, bni, bnj;
      tie(ani, anj, bni, bnj) = q.front();
      q.pop();
      byte& cur = dp[ani][anj][bni][bnj];
      if (ani == bi && anj == bj && bni == ai && bnj == aj) {
        printf("%d\n", cur);
        break;
      }
      for (int k = 0; k < wi[ani][anj].size(); k++) {
        int tai = wi[ani][anj][k];
        int taj = wj[ani][anj][k];
        for (int l = 0; l < wi[bni][bnj].size(); l++) {
          int tbi = wi[bni][bnj][l];
          int tbj = wj[bni][bnj][l];
          if (tai == tbi && taj == tbj) continue;
          byte& ncur = dp[tai][taj][tbi][tbj];
          if (cur + 1 < ncur) {
            ncur = cur + 1;
            q.emplace(tai, taj, tbi, tbj);
          }
        }
      }
    }
  }

  return 0;
}
