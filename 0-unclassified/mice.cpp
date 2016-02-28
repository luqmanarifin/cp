#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

double f[N][N][2];

double get(int a, int b) {
  if(a < 0 || b <= 0) return 0.;
  return 1. * a / b;
}

// c = 0 is princess :3
double dfs(int w, int b, int c) {
  if(f[w][b][c] > -0.5) return f[w][b][c];
  double& ret = f[w][b][c] = 0;
  if(w <= 0 || b < 0) return ret;
  if(c == 0) {
    ret = get(w, w + b);
    ret += get(b, w + b) * dfs(w, b - 1, c ^ 1);
  } else {
    ret += get(b, w + b) * get(w, w + b - 1) * dfs(w - 1, b - 1, c ^ 1);
    ret += get(b, w + b) * get(b - 1, w + b - 1) * dfs(w, b - 2, c ^ 1);
  }
  return ret;
}

int main() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      f[i][j][0] = f[i][j][1] = -1.;
    }
  }
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%.15f\n", dfs(a, b, 0));
  return 0;
}
