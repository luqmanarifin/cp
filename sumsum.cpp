#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000;

void norm(long long &a) {
  if(a >= mod) a -= mod;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n;
    scanf("%I64d", &n);
    long long last = n;
    long long ans = 0;
    for(long long i = 1; i * i <= n; i++) {
      ans += n / i;
      ans %= mod;
      last = n / i;
    }
    //printf("nyampe %I64d last %I64d\n", ans, last);
    long long hig = n + 1;
    for(long long i = 1; i < last; i++) {
      long long l = 1, r = hig;
      while(l < r) {
        long long mid = (l + r) >> 1;
        if(n / mid <= i) r = mid;
        else l = mid + 1;
      }
      long long lower = l;
      
      l = 1, r = lower;
      while(l < r) {
        long long mid = (l + r) >> 1;
        if(n / mid < i) r = mid;
        else l = mid + 1;
      }
      long long upper = l;
      ans += (upper - lower) * i;
      //printf("%I64d %I64d %I64d\n", upper, lower, i);
      ans %= mod;
      hig = lower;
    }
    printf("%I64d\n", ans);
  }
  
  return 0;
}