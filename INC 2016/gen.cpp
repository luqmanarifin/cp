#include <bits/stdc++.h>

using namespace std;

int main() {
  puts("100");
  srand(time(0));
  for (int tt = 1; tt <= 100; tt++) {
    int n = 2000;
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
      printf("%d ", rand() % 10 + 1);
    }
    printf("\n");
  }
  
  return 0;
}