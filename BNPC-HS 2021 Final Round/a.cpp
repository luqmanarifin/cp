#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int c[N], a[N];
char d[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %c", c + i, d + i);
    if (d[i] == 'U' && c[i] > 1) {
      a[i] = 2 * m - c[i] - 1;
    }
    if (d[i] == 'D') {
      a[i] = c[i] - 1;
    }
  }
  bool same = 1;
  set<int> s;
  for (int i = 1; i < n; i++) {
    if (a[i] % 2 != a[i - 1] % 2) {
      same = 0;
    }
    s.insert(a[i]);
  }
  if (same && s.size() <= 2) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
