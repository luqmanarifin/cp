#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int MOD[] = { 597804841, 618557587, 998244353 };
const int N = 500 * 1000 + 13;
const int K = 3;

using hs = array<int, K>;

int add(int x, int y, int mod) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
  return x;
}

int mul(int x, int y, int mod) {
  return x * 1LL * y % mod;
}

hs get(const int& x) {
  hs c;
  forn(i, K) c[i] = x;
  return c;
}

hs operator +(const hs& a, const hs& b) { 
  hs c;
  forn(i, K) c[i] = add(a[i], b[i], MOD[i]);
  return c;
}

hs operator -(const hs& a, const hs& b) {
  hs c;
  forn(i, K) c[i] = add(a[i], -b[i], MOD[i]);
  return c; 
}

hs operator *(const hs& a, const hs& b) {
  hs c;
  forn(i, K) c[i] = mul(a[i], b[i], MOD[i]);
  return c; 
}

int n, m;
string s, sx;
hs sum[N], pw[N];

hs get(int l, int r) {
  return sum[r] - sum[l] * pw[r - l];
}

vector<int> zfunction(const string& s) {
  int n = s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  
  cin >> s >> sx;
  n = s.size();
  m = sx.size();
  
  pw[0] = get(1);
  forn(i, N - 1) pw[i + 1] = pw[i] * get(10); 
  sum[0] = get(0);
  forn(i, n) sum[i + 1] = sum[i] * get(10) + get(s[i] - '0'); 
  hs x = get(0);
  forn(i, m) x = x * get(10) + get(sx[i] - '0');
  
  if (m > 1) for (int i = 0; i + 2 * (m - 1) <= n; ++i) {
    if (get(i, i + m - 1) + get(i + m - 1, i + 2 * (m - 1)) == x) {
      cout << i + 1 << ' ' << i + m - 1 << '\n';
      cout << i + m << ' ' << i + 2 * (m - 1) << '\n';
      return 0;
    }
  }
  
  auto z = zfunction(sx + "#" + s);
  
  for (int i = 0; i + m <= n; ++i) {
    int lcp = z[m + i + 1];
    for (int len = m - lcp - 1; len <= m - lcp; ++len) {
      if (len < 1) continue;
      if (i + m + len <= n && get(i, i + m) + get(i + m, i + m + len) == x) {
        cout << i + 1 << ' ' << i + m << '\n';
        cout << i + m + 1 << ' ' << i + m + len << '\n';
        return 0;
      }
      if (i >= len && get(i - len, i) + get(i, i + m) == x) {
        cout << i - len + 1 << ' ' << i << '\n';
        cout << i + 1 << ' ' << i + m << '\n';
        return 0;
      }
    }
  }
  
  assert(false);
}