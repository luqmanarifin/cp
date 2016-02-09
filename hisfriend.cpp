#include <bits/stdc++.h>
 
using namespace std;

long long seg;
bool half;

long long pre(int n) {
  return 1LL * n * (n + 1) / 2;
}

void addhalf() {
  if(half) seg++;
  half ^= 1;
}
 
// counting sum from l to r
long long sum(long long l, long long r) {
  if(l > r) return 0;
  return pre(r) - (l - 1 > 0? pre(l - 1) : 0);
}
 
long long count(long long l, long long r) {
  if(l > r) return 0;
  return r - l + 1;
}

// counting sum from l.50 to r.50
long long sumhalf(long long l, long long r) {
  if(l > r) return 0;
  long long cnt = count(l, r);
  if(cnt % 2) {
    addhalf();
  }
  return sum(l, r) + cnt / 2;
}
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    if(a > b) {
      swap(a, b);
      swap(c, d);
    }
    seg = 0;
    half = 0;
    
    long long t = min(a, b - c);
    if(t < 0) t = 0;
    seg += t * c;
    long long grab = min(b - a, c);
    long long sisa = a - t;
    seg += sumhalf(grab, grab + sisa - 1);
    
    t = min(a + 1, d + 1);
    if(t <= a) {
      seg += count(t, a) * d;
    }
    if(t >= 2) {
      seg += sumhalf(0, t - 2);
    }
    double ans = ((double) seg + (half? 0.5 : 0)) / (double) (a * b);
    printf("%.15lf\n", ans);
  }
  
  return 0;
}
     