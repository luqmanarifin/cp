#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 500, k = 10;
  printf("%d %d\n", n, k);
  for (int i = 0; i < n * k; i++) printf("1 "); printf("\n");
  for (int i = 0; i < n; i++) printf("1 "); printf("\n");
  for (int i = 0; i < k; i++) printf("%d ", i + 1); printf("\n");
  return 0;
}
