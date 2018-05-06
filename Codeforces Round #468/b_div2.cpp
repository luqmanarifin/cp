
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  a--; b--;
  int dif = -1;
  for (int i = 0; (1 << i) < n; i++) {
    if ((a & (1 << i)) != (b & (1 << i))) {
      dif = i;
    }
  }
  if ((1 << (dif + 1)) == n) {
    puts("Final!");
  } else {
    cout << dif + 1 << endl;
  }
  return 0;
}
