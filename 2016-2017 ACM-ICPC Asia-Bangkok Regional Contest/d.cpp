#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e14;

long long cros(long long a, long long b, long long c, long long d) {
  return 1LL * a * d - 1LL * b * c;
}

long long area(long long a, long long b, long long c, long long d, long long e, long long f) {
  long long ret =  cros(a, b, c, d) + cros(c, d, e, f) + cros(e, f, a, b);
  if (ret < 0)
    ret = -ret;
  return ret;
}
long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long euler(long long n) {
  long long ret = n;
  for (long long i = 2; i * i <= n; i++) if ((n % i) == 0) {
    while ((n % i) == 0)
      n /= i;
    ret -= ret/i;
  }
  return ret;
}

long long powmod(long long b, long long pw, long long mod) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    pw >>= 1;
    b = (b * b) % mod;
  }
  return ret;
}
int  main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, c, d, k;
    scanf("%I64d %I64d %I64d %I64d %I64d", &a, &b, &c, &d, &k);
    if (a > c) {
      swap(a, c);
      swap(b, d);
    }
    if (a == c) {
      for (long long i = 0; i < k; i++)
        printf("%I64d %I64d\n", a+1, i);
    }
    else if (b == d) {
      for (long long i = 0; i < k; i++)
        printf("%I64d %I64d\n", i, b+1);        
    }
    else {
      long long kk = d-b, n = c-a;
      long long g = gcd(abs(kk), n);
      kk /= g;
      n /= g;
      kk %= n;
      if (kk < 0)
        kk += n;
      long long i = b;
      if (kk > 0 && n > 0) {
        i = (1+a) * powmod(kk, euler(n) - 1, n);
        i %= n;
      }
      while (k > 0) {
        long long bs = gcd(abs(c-a), abs(d-b)) + 2;
        long long yl = 1LL * (d-b) * (i-a) / (c-a) + b, yu = yl+1;
        if (1LL * (c-a) * (yl-b) == 1LL * (i-a) * (d-b))
          yl--;
        long long luas = area(a, b, c, d, i, yl);
        long long s = bs + gcd(abs(c-i), abs(d-yl)) + gcd(abs(a-i), abs(b-yl)) - 2;
        if (luas == s-2) {
          long long x = i, y = yl;
          while (k > 0) {
            if (x > inf || x < -inf || y < -inf || y > inf)
              break;
            printf("%I64d %I64d\n", x, y);
            k--;
            x += a-c;
            y += b-d;
          }
          x = i - a + c;
          y = yl - b + d;
          while (k > 0) {
            x -= a-c;
            y -= b-d;
            if (x > inf || x < -inf || y < -inf || y > inf)
              break;
            printf("%I64d %I64d\n", x, y);
            k--;
          }
          if (k <= 0)
            break;
        }
        luas = area(a, b, c, d, i, yu);
        s = bs + gcd(abs(c-i), abs(d-yu)) + gcd(abs(a-i), abs(b-yu)) - 2;
        if (luas == s-2) {
          long long x = i, y = yu;
          while (k > 0) {
            if (x > inf || x < -inf || y < -inf || y > inf)
              break;
            printf("%I64d %I64d\n", x, y);
            x += a-c;
            y += b-d;
            k--;
          }
          x = i - a + c;
          y = yu - b + d;
          while (k > 0) {
            x -= a-c;
            y -= b-d;
            if (x > inf || x < -inf || y < -inf || y > inf)
              break;
            printf("%I64d %I64d\n", x, y);
            k--;
          }
          if (k <= 0)
            break;
        }
        i += n;
      }
    }
  }
  return 0;
}
