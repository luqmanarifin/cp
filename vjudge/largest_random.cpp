#include <bits/stdc++.h>

using namespace std;

vector<long long> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

long long largemul(long long a, long long b, long long n) {
  // assert(0 <= a && a < n && 0 <= b && b < n);
  long long r = 0;
  for (; b; b >>= 1, a <<= 1) {
    if (a >= n) a -= n;
    if (b & 1) {
      r += a;
      if (r >= n) r -= n;
    }
  }
  return r;
}

long long fastexp(long long a, long long b, long long n) {
  // assert(0 <= a && a < n && b >= 0);
  long long ret = 1;
  for (; b; b >>= 1, a = largemul(a, a, n))
    if (b & 1) ret = largemul(ret, a, n);
  return ret;
}

bool mrtest(long long n) {
  if (n == 1) return false;
  long long d = n-1;
  int s = 0;
  while ((d & 1) == 0) {
    s++;
    d >>= 1;
  }
  s--;
  if (s < 0) s = 0;
  for (int j = 0; j < (int)A.size(); j++) {
    if (A[j] >= n) continue;
    long long ad = fastexp(A[j], d, n);
    if (ad == 1) continue;
    bool notcomp = false;
    long long a2rd = ad;
    for (int r = 0; r <= s; r++) {
      if(a2rd == n-1) {notcomp = true; break;}
      a2rd = largemul(a2rd, a2rd, n);
    }
    if (!notcomp) {
      return false;
    }
  }
  return true;
}

long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }

long long pollard_rho(long long n) {
  int i = 0, k = 2;
  long long x = 3, y = 3; // random seed = 3, other values possible
  while (1) {
    i++;
    x = largemul(x, x, n)-1; // generating function
    if (x < 0) x += n;
    long long d = gcd(llabs(y - x), n); // the key insight
    if (d != 1 && d != n) return d;
    if (i == k) y = x, k <<= 1;
  }
}

const int N = 1e6 + 5;

map<long long, long long> mp;
int last[N];

long long solve(long long n) {
  if (n == 1) return 1;
  if (n < N) return last[n];
  if (mp.count(n)) return mp[n];
  if (mrtest(n)) return mp[n] = n;
  long long divs = pollard_rho(n);
  return mp[n] = max(solve(divs), solve(n / divs));
}  

int main() {
  for (int i = 2; i < N; i++) {
    if (!last[i]) {
      for (long long j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  //for (int i = 2; i <= 10; i++) printf("%d: %d\n", i, last[i]);
  
  long long n;
  while (1) {
    scanf("%lld", &n);
    if (n == 0) break;
    if (n == 1 || mrtest(n)) {
      puts("-1");
      continue;
    }
    printf("%lld\n", solve(n));
  }

  return 0;
}
