#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N][N];
queue<pair<int, int>> q;
int dist[N][N];
int n, m;

int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dist[i][j] = 1e9;
    }
  }
  dist[0][0] = 0;
  q.emplace(0, 0);
  while(!q.empty()) {
    int ni = q.front().first;
    int nj = q.front().second;
    int now = s[ni][nj] - '0';
    q.pop();
    if(ni == n - 1 && nj == m - 1) {
      printf("%d\n", dist[ni][nj]);
      return 0;
    }
    for(int i = 0; i < 4; i++) {
      int ti = ni + now * da[i];
      int tj = nj + now * db[i];
      if(valid(ti, tj) && dist[ni][nj] + 1 < dist[ti][tj]) {
        dist[ti][tj] = dist[ni][nj] + 1;
        q.emplace(ti, tj);
      }
    }
  }
  puts("IMPOSSIBLE");
  return 0;
}