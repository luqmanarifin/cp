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

using namespace std;

const long long mod = 1e9 + 7;

#define matrix vector<vector<long long> >

matrix one(int n) {
  matrix ret(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) ret[i][i] = 1;
  return ret;
}

matrix mul(matrix a, matrix b) {
  matrix ret(a.size(), vector<long long>(b[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        ret[i][j] += a[i][k] * b[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  return ret;
}

matrix power(matrix a, long long b) {
  if (b == 0) return one(a.size());
  matrix tmp = power(a, b / 2);
  tmp = mul(tmp, tmp);
  if (b & 1) {
    tmp = mul(tmp, a);
  } 
  return tmp;
}

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

void add(long long& a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}

long long mul(long long a, long long b) {
  return a * b % mod;
}

int get(int val, int i) {
  if (val & (1 << i)) {
    return 1;
  } else {
    return 0;
  }
}

long long fact[1000], ifact[1000];

long long c(long long n, long long k) {
  return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < 1000; i++) {
    fact[i] = fact[i-1] * i % mod;
    ifact[i] = power(fact[i], mod - 2);
  }

  matrix can(10, vector<long long>(10, 0));
  matrix cant(10, vector<long long>(10, 0));
  for (int n = 1; n <= 10; n++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      int couple = 0;
      for (int i = 0; i < n; i++) {
        if (i + 1 < n && get(mask, i) == 1 && get(mask, i + 1) == 0) {
          couple++;
        }
      }
      for (int i = 0; i <= couple; i++) {
        add(cant[n-1][n-1-i], c(couple, i));
        add(can[n-1][n-1-i], c(couple, i) * power(2, n - 2 * couple) % mod);
        assert(n >= 2 * couple);
      }
    }
  }
  int d, k;
  scanf("%d %d", &d, &k);
  matrix now(1, vector<long long>(10, 0));
  now[0][k-1] = 1;
  if (d >= 2) {
    now = mul(now, cant);
    // for (int i = 0; i < 10; i++) printf("%lld ", now[0][i]); printf("\n");
    matrix pow = power(can, d - 2);
    now = mul(now, pow);
  }
  cout << now[0][0] << endl;

  return 0;
}
