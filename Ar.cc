#include <bits/stdc++.h>
using namespace std;

int t;
long long n;

int len(long long x) {
  int res = 0;
  while (x > 0) {
    x /= 10;
    res++;
  }
  return res;
}

long long tenpow(int x) {
  long long res = 1;
  for (int i = 0; i < x; i++) {
    res *= 10;
  }
  return res;
}

long long rev(long long x) {
  long long res = 0;
  while (x> 0) {
    res = 10 * res + (x % 10);
    x /= 10;
  }
  return res;
}

int main() {
  int cs =0;
  scanf("%d", &t);
  while (t--) {
    ++cs;
    scanf("%lld", &n);
    long long res = 0;
    while (n > 1) {
      if (n < 10) {
        n--;
        res++;
        continue;
      }
      int l = len(n);
      long long back = n%tenpow(l/2);
      long long front = n/tenpow(l/2);
      if (back == 0) {
        res += 1;
        n--;
      } else if (back != 1) {
        res += (back - 1);
        n -= (back - 1);
      } else {
        //check front
        long long lowlimit = tenpow((l-1)/2);
        if (l % 2 == 0) {
          lowlimit++;
        } else {
          lowlimit += 10;
        }
        if (front < lowlimit) {
          n -= (tenpow(l / 2));
          res += (tenpow(l / 2));
        } else {
          res++;
          n = rev(n);
        }
      }
    }
    printf("Case #%d: %lld\n", cs, res + 1);
  }
}
