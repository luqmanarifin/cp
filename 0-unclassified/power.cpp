#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int MAX = 400000;

int dist[MAX];
int n, m;
char s[30][30];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int id(int i, int j, int k, int l) {
  return (i * m + j) * n * m + (k * m + l);
}

tuple<int, int, int, int> cuk(int hash) {
  int a = hash / (n * m);
  int b = hash % (n * m);
  int i = a / m;
  int j = a % m;
  int k = b / m;
  int l = b % m;
  return make_tuple(i, j, k, l);
}

int main() {
  scanf("%d %d", &n, &m);
  int ax, ay, gx, gy, px, py;
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'A') {
        ax = i, ay = j;
      } else if(s[i][j] == 'G') {
        gx = i, gy = j;
      } else if(s[i][j] == 'P') {
        px = i, py = j;
      }
    }
  }
  for(int i = 0; i < MAX; i++) {
    dist[i] = inf;
  }
  priority_queue<pair<int, int>> pq;
  dist[id(ax, ay, gx, gy)] = 0;
  pq.emplace(0, id(ax, ay, gx, gy));
  
  while(!pq.empty()) {
    int cost, now;
    tie(cost, now) = pq.top();
    cost = -cost;
    pq.pop();
    tie(ax, ay, gx, gy) = cuk(now);
    if(dist[now] != cost || (ax == gx && ay == gy)) {
      continue;
    }
    //printf("%d %d %d %d\n", ax, ay, gx, gy);
    if(ax == px && ay == py) {
      printf("%d\n", cost);
      return 0;
    }
    for(int d = 0; d < 4; d++) {
      int wx = ax + dx[d];
      int wy = ay + dy[d];
      if(wx < 0 || wx >= n || wy < 0 || wy >= m || s[wx][wy] == 'X') {
        continue;
      }
      bool sip = 0;
      for(int u = 0; u < 4; u++) {
        int tx = gx + dx[u];
        int ty = gy + dy[u];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m || s[tx][ty] == 'X') {
          continue;
        }
        if(u == 0 && wy < gy) {
          int at = id(wx, wy, tx, ty);
          if(cost + 1 < dist[at]) {
            dist[at] = cost + 1;
            pq.emplace(-dist[at], at);
          }
          sip = 1;
          break;
        } else if(u == 1 && gy < wy) {
          int at = id(wx, wy, tx, ty);
          if(cost + 1 < dist[at]) {
            dist[at] = cost + 1;
            pq.emplace(-dist[at], at);
          }
          sip = 1;
          break;
        } else if(u == 2 && wx < gx) {
          int at = id(wx, wy, tx, ty);
          if(cost + 1 < dist[at]) {
            dist[at] = cost + 1;
            pq.emplace(-dist[at], at);
          }
          sip = 1;
          break;
        } else if(u == 3 && gx < wx) {
          int at = id(wx, wy, tx, ty);
          if(cost + 1 < dist[at]) {
            dist[at] = cost + 1;
            pq.emplace(-dist[at], at);
          }
          sip = 1;
          break;
        }
      }
      if(!sip) {
        int at = id(wx, wy, gx, gy);
        if(cost + 1 < dist[at]) {
          dist[at] = cost + 1;
          pq.emplace(-dist[at], at);
        }
      }
    }
  }
  puts("-1");
  return 0;
}
