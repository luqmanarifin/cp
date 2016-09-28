#include <bits/stdc++.h>

using namespace std;

#define byte unsigned short int

const byte inf = 65535;
const int N = 102;

byte dp[N][N][N][N];
byte val[N][N][N][N];
int n, m;
char s[N][N];
vector<int> wi[N][N], wj[N][N];
int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
int da[N][N], db[N][N];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m && s[i][j] != 'x';
}

void bfs(int si, int sj, int d[N][N]) {
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = inf;
    }
  }
  d[si][sj] = 0;
  q.emplace(si, sj);
  while (!q.empty()) {
    tie(si, sj) = q.front();
    q.pop();
    int cur = d[si][sj];
    for (int k = 0; k < 4; k++) {
      int ti = si + di[k];
      int tj = sj + dj[k];
      if (!valid(ti, tj)) continue;
      if (cur + 1 < d[ti][tj]) {
        d[ti][tj] = cur + 1;
        q.emplace(ti, tj);
      }
    }
  }
}

long long encode(int ai, int aj, int bi, int bj) {
  return 1LL * ai * N * N * N + 1LL * aj * N * N + bi * N + bj;
}

tuple<int, int, int, int> decode(long long v) {
  int ai, aj, bi, bj;
  bj = v % N; v /= N;
  bi = v % N; v /= N;
  aj = v % N; v /= N;
  ai = v % N; v /= N;
  return make_tuple(ai, aj, bi, bj);
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
    bfs(ai, aj, da);
    bfs(bi, bj, db);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < m; l++) {
            val[i][j][k][l] = db[i][j] + da[k][l];
          }
        }
      }
    }
    
    dp[ai][aj][bi][bj] = 0;
    priority_queue<pair<int, long long>> q;
    q.emplace(val[ai][aj][bi][bj], encode(ai, aj, bi, bj));
    while (!q.empty()) {
      int ani, anj, bni, bnj;
      long long v = q.top().second;
      q.pop();
      tie(ani, anj, bni, bnj) = decode(v);
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
            q.emplace(val[tai][taj][tbi][tbj], encode(tai, taj, tbi, tbj));
          }
        }
      }
    }
  }

  return 0;
}
