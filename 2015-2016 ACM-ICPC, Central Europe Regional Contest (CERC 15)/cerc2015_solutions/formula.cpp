// Author: Ivan Katanic
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <complex>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1<<19;
const int mod = 1000003;
const int K = 1024; // ~ sqrt(mod)

namespace FFT {
  typedef llint value;
  typedef complex<double> comp;
 
  int N;
  comp omega[MAX];
  comp a1[MAX], a2[MAX];
  comp z1[MAX], z2[MAX];
 
  void fft(comp *a, comp *z, int m = N) {
    if (m == 1) {
      z[0] = a[0];
    } else {
      int s = N/m;
      m /= 2;
 
      fft(a, z, m);
      fft(a+s, z+m, m);
 
      REP(i, m) {
        comp c = omega[s*i] * z[m+i];
        z[m+i] = z[i] - c;
        z[i] += c;
      }
    }
  }
 
  void mult(value *a, value *b, value *c, int len) {
    N = 2*len;
    while (N & (N-1)) ++N;
    assert(N <= MAX);
 
    REP(i, N) a1[i] = 0;
    REP(i, N) a2[i] = 0;
    REP(i, len) a1[i] = a[i];
    REP(i, len) a2[i] = b[i];
 
    REP(i, N) omega[i] = polar(1.0, 2*M_PI/N*i);
    fft(a1, z1, N);
    fft(a2, z2, N);
 
    REP(i, N) omega[i] = comp(1, 0) / omega[i];
    REP(i, N) a1[i] = z1[i] * z2[i] / comp(N, 0);
    fft(a1, z1, N);
 
    REP(i, 2*len) c[i] = round(z1[i].real());
  }
}

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

int fr[MAX], fc[MAX];
int fact[MAX], invfact[MAX];

int choose(int n, int k) {
  return mul(fact[n], mul(invfact[k], invfact[n-k]));
}

int main(void) {
  fact[0] = invfact[0] = 1;
  FOR(i, 1, MAX) {
    fact[i] = mul(fact[i-1], i);
    invfact[i] = powmod(fact[i], mod-2);
  }

  int N, A, B, C;
  scanf("%d %d %d %d", &N, &A, &B, &C);

  for (int i = 0; i < N; ++i)
    scanf("%d", &fr[i]);
  for (int i = 0; i < N; ++i)
    scanf("%d", &fc[i]);
  assert(fr[0] == fc[0]);

  int ans = 0;
  FOR(j, 1, N) {
    int k = choose(N-2 + N-1-j, N-2);
    k = mul(k, powmod(A, N-1));
    k = mul(k, powmod(B, N-1-j));
    ans = add(ans, mul(k, fr[j]));
  }
  FOR(i, 1, N) {
    int k = choose(N-2 + N-1-i, N-2);
    k = mul(k, powmod(A, N-1-i));
    k = mul(k, powmod(B, N-1));
    ans = add(ans, mul(k, fc[i]));
  }

  static llint a[MAX], b[MAX], c[MAX];
  REP(ia, 2) {
    REP(i, N-1) {
      a[i] = mul(powmod(A, i), invfact[i]);
      b[i] = mul(powmod(B, i), invfact[i]);
      if (ia) a[i] /= K; else a[i] %= K;
    }
    
    FFT::mult(a, b, c, N-1);
    REP(i, 2*(N-1)-1) {
      int cc = c[i] % mod;
      if (ia) cc = mul(cc, K);
      ans = add(ans, mul(mul(C, fact[i]), cc));
    }
  }
  printf("%d\n", ans);
  return 0;
}
