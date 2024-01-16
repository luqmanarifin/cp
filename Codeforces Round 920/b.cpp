#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s %s", &n, a, b);
    int u = 0, v = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '0' && b[i] == '1') u++;
      if (a[i] == '1' && b[i] == '0') v++;
    }
    printf("%d\n", max(u, v));
  }

  return 0;
}
