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

long long ans[N];
map<long long, long long> cache;
long long last[N];

vector<long long> factors[N];
vector<long long> prime;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp;
  if (b & 1) {
    tmp = tmp * a;
  }
  return tmp;
}

long long arith(long long r, long long n) {
  long long ret = 0, now = 1;
  for (int i = 0; i < n; i++) {
    ret += now;
    now *= r;
  }
  return ret;
}

long long find_prime_factor(long long n) {
  if (n < N) return last[n];
  if (mrtest(n)) return n;
  return find_prime_factor(pollard_rho(n));
}

long long solve(long long n, long long a) {
  if (n < N) return ans[n];
  long long ret = 1;
  for (auto it : factors[n - a]) {
    long long f = it;
    int pw = 0;
    while (n % f == 0) {
      pw++;
      n /= f;
    }
    ret = ret * arith(f, pw + 1);
  }
  if (n > 1) {
    ret = ret * arith(n, 2);
  }
  return ret;
}

int main() {
  last[1] = 1;
  for (int i = 2; i < N; i++) {
    if (last[i] == 0) {
      prime.push_back(i);
      for (int j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  ans[1] = 1;
  for (int i = 2; i < N; i++) {
    long long n = i;
    long long f = last[i];
    int pw = 0;
    while (n % f == 0) {
      pw++;
      n /= f;
    }
    ans[i] = ans[n] * arith(f, pw + 1);
  }
  long long a, b;
  cin >> a >> b;
  for (auto it : prime) {
    long long st = a / it * it;
    while (st <= b) {
      if (a <= st) {
        factors[st - a].push_back(it);
      }
      st += it;
    }
  }

  long long ret = 0;
  for (long long i = a; i <= b; i++) {
    ret += solve(i, a);
  }
  cout << ret << endl;
  return 0;
}
