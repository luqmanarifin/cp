#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    bool pos_x = 0, pos_y = 0, neg_x = 0, neg_y = 0;
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (x > 0) pos_x = 1;
      if (x < 0) neg_x = 1;
      if (y > 0) pos_y = 1;
      if (y < 0) neg_y = 1;
    }
    puts(pos_x && pos_y && neg_x && neg_y? "NO" : "YES");
  }  

  return 0;
}
