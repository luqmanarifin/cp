#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool done[10][10];
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

bool ok(int i, int j) {
  for (int k = 0; k < 8; k++) {
    int p = i + dx[k], q = j + dy[k];
    while (valid(p, q)) {
      if (done[p][q]) return 0;
      p += dx[k];
      q += dy[k];
    }
  }
  return 1;
}

bool HELL = 0;

void dfs(int i, int j, int st) {
  if (HELL) return;
  if (st == 8) {
    done[i][j] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (done[i][j]) {
          printf(".");
        } else {
          printf("#");
        }
      }
      printf("\n");
    }
    HELL = 1;
    return;
  }
  for (int k = 1; ; k++) {
    if (HELL) return;
    int p = i + k * dx[st];
    int q = j + k * dy[st];
    if (!valid(p, q)) break;
    if (ok(p, q)) {
      done[i][j] = 1;
      dfs(p, q, st + 1);
      done[i][j] = 0;
    }
  }
}

int main() {
  int ans = 1e9;
  for (n = 1; n <= 10; n++) {
    for (m = 1; m <= 10 && n * m < ans; m++) {
      memset(done, 0, sizeof(done));
      HELL = 0;
      for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
          dfs(i, j, 0);
        }
      }
      if (HELL) {
        printf("bisa %d %d\n", n, m);
        //ans = min(ans, n * m);
      }
    }
  }


  return 0;
}
