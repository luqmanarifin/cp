#include <bits/stdc++.h>

using namespace std;

const int border = 100010;

map<pair<int, int>, bool> done;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int ax, ay, ix, iy, h;

int dist(int x, int y) {
  return abs(x - ix) + abs(y - iy);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    done.clear();
    
    scanf("%d %d %d %d %d", &ax, &ay, &ix, &iy, &h);
    if(abs(ax - ix) > 2 * h || abs(ay - iy) > 2 * h) {
      puts("-1");
      continue;
    }
    
    queue<tuple<int, int, int>> q;
    q.emplace(ax, ay, 0);
    
    while(!q.empty()) {
      int x, y, cost;
      tie(x, y, cost) = q.front();
      q.pop();
      if(cost > h) {
        puts("-1");
        break;
      }
      if(x == ix && y == iy) {
        printf("%d\n", cost);
        break;
      }
      for(int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(dist(xx, yy) >= dist(x, y) && dist(x, y) > 5) {
          continue;
        }
        if(!done[{xx, yy}]) {
          done[{xx, yy}] = 1;
          q.emplace(xx, yy, cost + 1);
        }
      }
    }
  }
  
  return 0;
}
