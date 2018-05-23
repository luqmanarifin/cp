#include <bits/stdc++.h>

using namespace std;

set<tuple<int, int, int>> s;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    char c; int x, y, r;
    scanf(" %c %d %d %d", &c, &x, &y, &r);
    if (c == 'A') {
      bool can = 1;
      for (auto it : s) {
        int xi, yi, ri;
        tie(xi, yi, ri) = it;
        if ((x - xi)*(x - xi) + (y - yi)*(y - yi) < (r + ri)*(r + ri)) {
          can = 0;
        }
      }
      if (can) {
        s.insert(make_tuple(x, y, r));
      }
      puts(can? "Ok" : "No");
    } else {
      auto it = s.lower_bound(make_tuple(x, y, r));
      if (it != s.end()) {
        int xi, yi, ri;
        tie(xi, yi, ri) = *it;
        if (xi == x && yi == y && ri == r) {
          s.erase(it);
          puts("Ok");
        } else {
          puts("No");
        }
      } else {
        puts("No");
      }
    }
  }

  return 0;
}
