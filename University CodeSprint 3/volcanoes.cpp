
#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

int a[N][N], done[N][N];
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    memset(done, 0, sizeof(done));

    int x, y, w;
    scanf("%d %d %d", &x, &y, &w);
    queue<tuple<int, int, int>> q;
    q.emplace(w, x, y);
    done[x][y] = 1;
    while (!q.empty()) {
      tie(w, x, y) = q.front();
      q.pop();
      a[x][y] += w;
      for (int i = 0; i < 8; i++) {
        int ti = x + dx[i];
        int tj = y + dy[i];
        if (valid(ti, tj) && !done[ti][tj] && w - 1) {
          done[ti][tj] = 1;
          q.emplace(w - 1, ti, tj);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      //printf("%d ", a[i][j]);
      ans = max(ans, a[i][j]);
    }
    //printf("\n");
  }
  cout << ans << endl;
  return 0;
}
