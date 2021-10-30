#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    long long rem = (y % x) / 2;
    vector<long long> cans = {x + y, x, (x + y) / 2, y - 1, y - rem};
    bool found = 0;
    for (auto n : cans) {
      if (n % x == y % n) {
        printf("%lld\n", n);
        found = 1;
        break;
      }
    }
    if (!found) assert(0);
  }
  return 0;
}
