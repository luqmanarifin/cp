#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[505][505];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int sx, sy, fx, fy;
  scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
  sx--; sy--; fx--; fy--;
  
  queue<pair<int, int>> q;
  q.emplace(sx, sy);
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if(valid(tx, ty)) {
        if((tx == fx && ty == fy && s[tx][ty] == 'X')) {
          puts("YES");
          return 0;
        }
        if(s[tx][ty] == '.') {
          s[tx][ty] = 'X';
          q.emplace(tx, ty);
        }
      }
    }
  }
  puts("NO");
  return 0;
}
