#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s %s", &n, a, b);
    bool same = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) continue;
      if (a[i] > b[i]) swap(a[i], b[i]);
      if (a[i] == 'B' && b[i] == 'G') continue;
      same = 0;
    }
    puts(same? "YES" : "NO");
  }

  return 0;
}
