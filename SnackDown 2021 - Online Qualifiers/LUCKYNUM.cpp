#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 7 || b == 7 || c == 7) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
