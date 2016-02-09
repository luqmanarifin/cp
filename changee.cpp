#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%lld", &n);
    if(n == 1) {
      puts("1");
    } else if(n == 2) {
      puts("8");
    } else {
      printf("%lld\n", 6*n*n-12*n+8);
    }
  }
  
  return 0;
}
