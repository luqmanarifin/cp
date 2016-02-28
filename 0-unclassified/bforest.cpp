#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int n, m;
char s[1005][1005];
int dist[1005][1005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  scanf("%d %d", &n, &m);
  int si, sj, ti, tj;
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'E') {
        si = i, sj = j;
      } else if(s[i][j] == 'S') {
        ti = i, tj = j;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dist[i][j] = inf;
    }
  }
  dist[si][sj] = 0;
  queue<pair<int, int>> q;
  q.emplace(si, sj);
  while(!q.empty()) {
    int ni, nj;
    tie(ni, nj) = q.front();
    q.pop();
    for(int k = 0; k < 4; k++) {
      int ii = ni + dx[k];
      int jj = nj + dy[k];
      if(valid(ii, jj) && s[ii][jj] != 'T') {
        if(dist[ni][nj] + 1 < dist[ii][jj]) {
          dist[ii][jj] = dist[ni][nj] + 1;
          q.emplace(ii, jj);
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if('0' <= s[i][j] && s[i][j] <= '9') {
        if(dist[i][j] <= dist[ti][tj]) {
          //printf("%d %d %d\n", i, j, dist[i][j]);
          ans += s[i][j] - '0';
        }
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}
