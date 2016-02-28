#include <bits/stdc++.h>

using namespace std;

const int of = 100;
const int inf = 1e9;

int dist[of * 3][of * 3];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

// return -1 if cant, jaraknya if can
int to(int dx, int dy) {
  if((dx + dy) % 3) return -1;
  int d = (dx + dy) / 3;
  if(min(dx, dy) < d) return -1;
  return d;
}

bool valid(int x, int y) {
  return 0 <= x && x <= of * 2 && 0 <= y && y <= of * 2;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < of * 3; i++) {
      for(int j = 0; j < of * 3; j++) {
        dist[i][j] = inf;
      }
    }
    int ax, ay, ix, iy, h;
    scanf("%d %d %d %d %d", &ax, &ay, &ix, &iy, &h);
    priority_queue<tuple<int, int, int>> pq;
    for(int i = -of; i <= of; i++) {
      for(int j = -of; j <= of; j++) {
        int ret = to(abs(ix - i - ax), abs(iy - j - ay));
        if(ret != -1) {
          dist[i + of][j + of] = ret;
          pq.emplace(-ret, i + of, j + of);
        }
      }
    }
    bool found = 0;
    while(!pq.empty()) {
      int c, x, y;
      tie(c, x, y) = pq.top();
      c = -c;
      pq.pop();
      if(c != dist[x][y]) continue;
      if(c > h) break;
      if(x == of && y == of) {
        printf("%d\n", c);
        found = 1;
        break;
      }
      for(int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(valid(xx, yy)) {
          if(c + 1 < dist[xx][yy]) {
            dist[xx][yy] = c + 1;
            pq.emplace(-dist[xx][yy], xx, yy);
          }
        }
      }
    }
    if(!found) puts("-1");
  }
  
  return 0;
}
