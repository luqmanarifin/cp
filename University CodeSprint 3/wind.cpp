#include <bits/stdc++.h>

using namespace std;

const int N = 65;

string dir = "nswe";
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int ans[N][N], n;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < n;
}

int main() {
  int x, y;
  char c;
  scanf("%d %c %d %d", &n, &c, &x, &y);
  vector<int> pri;
  int p = -1;
  for (int i = 0; i < 4; i++) if (dir[i] == c) {
    p = i;
  }
  pri.push_back(p);
  pri.push_back(p ^ 2);
  pri.push_back(p ^ 3);
  pri.push_back(p ^ 1);
  ans[x][y] = 1;
  while (1) {
    int ni = -1, nj = -1;
    for (int i = 0; i < 4; i++) {
      int ti = x + dx[pri[i]];
      int tj = y + dy[pri[i]];
      //printf("asu %d %d: %d\n", ti, tj, pri[i]);
      if (valid(ti, tj) && ans[ti][tj] == 0) {
        //puts("masuk");
        ni = ti;
        nj = tj;
        break;
      }
    }
    if (ni == -1) break;
    ans[ni][nj] = ans[x][y] + 1;
    x = ni;
    y = nj;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
