#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long m[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n; long long f, a, b;
    scanf("%d %lld %lld %lld", &n, &f, &a, &b);
    for (int i = 1; i <= n; i++) scanf("%lld", m + i);
    long long cost = 0;
    for (int i = 1; i <= n; i++) {
      cost += min(b, (m[i] - m[i - 1]) * a);
    }
    puts(cost < f? "YES" : "NO");
  }

  return 0;
}
