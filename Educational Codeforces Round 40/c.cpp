
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (i) {
      if (a[i] == a[i-1]) {
        puts("NO");
        return 0;
      }
      int d = abs(a[i] - a[i - 1]);
      if (d > 1) {
        s.insert(d);
      }
    }
  }
  bool can = (s.size() <= 1);
  for (int i = 0; i < n; i++) a[i]--;
  int d = (s.size()? *(s.begin()) : 1);
  for (int i = 1; i < n; i++) {
    int l = min(a[i-1], a[i]);
    int r = max(a[i-1], a[i]);
    if (d > 1 && abs(l - r) == 1 && l / d != r / d) {
      can = 0;
    }
  }
  if (!can) {
    puts("NO");
  } else {
    puts("YES");
    printf("%d %d\n", inf, d);
  }

  return 0;
}
