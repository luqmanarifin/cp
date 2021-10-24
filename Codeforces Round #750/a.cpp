#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    long long tot = a + 2LL * b + 3LL * c;
    printf("%lld\n", tot % 2);
  }

  return 0;
}
