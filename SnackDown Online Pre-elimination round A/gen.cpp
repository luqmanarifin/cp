#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 100000;
  int q = n;
  printf("%d %d\n", n, q);
  srand(time(0));

  for(int i = 0; i < n; i++) {
    int l = rand() % (1000000 - 10) + 1;
    int r = rand() % 10 + 1;
    printf("%d %d\n", l, l + r);
  }
  
  for(int i = 0; i < n; i++) {
    int l = rand() % 1000000 + 1;
    int r = rand() % 1000000 + 1;
    if(l > r) swap(l, r);
    printf("%d %d\n", l, r);
  }
  
  return 0;
}