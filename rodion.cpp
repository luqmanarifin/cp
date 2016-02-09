#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  if(n == 1) {
    if(t < 10) {
      printf("%d\n", t);
    } else {
      puts("-1");
    }
    return 0;
  }
  printf("1");
  int rem = 1 % t;
  for(int i = 0; i < n - 2; i++) {
    printf("0");
    rem = rem * 10 % t;
  }
  rem = rem * 10 % t;
  printf("%d\n", (t - rem) % 10);
  
  return 0;
}
