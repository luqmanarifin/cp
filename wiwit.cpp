#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

long long a[N];

int main() {
  cin.sync_with_stdio(0);
  int n;
  long long d;
  cin >> n >> d;
  for(int i = 0; i<n; i++)
    cin >> a[i];
  long long l = 0, r = 4e9;
  while(l<r) {
    long long m = (l+r)/2;
    long long last = a[0]+m*d;
    bool ok = true;
    for(int i = 1; i<n; i++) {
      if((a[i]-m*d) >= last) {
        ok = false;
        break;
      }
      long long k = (last-a[i])/d;
      k = min(max(-m, k), m);
      long long kk = a[i] + k*d;
      if((k&1) != (m&1)) {
        if((kk+d)<last)
          kk += d;
        else
          kk -= d;
      }
      while(kk >= last)
        kk -= 2*d;
      last = kk;
    }
    if(ok)
      r = m;
    else
      l = m+1;
  }
  cout << l << "\n";
  return 0;
}