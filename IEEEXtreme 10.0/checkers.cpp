#include <bits/stdc++.h>

using namespace std;

int di4[] = {0, 0, -1, 1};
int dj4[] = {1, -1, 0, 0};

int di8[] = {0, 0, -1};
int dj8[] = {1, -1, 0};

// mask - pos a - pos b - arah - pieces (0 cupu, 1 imba)
long long dp[1<<16][8][8][5][2];
bool done[1<<16][8][8][5][2];

char s[10][10];
bool petak[10][10];
int ada[10][10];
int a[20], b[20], n = 8;

vector<int> all[20];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 20; i++) all[i].clear();
    memset(dp, 0, sizeof(dp));
    memset(done, 0, sizeof(done));
    memset(petak, 0, sizeof(petak));
    memset(ada, -1, sizeof(ada));
    
    int m = 0;
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    queue<tuple<int, int, int, int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == 'x') {
          a[m] = i;
          b[m] = j;
          petak[i][j] = 1;
          m++;
        }
        if (s[i][j] == 'o') {
          dp[0][i][j][4][i == 0] = 1;
          done[0][i][j][4][i == 0] = 1;
          q.emplace(0, i, j, 4, i == 0);
        }
      }
    }
    for (int i = 0; i < (1 << m); i++) {
      all[__builtin_popcount(i)].push_back(i);
    }
    int last = -1;
    while (!q.empty()) {
      int mask, pi, pj, d, st;
      tie(mask, pi, pj, d, st) = q.front();
      q.pop();
      
      int cnt_mask = __builtin_popcount(mask);
      if (last != cnt_mask) {
        for (auto it : all[cnt_mask]) {
          for (int i = 0; i < m; i++) {
            if ((it & (1 << i)) == 0) {
              ada[a[i]][b[i]] = i;
            }
          }
          for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
              if (ada[i][j] == -1) {
                dp[it][i][j][0][1] += dp[it][i][j-1][0][1];
              }
            }
          }
          for (int i = 0; i < n; i++) {
            for (int j = n - 2; j >= 0; j--) {
              if (ada[i][j] == -1) {
                dp[it][i][j][1][1] += dp[it][i][j+1][1][1];
              }
            }
          }
          for (int j = 0; j < n; j++) {
            for (int i = n - 2; i >= 0; i--) {
              if (ada[i][j] == -1) {
                dp[it][i][j][2][1] += dp[it][i+1][j][2][1];
              }
            }
          }
          for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
              if (ada[i][j] == -1) {
                dp[it][i][j][3][1] += dp[it][i-1][j][3][1];
              }
            }
          }
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
              for (int k = 0; k < 4; k++) {
                if (!done[it][i][j][k][1] && dp[it][i][j][k][1]) {
                  done[it][i][j][k][1] = 1;
                  q.emplace(it, i, j, k, 1);
                }
              }
            }
          }
          for (int i = 0; i < m; i++) {
            if ((it & (1 << i)) == 0) {
              ada[a[i]][b[i]] = -1;
            }
          }
        }
        last = cnt_mask;
      }
      long long add = dp[mask][pi][pj][d][st];
      //if (__builtin_popcount(mask) == 6) printf("%d %d %d %d %d %d\n", mask, pi, pj, d, st, add);
      
      for (int i = 0; i < m; i++) {
        if ((mask & (1 << i)) == 0) {
          ada[a[i]][b[i]] = i;
        }
      }
      if (st == 0) {
        for (int i = 0; i < 3; i++) {
          int ti = pi + di8[i];
          int tj = pj + dj8[i];
          if (valid(ti, tj) && ada[ti][tj] != -1) {
            int tti = ti + di8[i];
            int ttj = tj + dj8[i];
            if (valid(tti, ttj) && ada[tti][ttj] == -1) {
              int tmask = (mask | (1 << ada[ti][tj]));
              int td = i;
              int tst = (tti == 0);
              dp[tmask][tti][ttj][td][tst] += add;
              if (!done[tmask][tti][ttj][td][tst]) {
                done[tmask][tti][ttj][td][tst] = 1;
                q.emplace(tmask, tti, ttj, td, tst);
              }
            }
          }
        }
      } else {
        for (int i = 0; i < 4; i++) {
          if (i == (d ^ 1)) continue;
          int ti = pi + di4[i];
          int tj = pj + dj4[i];
          while (valid(ti, tj)) {
            if (ada[ti][tj] != -1) {
              //printf("eks %d %d\n", ti, tj);
              for (int j = 1; ; j++) {
                int tti = ti + j * di4[i];
                int ttj = tj + j * dj4[i];
                if (!valid(tti, ttj)) break;
                if (ada[tti][ttj] != -1) break;
                //printf("sparse %d %d\n", tti, ttj);
                int tmask = (mask | (1 << ada[ti][tj]));
                int td = i;
                int tst = 1;
                dp[tmask][tti][ttj][td][tst] += add;
                if (!done[tmask][tti][ttj][td][tst]) {
                  done[tmask][tti][ttj][td][tst] = 1;
                  q.emplace(tmask, tti, ttj, td, tst);
                }
                break;
              }
              break;
            }
            ti += di4[i];
            tj += dj4[i];
          }
        }
      }
      for (int i = 0; i < m; i++) {
        if ((mask & (1 << i)) == 0) {
          ada[a[i]][b[i]] = -1;
        }
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 5; k++) {
          for (int l = 0; l < 2; l++) {
            ans += dp[(1 << m) - 1][i][j][k][l];
          }
        }
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}