#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int n = 4000;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) printf("%d ", rand() % 200000 - 100000);
  return 0;
}
