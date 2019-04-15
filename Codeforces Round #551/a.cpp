#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  int at = 2e9, ans = -1;
  for (int i = 0; i < n; i++) {
    int s, d;
    scanf("%d %d", &s, &d);
    while (s < t) s += d;
    if (s < at) {
      at = s;
      ans = i;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
