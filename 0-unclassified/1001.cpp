#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char str[] = "RLDU"; 

const int inf = 1e9;

char s[N][N];
int pe[N][N], pc[N][N];

// i, j, checkpoint, galon sudah
int b[N][N][8][8], d[N][N][8][8];
int n, m, k, g;
tuple<int, int, int, int> past[N][N][8][8];

bool bisa(int i, int j) {
  return (0 <= i && i < n && 0 <= j && j < m && s[i][j] != '#');
}

void init() {
  int cntc = 0, cnte = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      pe[i][j] = -1;
      pc[i][j] = -1;
      for(int c = 0; c < (1 << k); c++) {
        for(int e = 0; e < (1 << g); e++) {
          past[i][j][c][e] = make_tuple(-1, -1, -1, -1);
          b[i][j][c][e] = -1;
          d[i][j][c][e] = -inf;
        }
      }
      if(s[i][j] == 'C') {
        pc[i][j] = cntc++;
      }
      if(s[i][j] == 'E') {
        pe[i][j] = cnte++;
      }
    }
  }
}

void backtrack(int i, int j, int mc, int me) {
  //assert(d[i][j][mc][me] > 0);
  if(b[i][j][mc][me] == -1) return;
  int ti, tj, tc, te;
  tie(ti, tj, tc, te) = past[i][j][mc][me];
  backtrack(ti, tj, tc, te);
  printf("%c", str[b[i][j][mc][me]]);
}

int main() {
  int t = 1001;
  int time = 13000;
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d %d %d", &m, &n, &k);
    
    g = 0;
    int gx, gy, sx, sy;
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      for(int j = 0; j < m; j++) {
        if(s[i][j] == 'E') {
          g++;
        }
        if(s[i][j] == 'S') {
          sx = i; sy = j;
        }
        if(s[i][j] == 'G') {
          gx = i; gy = j;
        }
      }
    }
    //cerr << n << ' ' << m << ' ' << k << ' ' << g << endl;
    init();
    // cost, i, j, checkpoint, galon sudah
    priority_queue<tuple<int, int, int, int, int>> pq;
    d[sx][sy][0][0] = time;
    pq.emplace(time, sx, sy, 0, 0);
    while(!pq.empty()) {
      int dist, i, j, mc, me;
      tie(dist, i, j, mc, me) = pq.top();
      pq.pop();
      if(dist != d[i][j][mc][me]) {
        continue;
      }
      for(int dir = 0; dir < 4; dir++) {
        int tx = i + dx[dir];
        int ty = j + dy[dir];
        if(!bisa(tx, ty)) continue;
        int mcc = mc;
        if(s[tx][ty] == 'C') {
          mcc |= (1 << pc[tx][ty]);
        }
        int mee = me;
        int to = dist - 1;
        if(s[tx][ty] == 'E') {
          mee |= (1 << pe[tx][ty]);
          if((me & (1 << pe[tx][ty])) == 0) {
            to += 20;
          }
        }
        if(d[tx][ty][mcc][mee] < to) {
          d[tx][ty][mcc][mee] = to;
          pq.emplace(to, tx, ty, mcc, mee);
          b[tx][ty][mcc][mee] = dir;
          past[tx][ty][mcc][mee] = make_tuple(i, j, mc, me);
        }
      }
    }
    int best = -inf, mbest = -1;
    for(int i = 0; i < (1 << g); i++) {
      if(d[gx][gy][(1 << k) - 1][i] > best) {
        best = d[gx][gy][(1 << k) - 1][i];
        mbest = i;
      }
    }
    if(g > 0) {
      if(mbest != (1 << g) - 1) {
        cerr << "goblok ga diambil semua" << endl;
        //return 0;
      }
      if(mbest > 0) {
        cerr << "good! at least ngambil" << endl;
        //return 0;
      }
    }
    /*
    if(best <= 0) {
      printf("start %d\n", time);
      for(int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
      }
    }
    */
    time = best;
    //assert(time > 0);
    
    backtrack(gx, gy, (1 << k) - 1, mbest);
    printf("\n");
    
    cerr << tt << " done! now time only " << time << endl;
  }
  
  return 0;
}
