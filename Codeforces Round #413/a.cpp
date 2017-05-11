#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t, k, d;
  scanf("%d %d %d %d", &n, &t, &k, &d);
  int bef = ((n + k - 1) / k * t);
  if (bef <= d + t) {
    puts("NO");
  } else {
    puts("YES");
  }

  return 0;
}
