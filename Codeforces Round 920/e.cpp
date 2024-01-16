#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, xa, ya, xb, yb;
    scanf("%d %d %d %d %d %d", &n, &m, &xa, &ya, &xb, &yb);
    if (xa >= xb) {
      puts("Draw");
      continue;
    }
    int d = (xb - xa);
    if (d % 2) {
      // Alice attempt to win, Bob defend
      int step_a = d / 2 + 1;
      int step_b = d / 2;
      if (ya < yb) {
        int s = min(m, yb + step_b);
        if (s - ya <= step_a) {
          puts("Alice");
        } else {
          puts("Draw");
        }
      } else {
        int s = max(1, yb - step_b);
        if (ya - s <= step_a) {
          puts("Alice");
        } else {
          puts("Draw");
        }
      }

    } else {
      // Bob attempt to win, Alice defend
      int step_a = d / 2;
      int step_b = d / 2;
      if (ya < yb) {
        int s = max(1, ya - step_a);
        if (yb - s <= step_b) {
          puts("Bob");
        } else {
          puts("Draw");
        }
      } else {
        int s = min(m, ya + step_a);
        if (s - yb <= step_b) {
          puts("Bob");
        } else {
          puts("Draw");
        }
      }
    }
  }  

  return 0;
}
