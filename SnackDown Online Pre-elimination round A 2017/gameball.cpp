#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 22;
 
char a[N][N], b[N][N];
vector< pair< pair<int, int >, pair< int, int > > > moves; 
pair<int, int> pre[N][N];
 
int n, m;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
void reset() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      pre[i][j] = {-1, -1};
}
pair<int, int> bfs(int x, int y, char c) {
  queue< pair< int, int > > que;
  que.push(make_pair(x, y));
  pre[x][y] = make_pair(x, y);
  while (!que.empty()) {
    auto cur = que.front(); que.pop();
    x = cur.first, y = cur.second;
    if (a[x][y] == c) return make_pair(x, y);
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (pre[xx][yy] != make_pair(-1, -1)) continue;
      pre[xx][yy] = {x, y};
      que.push(make_pair(xx, yy));
    }
  }
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    moves.clear();
    scanf("%d %d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", a[i]);
      for (int j = 0; j < m; j++)
        cnt += a[i][j] == '*', b[i][j] = a[i][j];
    }
    if (cnt == 1) {
      puts("0");
      continue;
    }
    if (max(n, m) < 3) {
      puts("-1");
      continue;
    }
    if (n >= 3) {
      while (cnt > 1) {
        reset();
        pair< int, int > cur = bfs(0, 0, '*');
        while (cur != make_pair(0, 0)) {
          pair< int, int > nex = pre[cur.first][cur.second];
          moves.emplace_back(cur, nex);
          swap(a[cur.first][cur.second], a[nex.first][nex.second]);
          cur = nex;
        }
        reset();
        pre[0][0] = {0, 0};
        cur = bfs(1, 0, '*');
        while (cur != make_pair(1, 0)) {
          pair< int, int > nex = pre[cur.first][cur.second];
          moves.emplace_back(cur, nex);
          swap(a[cur.first][cur.second], a[nex.first][nex.second]);
          cur = nex;
        }
        reset();
        cur = bfs(2, 0, '.');
        while (cur != make_pair(2, 0)) {
          pair< int, int > nex = pre[cur.first][cur.second];
          moves.emplace_back(nex, cur);
          swap(a[cur.first][cur.second], a[nex.first][nex.second]);
          cur = nex;
        }
        moves.emplace_back(make_pair(0, 0), make_pair(2, 0));
        a[0][0] = '.';
        a[1][0] = '.';
        a[2][0] = '*';
        cnt--;
      }
    }
    else {
      while (cnt > 1) {
        reset();
        pair< int, int > cur = bfs(0, 0, '*');
        while (cur != make_pair(0, 0)) {
          pair< int, int > nex = pre[cur.first][cur.second];
          moves.emplace_back(cur, nex);
          swap(a[cur.first][cur.second], a[nex.first][nex.second]);
          cur = nex;
        }
        reset();
        pre[0][0] = {0, 0};
        cur = bfs(0, 1, '*');
        while (cur != make_pair(0, 1)) {
          pair< int, int > nex = pre[cur.first][cur.second];
          moves.emplace_back(cur, nex);
          swap(a[cur.first][cur.second], a[nex.first][nex.second]);
          cur = nex;
        }
        reset();
        cur = bfs(0, 2, '.');
        while (cur != make_pair(0, 2)) {
          pair< int, int > nex = pre[cur.first][cur.second];
          moves.emplace_back(nex, cur);
          swap(a[cur.first][cur.second], a[nex.first][nex.second]);
          cur = nex;
        }
        moves.emplace_back(make_pair(0, 0), make_pair(0, 2));
        a[0][0] = '.';
        a[0][1] = '.';
        a[0][2] = '*';
        cnt--;
      }
    }
    printf("%d\n", moves.size());
    for (auto it : moves) {
      pair< int, int > fr = it.first, to = it.second;
      printf("%d %d %d %d\n", fr.first+1, fr.second+1, to.first+1, to.second+1);
    }
    assert(moves.size() <= 5000);
  }
  return 0;
} 