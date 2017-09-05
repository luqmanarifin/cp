#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N][N], b[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  bool hor = 1, ver = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      hor &= (a[i][j] == b[n - 1 - i][j]);
      ver &= (a[i][j] == b[i][n - 1 - j]);
    }
  }
  cout << (hor | ver) << endl;
  return 0;
}