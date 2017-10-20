#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int inf = 1e9;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int px[8] = {-1, -1, 0, 1, 2, 2, 1, 0};
int py[8] = {0, 1, 2, 2, 1, 0, -1, -1};

char s[N][N];
bool awas[N][N];
int n, m;

int done[N][N];
int dist[4][N][N];
vector<pair<int, int>> start;

int bfs[8][N][N];
// cost - i - j - arah
priority_queue<tuple<int, int, int, int>> pq;
int change[N][N][4][4];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void expand(int u, int v, bool is_start = 0) {
  if (done[u][v]) return;
  done[u][v] = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      awas[u+i][v+j] = 1;
    }
  }
  
  for (int k = 0; k < 8; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        bfs[k][i][j] = inf;
      }
    }
  }
  for (int k = 0; k < 8; k++) {
    if (!valid(u+px[k], v+py[k]) || awas[u+px[k]][v+py[k]]) continue;
    queue<pair<int, int>> q;
    bfs[k][u + px[k]][v + py[k]] = 0;
    q.emplace(u + px[k], v + py[k]);
    while (!q.empty()) {
      int ni, nj;
      tie(ni, nj) = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int ti = ni + dx[i];
        int tj = nj + dy[i];
        if (!valid(ti, tj) || awas[ti][tj]) continue;
        if (bfs[k][ti][tj] > bfs[k][ni][nj] + 1) {
          bfs[k][ti][tj] = bfs[k][ni][nj] + 1;
          q.emplace(ti, tj);
        }
      }
    }
  }
  if (is_start) {
    for (int i = 0; i < 4; i++) {
      int cur = min(bfs[i*2][start[0].first][start[0].second] + bfs[i*2+1][start[1].first][start[1].second], bfs[i*2+1][start[0].first][start[0].second] + bfs[i*2][start[1].first][start[1].second]);
      //printf("lol %d: %d\n", i, cur);
      if (dist[i][u][v] > cur) {
        //puts("masuk");
        dist[i][u][v] = cur;
        pq.emplace(-dist[i][u][v], u, v, i);
      }
    }
  }
  //printf("expand %d %d\n", u, v);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int cur = min(bfs[i*2][u+px[j*2]][v+py[j*2]] + bfs[i*2+1][u+px[j*2+1]][v+py[j*2+1]], bfs[i*2][u+px[j*2+1]][v+py[j*2+1]] + bfs[i*2+1][u+px[j*2]][v+py[j*2]]);
      change[u][v][i][j] = cur;
      //printf("%d %d: %d\n", i, j, cur);
    }
  }
  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      awas[u+i][v+j] = 0;
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  while (n && m) {
    memset(done, 0, sizeof(done));
    start.clear();
    memset(awas, 0, sizeof(awas));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < 4; k++) {
          for (int l = 0; l < 4; l++) {
            change[i][j][k][l] = inf;
          }
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          dist[i][j][k] = inf;
        }
      }
    }
    
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int kx = -1, ky = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '*') {
          awas[i][j] = 1;
        } else if (s[i][j] == '.') {
          start.emplace_back(i, j);
        } else if (s[i][j] == 'X' && kx == -1) {
          kx = i;
          ky = j;
        }
      }
    }
    bool found;
    if (kx == 0 && ky == 0) {
      puts("0");
      goto FUCK;
    }
    assert(start.size() == 2);
    while (!pq.empty()) pq.pop();
    expand(kx, ky, 1);
    found = 0;
    while (!pq.empty()) {
      int cost, i, j, d;
      tie(cost, i, j, d) = pq.top();
      pq.pop();
      cost = -cost;
      if (i == 0 && j == 0) {
        cout << cost << endl;
        found = 1;
        break;
      }
      //printf("%d %d %d %d\n", cost, i, j, d);
      expand(i, j);
      for (int k = 0; k < 4; k++) {
        int ti = i + dx[k];
        int tj = j + dy[k];
        int cur = cost + change[i][j][d][k];
        if (dist[k][i][j] > cur) {
          dist[k][i][j] = cur;
          pq.emplace(-dist[k][i][j], i, j, k);
        }
      }
      int ti = i + dx[d];
      int tj = j + dy[d];
      if (valid(ti, tj)) {
        int cur = cost + 1;
        if (dist[d^2][ti][tj] > cur) {
          dist[d^2][ti][tj] = cur;
          pq.emplace(-dist[d^2][ti][tj], ti, tj, d^2);
        }
      }
    }
    if (!found) puts("-1");
    
    FUCK:;
    scanf("%d %d", &n, &m);
  }

  return 0;
}
