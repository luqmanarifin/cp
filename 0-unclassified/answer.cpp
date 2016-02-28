#include <bits/stdc++.h>

using namespace std;

int main() {
  for(int i = 1; i <= 10; i++) {
    int ans = 0;
    for(int j = 1; j <= i; j++) {
      ans += i / j;
    }
    printf("%d ", ans);
  }
  
  return 0;
}