#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool leaf[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
      leaf[i] = 0;
    }
    while (m--) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      leaf[b] = 1;
    }
    int non_leaf = -1;
    for (int i = 1; i <= n; i++) {
      if (!leaf[i]) {
        non_leaf = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == non_leaf) continue;
      printf("%d %d\n", i, non_leaf);
    }
  }

  return 0;
}
