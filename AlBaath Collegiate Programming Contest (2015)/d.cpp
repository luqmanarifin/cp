#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%I64d", &n);
    if(n % 8) {
      puts("Impossible");
    } else {
      printf("%I64d %I64d %I64d\n", 11 * n / 8, 7 * n / 8, 6 * n / 8);
    }
  }
  return 0;
}
