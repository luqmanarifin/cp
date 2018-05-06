
#include <bits/stdc++.h>

using namespace std;

int a[10];

int main() {
  a[0] = a[6] = a[9] = 1;
  a[8] = 2;
  int l, r;
  scanf("%d %d", &l, &r);
  int ans = -1, p = -1;
  for (int i = l; i <= r; i++) {
    int v = i, cur = 0;
    if (i == 0) {
      cur = 1;
    } else {
      while (v > 0) {
        cur += a[v % 10];
        v /= 10;
      }
    }
    if (ans < cur) {
      ans = cur;
      p = i;
    }
  }
  cout << p << endl;
  return 0;
}
