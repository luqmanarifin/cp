#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 2000, a = 2000, b = 2000;
  printf("%d %d %d\n", n, a, b);
  for (int i = 0; i < n; i++) {
    printf("0.%.3d ", rand() % 1000);
  } printf("\n");
  for (int i = 0; i < n; i++) {
    printf("0.%.3d ", rand() % 1000);
  } printf("\n");
  return 0;
}
