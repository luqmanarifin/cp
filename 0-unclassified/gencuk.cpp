#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 4000;
  int m = 4000;
  printf("%d %d\n", n, m);
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      printf("%d %d\n", i, j);
      m--;
      if(m == 0) return 0;
    }
  }
  return 0;
}
