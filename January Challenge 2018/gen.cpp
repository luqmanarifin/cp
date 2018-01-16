#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 1000;
  srand(time(0));
  printf("%d\n", n);
  while (n--) printf("%d ", rand() ); printf("\n");
  int q = 1000;
  printf("%d\n", q);
  while (q--) printf("%d %d\n", rand(), rand());
  return 0;
}
