#include <bits/stdc++.h>

using namespace std;

int last(long long a) {
  while(a % 10 == 0) a /= 10;
  return a % 10;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%lld", &n);
    while(last(n) == 5) n *= 4;
    printf("%lld\n", n);
  }
  
  return 0;
}
