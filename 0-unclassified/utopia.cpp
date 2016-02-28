#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int inf = 1e9;

// cost - lt - x - y
priority_queue<tuple<int, int, int, int>> pq;

char s[N][N][N];
int dist[N][N][N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int l, n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        dist[i][j][k] = inf;
      }
    }    
  }

  scanf("%d %d %d", &l, &n, &m);
  int si, sj, sk;
  for(int i = 0; i < l - 1; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        scanf(" %c", &s[i][j][k]);
        if(s[i][j][k] == 'T') {
          si = i, sj = j, sk = k;
          dist[i][j][k] = 0;
        }
      }
    }
  }
  pq.emplace(0, si, sj, sk);
  while(!pq.empty()) {
    int c, i, j, k;
    tie(c, i, j, k) = pq.top();
    c = -c;
    pq.pop();
    if(c != dist[i][j][k]) {
      continue;
    }
    //printf("%d %d %d %d\n", c, i, j, k);
    if(i == l - 1) {
      printf("%d\n", c);
      return 0;
    }
    if(s[i][j][k] == 'O' && c < dist[i + 1][j][k]) {
      dist[i + 1][j][k] = c;
      pq.emplace(-c, i + 1, j, k);
    }
    for(int t = 0; t < 4; t++) {
      int xx = j + dx[t];
      int yy = k + dy[t];
      if(valid(xx, yy)) {
        if(c + 1 < dist[i][xx][yy] && s[i][xx][yy] != 'X') {
          dist[i][xx][yy] = c + 1;
          pq.emplace(-dist[i][xx][yy], i, xx, yy);
        }
      }
    }
  }
  puts("-1");
  return 0;
}
