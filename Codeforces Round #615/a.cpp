#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b, c;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    int d = max(a, max(b, c));
    int mini = 3 * d - a - b - c;
    if (n >= mini && (n - mini) % 3 == 0) {
      puts("YES");
    } else {
      puts("NO");
    }
  }

  return 0;
}
