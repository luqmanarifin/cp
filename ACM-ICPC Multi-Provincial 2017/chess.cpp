#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int a[N][N];

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      set<int> s;
      for (int k = 0; k < i; k++) s.insert(a[k][j]);
      for (int k = 0; k < j; k++) s.insert(a[i][k]);
      for (int k = 0; k < N * N; k++) if (!s.count(k)) {
        a[i][j] = k;
        break;
      }
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
