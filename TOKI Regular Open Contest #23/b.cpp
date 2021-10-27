#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> p;
  for (int n = 1; n <= 100; n++) {
    int mul = 1, sum = 0, x = n;
    while (x > 0) {
      mul *= x % 10;
      sum += x % 10;
      x /= 10;
    }
    if (mul + sum == n) p.push_back(n);
  }
  int n;
  scanf("%d", &n);
  printf("%d\n", upper_bound(p.begin(), p.end(), n) - p.begin());

  return 0;
}
