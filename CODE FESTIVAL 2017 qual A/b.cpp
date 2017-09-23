#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (k == i * (m - j) + j * (n - i)) {
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}
