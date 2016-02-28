#include <bits/stdc++.h>

using namespace std;

const long long lim = 5000;

long long c, hr, hb, wr, wb;

inline long long lcm(long long a, long long b) {
  return a / __gcd(a, b) * b;
}

int main() {
  cin >> c >> hr >> hb >> wr >> wb;
  if(wb < wr) {
    swap(wb, wr);
    swap(hb, hr);
  }
  long long ans = 0;
  if(lim < wb) {
    long long pol = c / wb;
    for(long long i = 0; i <= pol; i++) {
      long long cur = i * hb + (c - i * wb) / wr * hr;
      ans = max(ans, cur);
    }
  } else {
    long long kpk = lcm(wr, wb);
    long long pak = max(kpk / wr * hr, kpk / wb * hb);
    long long until = max(wr, wb);
    for(long long b = 0; b <= until; b++) {
      for(long long r = 0; r <= until; r++) {
        long long w = b * wb + r * wr;
        if(c < w) break;
        ans = max(ans, b * hb + r * hr + (c - w) / kpk * pak);
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}
