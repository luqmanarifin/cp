#include <bits/stdc++.h>

using namespace std;

long long ask(long long x) {
  printf("? %lld\n", x);
  fflush(stdout);
  long long v;
  scanf("%lld", &v);
  return v;
}

void answer(long long x) {
  printf("! %lld\n", x);
  fflush(stdout);
}

vector<long long> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

const int N = 1e6;
int is[N];

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

vector<long long> combine(vector<long long> l, vector<long long> r, long long n) {
  set<long long> s;
  for (auto it : l) s.insert(it);
  for (auto it : r) s.insert(it);
  for (auto i : l) {
    for (auto j : r) {
      if (i <= n / j) {
        s.insert(i * j);
      }
    }
  }
  vector<long long> ret;
  for (auto it : s) ret.push_back(it);
  return ret;
}

vector<long long> factors(long long n) {
  // printf("factorizing %lld\n", n);
  if (n == 1) return {1};
  if (n < N) {
    if (is[n] == 0) return {1, n};
    return combine(factors(is[n]), factors(n / is[n]), n);
  }
  if (mrtest(n)) return {1, n};
  long long f = pollard_rho(n);
  if (f == 1 || f == n) {
    return {1, n};
  }
  auto l = factors(f);
  auto r = factors(n / f);
  return combine(l, r, n);
}

const long long MAX = 1e18;

int main() {
  for (int i = 2; i < N; i++) {
    if (is[i]) continue;
    for (int j = i + i; j < N; j += i) {
      if (!is[j]) {
        is[j] = i;
      }
    }
  }
  vector<long long> primes;
  for (long long i = MAX + 1; i <= MAX + 1000; i++) {
    if (mrtest(i)) {
      primes.push_back(i);
    }
  }
  srand(time(0));

  int t;
  scanf("%d", &t);
  while (t--) {
    random_shuffle(primes.begin(), primes.end());
    
    long long v = ask(primes[0]);
    long long big = primes[0] - v;
    // puts("big found");
    auto fs = factors(big);
    // puts("factorized");
    vector<long long> cans;
    for (auto it : fs) {
      if (primes[0] % big == primes[0] % it && it <= MAX) {
        cans.push_back(it);
        // printf("can: %lld\n", it);
      }
    }
    // puts("cans collected");
    bool found = 0;
    long long prime = big - 1;
    while (1) {
      // if (!mrtest(prime)) {
      //   prime--;
      //   continue;
      // }
      // printf("trying %lld\n", prime);
      auto it = prime;
      prime--;
      set<long long> ret;
      for (auto can : cans) {
        ret.insert(it % can);
      }
      if (ret.size() == cans.size()) {
        found = 1;
        long long v = ask(it);
        bool answered = 0;
        for (auto can : cans) {
          if (it % can == v) {
            answer(can);
            answered = 1;
            break;
          }
        }
        if (!answered) assert(0);
        break;
      }
    } 
    if (!found) assert(0);
  }
  return 0;
}
