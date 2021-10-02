#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int n = 5;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    int val = rand() % n + 1;
    printf("%d ", val);
  }
  printf("\n");
  return 0;
}
