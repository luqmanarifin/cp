#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return (b? gcd(b, a % b) : a);
}

struct item {
  item() {}
  item(int p) : p(p), q(1) {}
  item(int p, int q) : p(p), q(q) {}
  item operator*(const item& other) {
    item ret;
    ret.p = p * other.p;
    ret.q = q * other.q;
    long long fpb = gcd(ret.p, ret.q);
    ret.p /= fpb;
    ret.q /= fpb;
    return ret;
  }
  item operator-(const item& other) {
    item ret;
    long long a = p;
    long long b = q;
    long long c = other.p;
    long long d = other.q;
    ret.p = a * d - b * c;
    ret.q = b * d;
    long long fpb = gcd(ret.p, ret.q);
    ret.p /= fpb;
    ret.q /= fpb;
    return ret;
  }
  item operator/(const item& other) {
    return *this * item(other.q, other.p);
  }
  item operator%(int c) {
    item ret;
    ret.p = p % (c * q);
    ret.q = q;
    return ret;
  }
  long long p, q;
};

int main() {
  int c, v1, v2;
  scanf("%d", &c);
  while (c) {
    scanf("%d %d", &v1, &v2);
    item t;
    if ((v1 > 0 && v2 < 0) || (v1 < 0 && v2 > 0)) {
      int d = abs(v1) + abs(v2);
      t = item(c) / (item(2) * item(d));
    } else {
      int d = abs(v1 - v2);
      t = item(c) / (item(2) * item(d));
    }
    item ans;
    if (v1 > 0) {
      ans = t * item(v1) % c;
    } else {
      ans = (item(c) - (t * item(v1) % c)) % c;
    }
    if (ans.q < 0) {
      ans.p *= -1;
      ans.q *= -1;
    }
    if (ans.q == 1) {
      printf("%lld\n", ans.p);
    } else {
      printf("%lld/%lld\n", ans.p, ans.q);
    }
    
    scanf("%d", &c);
  }

  return 0;
}
