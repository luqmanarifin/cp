#include <bits/stdc++.h>

using namespace std;

const string NAME = "ascii";

const int N = 105;

char s[N][N];
int a[N][N];

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '.') {
        a[i][j]++;
      }
      if (j) {
        a[i][j] += a[i][j-1];
      }
    }
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '.') {
        ans += 0.5;
      } else {
        if (a[i][j] % 2) {
          ans += 1;
        }
      }
    }
  }
  printf("%d\n", (int) (ans + 0.5));

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}
