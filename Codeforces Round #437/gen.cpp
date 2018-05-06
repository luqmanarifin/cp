
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 100000;
  int S = 1;
  srand(time(0));
  printf("%d %d\n", n, S);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", 100000, rand() % n, rand() % n);
  }
  return 0;
}
