#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 300;
  printf("%d\n", n);
  srand(time(0));
  for (int i = 0; i < n; i++) printf("%d %d\n", rand() % 30000, rand() % 30000);

  return 0;
}
