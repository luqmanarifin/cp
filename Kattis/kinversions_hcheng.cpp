#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll &s, ll &t) { // a*s+b*t = g
  if (b==0) { t = 0; s = (a < 0) ? -1 : 1; return (a < 0) ? -a : a;
  } else { ll g = gcd(b, a%b, t, s);  t -= a/b*s;  return g; }
}

ll inverse(ll n, ll mod)
{
  ll s, t;
  gcd(n, mod, s, t);
  return (s > 0) ? s : s + mod;
}

// FFT code taken from http://e-maxx.ru/algo/fft_multiply

const ll mod = 5 * (1 << 25) + 1;
const ll root = 243;
const ll root_1 = 114609789;
const ll root_pw = 1<<25;
 
void fft (vector<ll> & a, bool invert) {
  int n = (int) a.size();
 
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1)
      j -= bit;
    j += bit;
    if (i < j)
      swap (a[i], a[j]);
  }
 
  for (int len=2; len<=n; len<<=1) {
    ll wlen = invert ? root_1 : root;
    for (ll i=len; i<root_pw; i<<=1)
      wlen = ll (wlen * 1ll * wlen % mod);
    for (int i=0; i<n; i+=len) {
      ll w = 1;
      for (int j=0; j<len/2; ++j) {
	ll u = a[i+j],  v = ll (a[i+j+len/2] * 1ll * w % mod);
	a[i+j] = u+v < mod ? u+v : u+v-mod;
	a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
	w = ll (w * 1ll * wlen % mod);
      }
    }
  }
  if (invert) {
    ll nrev = inverse (n, mod);
    for (int i=0; i<n; ++i)
      a[i] = ll (a[i] * 1ll * nrev % mod);
  }
}

const int MAX_LEN = 1000000;

int main()
{
  string s;
  cin >> s;

  int n = s.length();

  int fft_len = 1;
  while (fft_len < 2*MAX_LEN)
    fft_len *= 2;
  
  vector<ll> A(fft_len, 0), B(fft_len, 0), C(fft_len, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') A[i] = 1;
    else B[n-i] = 1;
  }
  
  fft(A, false);
  fft(B, false);

  for (int i = 0; i < fft_len; i++) {
    C[i] = A[i] * B[i] % mod;
  }

  fft(C, true);
  for (int i = n+1; i < 2*n; i++) {
    cout << C[i] << endl;
  }
  cout << endl;
  
  return 0;
}
