#include <bits/stdc++.h>

using namespace std;

int main() {
  for(int n = 1; n <= 1000; n *= 5) {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += n / __gcd(i, n);
    }
    printf("%d : %d\n", n, ans);
  }
  
  return 0;
}
