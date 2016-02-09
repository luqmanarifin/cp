#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n % 2 == 0) {
      int c = (m - 2) % (n - 1);
      if(c == n - 2) {
        printf("%d\n", n);
      } else {
        puts("2");
      }
    } else {
      int c = (m - 2) % (n - 1);
      if(c == n - 2) {
        printf("%d\n", n);
      } else {
        int d = min(c, n - 3 - c);
        printf("%d\n", 2 + d);
      }
    }
  }
  return 0;
}
