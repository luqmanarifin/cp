#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int c = max(k, n / (m + 1));
    for (int i = 0; i < n; i++) printf("%d%c", i % c, i + 1 == n? '\n' : ' ');
  }

  return 0;
}
