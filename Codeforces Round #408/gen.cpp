#include <bits/stdc++.h>

using namespace std;

int main() {
  printf("1000 32 33\n");
  int t = 500, now = 2;
  printf("%d ", t);
  while (t--) {
    printf("%d ", now);
    now += 2;
  }
  
  t = 334;
  now = 1;
  printf("%d ", t);
  while (t--) {
    printf("%d ", now);
    now += 3;
  }

  return 0;
}
