#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    long long sisa = 0, ans = 0;
    for(int i = 0; i < n; i++) {
      long long a;
      scanf("%lld", &a);
      long long del = min(sisa, a);
      sisa -= del;
      a -= del;
      if(a > 0) {
        ans += a / k + (a % k? 1 : 0);
        if(a % k) sisa = k - a % k;
      }
      if(sisa) sisa--;
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}
