#include <bits/stdc++.h>

using namespace std;

const int N = 400;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

// petak - ke - arah
int vis[N][N][35][8];
bool done[N][N];
int a[35], n;

void dfs(int i, int j, int ke, int d) {
  if (vis[i][j][ke][d] || ke == n) return;
  //printf("MPIK %d %d %d %d\n", i, j, ke, d);
  vis[i][j][ke][d] = 1;
  
  for (int k = 0; k < a[ke]; k++) {
    done[i][j] = 1;
    //printf("%d %d\n", i, j);
    if (k != a[ke] - 1) {
      i += dx[d];
      j += dy[d];
    }
  }
  int l = (d + 1) % 8;
  int r = (d + 7) % 8;
  dfs(i + dx[l], j + dy[l], ke + 1, l);
  dfs(i + dx[r], j + dy[r], ke + 1, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  dfs(200, 200, 0, 0);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans += done[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}
