#include <bits/stdc++.h>

using namespace std;

set<int> ucok = {4, 8, 14, 20, 24, 28, 34, 38, 42, 54};

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    printf("Case #%d: ", tt);
    if (n <= 54) {
      puts(ucok.count(n)? "UCOK": "UDIN");
    } else {
      n = (n - 54) % 34;
      switch(n) {
        case 0:
        case 4:
        case 8:
        case 18:
        case 22:
          puts("UCOK");
          break;
        default:
          puts("UDIN");
      }
    }
  }
  return 0;
}
