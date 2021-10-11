#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[2][N];
bool vis[2][N];

int dx[] = {-1, 0, 1, -1, 0, 1, 1, -1};
int dy[] = {1, 1, 1, -1, -1, -1, 0, 0};
int n;

bool valid(int i, int j) {
  return 0 <= i && i < 2 && 0 <= j && j < n;
}

void dfs(int p, int q) {
  if (vis[p][q]) return;
  vis[p][q] = 1;
  for (int i = 0; i < 8; i++) {
    int a = p + dx[i];
    int b = q + dy[i];
    if (!valid(a, b)) continue;
    if (s[a][b] == '1') continue;
    dfs(a, b);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(vis, 0, sizeof(vis));

    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
      scanf("%s", s[i]);
    }
    dfs(0, 0);
    puts(vis[1][n-1]? "YES" : "NO");
  }

  return 0;
}
