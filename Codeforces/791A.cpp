#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  for (int ans = 1; ; ans++) {
    a *= 3;
    b *= 2;
    if (a > b) {
      cout << ans << endl;
      return 0;
    }
  }

  return 0;
}
