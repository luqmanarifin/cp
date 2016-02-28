#include <bits/stdc++.h>

using namespace std;

int a[10], b[10];

int main() {
  for(int n = 7; n <= 7; n++) {
    for(int mask = 0; mask < (1 << n); mask++) {
      for(int i = 0; i < n; i++) {
        a[i] = (mask & (1 << i)? 1 : 0);
      }
      for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
      }
      printf("\njadi\n");
      while(1) {
        bool change = 0;
        b[0] = a[0];
        b[n - 1] = a[n - 1];
        for(int i = 1; i < n - 1; i++) {
          int zero = !a[i - 1] + !a[i] + !a[i + 1];
          int one = a[i - 1] + a[i] + a[i + 1];
          b[i] = one > zero;
          if(b[i] != a[i]) {
            change = 1;
          }
        }
        for(int i = 0; i < n; i++) {
          a[i] = b[i];
        }
        if(!change) {
          break;
        }
      }
      for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
      }
      printf("\n\n");
    }
  }
  
  return 0;
}
