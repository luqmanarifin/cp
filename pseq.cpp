#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  while(b != 0) {
    long long t = b;
    b = a % b;
    a = t;
  }
  return a;
}

/* This function return the gcd of a and b followed by
    the pair x and y of equation ax + by = gcd(a,b)*/
pair<long long, pair<long long, long long> > extendedEuclid(long long a, long long b) {
    long long x = 1, y = 0;
    long long xLast = 0, yLast = 1;
    long long q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}
 
long long inv(long long a, long long m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}

int main() {
  //ios_base::sync_with_stdio(false);
  
  long long t;
  cin >> t;
  while(t--) {
    long long a, p, n;
    cin >> a >> p >> n;
    if(gcd(a, p) != 1) {
      puts("-1");
      continue;
    }
    long long b = inv(a, p);
    //cout << a << ' ' << b << endl;
    long long ans = (n - n / 2) * a + (n / 2) * b;
    cout << ans << endl;
  }
  
  return 0;
}
