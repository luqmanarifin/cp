#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long a, b;
    scanf("%I64d %I64d", &a, &b);
    if(a == 0 && b == 0) {
      puts("0");
      continue;
    }
    long long t = max(abs(a) , abs(b));
    long long base = (2 * t + 1) * (2 * t + 1);
    if(b == -t) {
      long long d = (t + 1) - a;
      printf("%I64d\n", base - d);
      continue;
    } else {
      base -= 2 * t + 1;
    }
    if(a == -t) {
      long long d = b + t;
      printf("%I64d\n", base - d);
      continue;
    } else {
      base -= 2 * t;
    }
    if(b == t) {
      long long d = a + t;
      printf("%I64d\n", base - d);
      continue;
    } else {
      base -= 2 * t;
    }
    long long d = t - b;
    printf("%I64d\n", base - d);
  }
  return 0;
}
