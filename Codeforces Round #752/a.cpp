#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e10;

long long lcm(long long a, long long b) {
  return a * b / __gcd(a, b);
}

long long pre[N], a[N];

int main() {
  pre[1] = 2;
  for (int i = 2; i < N; i++) {
    pre[i] = lcm(pre[i - 1], i + 1);
    if (pre[i] > inf) break;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", a + i);
      if (pre[i] && a[i] % pre[i] == 0) {
        ok = 0;
      }
    }
    puts(ok? "YES" : "NO");
  }


  return 0;
}
