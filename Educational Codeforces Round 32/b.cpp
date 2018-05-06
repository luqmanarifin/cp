
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int dx = 0, dy = 0, x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      dx--;
      x++;
    } else if (s[i] == 'R') {
      dx++;
      x++;
    } else if (s[i] == 'U') {
      dy++;
      y++;
    } else {
      dy--;
      y++;
    }
  }
  int ans = x - abs(dx) + y - abs(dy);
  cout << ans << endl;
  return 0;
}
