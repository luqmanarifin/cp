#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("kakurasu.txt", "w", stdout);
  int n = 8;
  printf("   ");
  for(int i = 1; i <= n; i++) {
    printf("%2d ", i);
  }
  printf("\n");
  
  for(int i = 1; i <= n; i++) {
    printf("%2d ", i);
    for(int j = 1; j <= n; j++) {
      printf("%2d ", 0);
    }
    printf("%2d\n", 0);
  }
  
  printf("   ");
  for(int i = 1; i <= n; i++) {
    printf("%2d ", 0);
  }
  
  return 0;
}