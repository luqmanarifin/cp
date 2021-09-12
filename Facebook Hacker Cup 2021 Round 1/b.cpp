#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int inf = 1e9;

int s[N][N], tmp[N][N];
int d[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int valid(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int shortest_path(int si, int sj, int ti, int tj, int n, int m, int g) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = inf;
    }
  }
  priority_queue<tuple<int, int, int>> pq;
  pq.emplace(-s[si][sj], si, sj);
  d[si][sj] = s[si][sj];
  while (!pq.empty()) {
    int now, p, q;
    tie(now, p, q) = pq.top();
    pq.pop();
    now = -now;
    if (now != d[p][q]) continue;
    for (int i = 0; i < 4; i++) {
      int pi = p + dx[i];
      int qi = q + dy[i];
      if (!valid(pi, qi, n, m)) continue;
      int ncos = now + s[pi][qi];
      if (ncos < d[pi][qi]) {
        d[pi][qi] = ncos;
        pq.emplace(-d[pi][qi], pi, qi);
      }
    }
  }
  return g == d[ti][tj];
}

bool verify(int n, int m, int a, int b) {
  return shortest_path(0, 0, n-1, m-1, n, m, a) && shortest_path(n-1, 0, 0, m-1, n, m, b);
}

void invert(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tmp[j][i] = s[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      s[j][i] = tmp[j][i];
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    printf("Case #%d: ", tt);

    bool inverted = 0;
    if (n > m) {
      invert(n, m);
      swap(n, m);
      inverted = 1;
    }
    int shortest = n + m - 1;
    if (min(a, b) < shortest) {
      printf("Impossible\n");
      continue;
    }
    printf("Possible\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        s[i][j] = 1000;
        if (i == 0 || j == 0 || j == m - 1) {
          s[i][j] = 1;
        }
      }
    }
    s[n-1][m-1] = a - (n + m - 2);
    s[n-1][0] = b - (n + m - 2);
    if (inverted) {
      invert(n, m);
      swap(n, m);
    }
    assert(verify(n, m, a, b));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d%c", s[i][j], j == m - 1? '\n' : ' ');
      }
    }
  }

  return 0;
}
