#include <bits/stdc++.h>

using namespace std;

long long sum(long long n) {
  return n * (n - 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", 1 + sum(n - 1));
  }

  return 0;
}
