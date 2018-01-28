#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, -1};

bool vis[N][N];
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m; 
}

int dfs(int x, int y) {
  if (vis[x][y]) return 1;
}

int main() {
  

  return 0;
}
