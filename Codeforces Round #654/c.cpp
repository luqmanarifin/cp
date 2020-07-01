#include <bits/stdc++.h>

using namespace std;

bool solve(long long a, long long b, long long n, long long m) {
  if (m > 0) {
    if (a > b) {
      if (m > b) return 0;
      return solve(a, b - m, n, 0);
    } else {
      if (m > a) return 0;
      return solve(a - m, b, n, 0);
    }
  } else {
    long long tot = a + b;
    if (n > tot) return 0;
    return 1;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, n, m;
    scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
    puts(solve(a, b, n, m)? "Yes" : "No");
  }

  return 0;
}
