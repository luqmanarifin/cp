#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    vector<int> done(2);
    int y = 0;
    for (int i = 0; i < 31; i++) {
      if (x & (1 << i)) {
        if (!done[1]) {
          done[1] = 1;
          y |= (1 << i);
        }
      } else {
        if (!done[0]) {
          done[0] = 1;
          y |= (1 << i);
        }
      }
    }
    printf("%d\n", y < x? y : -1);
  }

  return 0;
}
