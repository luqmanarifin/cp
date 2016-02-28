#include <bits/stdc++.h>

using namespace std;

long long a, b, n;
long long l, t, m;

long long f(long long num) {
  return a + (num - 1) * b;
}

long long arith(long long A, long long Un, long long num) {
  return num * (A + Un) / 2;
}

int main() {
  scanf("%I64d %I64d %I64d", &a, &b, &n);
  while(n--) {
    scanf("%I64d %I64d %I64d", &l, &t, &m);
    if(t < f(l)) {
      puts("-1");
      continue;
    }
    long long lef = l, rig = l + 1000005LL;
    while(lef < rig) {
      long long mid = (lef + rig + 1) >> 1;
      if(f(mid) <= t && arith(f(l), f(mid), mid - l + 1) <= m * t) {
        lef = mid;
      } else {
        rig = mid - 1;
      }
    }
    printf("%I64d\n", lef);
  }
  
  return 0;
}
