#include <bits/stdc++.h>

using namespace std;

int main() {
  int a = 1000;
  bool done = 0;
  for(int i = 1; i <= a; i++) {
    if(i * i >= a && !done) {
      printf("SURPRISE %d\n", i);
      done = 1;
    }
    printf("%d ", a / i);
  }
  
  return 0;
}