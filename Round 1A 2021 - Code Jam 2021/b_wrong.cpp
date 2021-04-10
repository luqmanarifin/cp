#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int P = 505;

long long prime[N];

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

long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }

vector<long long> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

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

long long pollard_rho(long long n) {
  if (n < N) return prime[n];
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

vector<long long> factorize(long long n) {
  vector<long long> res;
  if (n == 1) return res;
  if (mrtest(n)) {
    res.push_back(n);
    return res;
  }
  long long p = pollard_rho(n);
  auto res_p = factorize(p);
  auto res_np = factorize(n / p);
  for (auto it : res_p) res.push_back(it);
  for (auto it : res_np) res.push_back(it);
  return res;
}

vector<pair<long long, int>> get(long long n) {
  // printf("get %lld\n", n);
  auto primes = factorize(n);
  sort(primes.begin(), primes.end());
  vector<pair<long long, int>> res;
  for (int i = 0; i < primes.size(); i++) {
    int j = i;
    while (j + 1 < primes.size() && primes[j + 1] == primes[j]) j++;
    res.emplace_back(primes[i], j - i + 1);
    i = j;
  }
  return res;
}

long long own[P];

int main() {
  for (int i = 2; i < N; i++) {
    if (prime[i]) continue;
    for (int j = i; j < N; j += i) prime[j] = i; 
  }
  // puts("asu");
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(own, 0, sizeof(own));

    int m;
    scanf("%d", &m);
    long long sum = 0;
    while (m--) {
      int k; long long v;
      scanf("%d %lld", &k, &v);
      own[k] = v;
      sum += 1LL * k * v;
    }
    long long answer = 0;
    for (long long ans = sum; ans >= sum - 64 * 499 && ans >= 2; ans--) {
      // printf("verifying %lld\n", ans);
      auto factors = get(ans);
      // printf("factorization finished %lld\n", ans);
      bool can = 1;
      long long sum_factors = 0;
      for (auto it : factors) {
        if (it.first >= P) {
          can = 0;
          break;
        }
        if (it.second > own[it.first]) {
          can = 0;
          break;
        }
        sum_factors += it.first * it.second;
      }
      if (can && sum_factors == sum - ans) {
        answer = ans;
        break;
      }
    }
    printf("Case #%d: %lld\n", tt, answer);
  }

  return 0;
}
