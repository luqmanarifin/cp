
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
    int d = abs(a[i] - a[i - 1]);
    if (i && d > 1) {
      s.insert(d);
    }
  }
  if (s.size() > 1) {
    puts("NO");
  } else {
    puts("YES");
    if (s.size() == 0) {
      printf("%d %d\n", inf, 1);
    } else {
      printf("%d %d\n", inf, *(s.begin()));
    }
  }

  return 0;
}
