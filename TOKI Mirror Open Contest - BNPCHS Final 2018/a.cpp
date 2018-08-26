#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, a, b, k;
    scanf("%d %d %d %d", &n, &a, &b, &k);
    printf("Kasus #%d: %d\n", tt, n + (b - a) * k);
  }

  return 0;
}

