#include <bits/stdc++.h>

using namespace std;

int main() {
  for (int y = 2; y <= 10; y += 2) {
    for (int n = 1; n <= y; n++) {
      printf("%d mod %d = %d\n", y, n, y % n);
    }
  }
  int largest = 0;
  for (int x = 2; x <= 1000; x += 2) {
    for (int y = x; y <= 1000; y += 2) {
      // int n = 0;
      // if (x > y) {
      //   n = x + y;
      // } else if (y % x == 0) {
      //   n = x;
      // } else {
      //   n = (x + y) / 2;
      // }
      // printf("%d %d\n", x, y);
      // assert(n % x == y % n);
      int rem = (y % x) / 2;
      vector<int> cans = {(x + y) / 2, y - 1, y - rem};
      bool easy = 0;
      for (auto n : cans) {
        if (n % x == y % n) {
          easy = 1;
          break;
        }
      }
      if (easy) continue;

      bool found = 0;
      for (int n = y; n >= 1; n--) {
        if (n % x == y % n) {
          found = 1;
          printf("%d %d: %d - %d\n", x, y, n, y - n);
          largest = max(largest, abs(n - y));
          break;
        }
      }
      if (!found) printf("%d %d not found\n", x, y);
    }
  }
  cout << largest << endl;
  return 0;
}
