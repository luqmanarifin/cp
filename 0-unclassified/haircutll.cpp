#include <bits/stdc++.h>

using namespace std;

long long n, a[1005], b;

long long under(long long lim) {
  if(lim < 0) return 0;
  long long ret = 0;
  for(int i = 0; i < b; i++) {
    ret += lim / a[i] + 1;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(a, 0, sizeof(a));
    scanf("%d %I64d", &b, &n);
    for(int i = 0; i < b; i++) {
      scanf("%I64d", &a[i]);
    }
    long long l = 0, r = (long long) 1e15 + 5;
    while(l < r) {
      long long mid = (l + r) >> 1;
      if(under(mid) >= n) r = mid;
      else l = mid + 1;
    }
    n -= under(l - 1);
    for(int i = 0; i < b; i++) {
      if(l % a[i] == 0) {
        n--;
        if(n == 0) {
          printf("Case #%d: %d\n", tt, i + 1);
          break;
        }
      }
    }
  }
  
  return 0;
}
