
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a = (n - 1) % 8;
  if (a == 0 || a == 3) {
    puts("LB");
  } else if (a == 1 || a == 4) {
    puts("MB");
  } else if (a == 2 || a == 5) {
    puts("UB");
  } else if (a == 6) {
    puts("SLB");
  } else {
    puts("SUB");
  }

  return 0;
}
