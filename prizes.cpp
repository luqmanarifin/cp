#include <bits/stdc++.h>

using namespace std;

long long n;

long long worst(long long a) {
  long long l = 0;
  for(int i = 0; i <= n; i++) {
    if((1LL << i) - 1 <= a) {
      l = i;
    } else {
      break;
    }
  }
  long long bit = (1LL << l) - 1;
  return bit << (n - l);
}

long long best(long long a) {
  a = (1LL << n) - 1 - a;
  //cout << a << endl;
  long long l = 0;
  for(int i = 0; i <= n; i++) {
    if((1LL << i) - 1 <= a) {
      l = i;
    } else {
      break;
    }
  }
  //cout << l << endl;
  return (1LL << (n - l)) - 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    long long p;
    scanf("%I64d %I64d", &n, &p);
    long long l = 0, r = (1LL << n) - 1;
    while(l < r) {
      long long mid = (l + r + 1) >> 1;
      if(worst(mid) < p) l = mid;
      else r = mid - 1;
    }
    printf("Case #%d: %I64d ", tt, l);
    l = 0, r = (1LL << n) - 1;
    while(l < r) {
      long long mid = (l + r + 1) >> 1;
      if(best(mid) < p) l = mid;
      else r = mid - 1;
    }
    printf("%I64d\n", l);
  }
  
  //cout << best(6) << endl;
  
  return 0;
}
