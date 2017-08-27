#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[N][N];

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == 0 && j == 0) continue;
      set<int> s;
      if (i) s.insert(a[i-1][j]);
      if (j) s.insert(a[i][j-1]);
      if (i && j) s.insert(a[i-1][j-1]);
      for (int k = 0; ; k++) {
        if (!s.count(k)) {
          a[i][j] = k;
          break;
        }
      }
      //if (a[i][j] == 0) printf("%d %d: %d\n", i, j, a[i][j]);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a % 2 == 0 && b % 2 == 0) {
      puts("abdullah");
    } else {
      puts("hasan");
    }
  }
  return 0;
}