
#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  if (y < 1) {
    puts("NO");
    return 0;
  }
  int nx = 0, ny = 1;
  nx += y - ny;
  ny = y;
  if (x > 0) {
    if (x >= nx && (x - nx) % 2 == 0 && nx > 0) {
      puts("YES");
    } else {
      puts("NO");
    }
  } else {
    if (x == nx) {
      puts("YES");
    } else {
      puts("NO");
    }
  }

  return 0;
}
