#include <bits/stdc++.h>

using namespace std;

const int N = 1050;

char s[N][N];
int a[N][N];

int get(int b, int c, int d, int e) {
  int ret = a[d][e];
  if(b) ret -= a[b - 1][e];
  if(c) ret -= a[d][c - 1];
  if(b && c) ret += a[b - 1][c - 1];
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 1; j < m; j++) {
      if(s[i][j] == s[i][j - 1] && s[i][j] == '.') {
        a[2 * i][2 * j - 1]++;
      }
    }
  }
  for(int j = 0; j < m; j++) {
    for(int i = 1; i < n; i++) {
      if(s[i][j] == s[i - 1][j] && s[i][j] == '.') {
        a[2 * i - 1][2 * j]++;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i) a[i][j] += a[i - 1][j];
      if(j) a[i][j] += a[i][j - 1];
      if(i && j) a[i][j] -= a[i - 1][j - 1];
    }
  }
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int b, c, d, e;
    scanf("%d %d %d %d", &b, &c, &d, &e);
    b--; c--; d--; e--;
    printf("%d\n", get(2 * b, 2 * c, 2 * d, 2 * e));
  }
  return 0;
}
