#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 300000;
  int k = 75000;
  printf("%d\n", n);
  for (int i = 0; i < 3*k; i++) printf("1 ");
  printf("%d ", -3*k);
  for (int i = 0; i < k - 1; i++) printf("1 "); printf("\n");

  for (int i = 0; i < k; i++) printf("1 ");
  for (int i = 0; i < 2*k; i++) printf("0 ");
  for (int i = 0; i < k; i++) printf("1 "); printf("\n");

  return 0;
}
