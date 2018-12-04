#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>
#include <cmath>

using namespace std;

const long long N = 1e9;

long long power(long long a, long long b, long long m) {
  if (b == 0) return 1 % m;
  long long tmp = power(a, b / 2, m);
  tmp = tmp * tmp % m;
  if (b & 1) {
    tmp = tmp * a % m;
  }
  return tmp;
}

vector<long long> prime;
bool is[32000];

long long phi(long long n) {
  long long ret = 1;
  for (auto it : prime) {
    int pw = 0;
    while (n % it == 0) {
      n /= it;
      pw++;
    }
    if (pw) {
      ret *= power(it, pw - 1, 1e18) * (it - 1);
    }
  }
  if (n > 1) {
    ret *= n - 1;
  }
  return ret;
}

pair<long long, long long> extended_euclid(long long a, long long b) {
  long long x = 0, y = 1, lastx = 1, lasty = 0;
  while (b != 0) {
    long long q = a / b;
    long long temp = a;
    a = b;
    b = temp % b;
    temp = x;
    x = lastx - q * x;
    lastx = temp;
    temp = y;
    y = lasty - q * y;
    lasty = temp;
  }
  return make_pair(lastx, lasty);
}

long long inverse(long long a, long long n) {
  auto xy = extended_euclid(a, n);
  return ((xy.first % n) + n) % n;
}

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  if (a == 0) return b;
  return gcd(b, a % b);
}

// compute g^x % mod == h
long long babystep_giantstep(long long g, long long h, long long mod) {
  long long m = int(ceil(sqrt(mod)) + 0.5);
  // while (gcd(power(g, m, mod), mod) != 1) m++;
  // printf("m %lld %lld\n", m, power(g, m, mod));

  map<long long, long long> table;
  long long e = 1;
  for (int i = 0; i < m; i++) {
    table[e] = i;
    e = e * g % mod;
  }
  long long factor = power(g, m, mod);
  factor = inverse(factor, mod);
  e = h;
  for (int i = 0; i < m; i++) {
    if (table.count(e)) {
      return i * m + table[e];
    }
    e = e * factor % mod;
  }
  return -1;
}

int main() {
  for (int i = 2; i * i < N; i++) {
    if (!is[i]) {
      prime.push_back(i);
      for (long long j = 1LL * i * i; j * j < N; j += i) {
        is[j] = 1;
      }
    }
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, m;
    scanf("%lld %lld %lld", &a, &b, &m);
    printf("%lld\n", babystep_giantstep(a, b, m));
  }

  return 0;
}
