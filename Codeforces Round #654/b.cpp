#include <bits/stdc++.h>

using namespace std;

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, r;
    scanf("%d %d", &n, &r);
    int con = min(r, n - 1); 
    long long ans = sum(con) + (n <= r? 1 : 0);
    printf("%lld\n", ans);
  }

  return 0;
}
