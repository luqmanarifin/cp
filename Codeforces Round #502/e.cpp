#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

#define x first
#define y second

typedef long long LD;
const LD EPS = 1e-9, PI = acos(-1);
inline bool eq(LD a, LD b) { return fabs(a-b) < EPS; }
inline bool lt(LD a, LD b) { return a + EPS < b; }
inline bool le(LD a, LD b) { return a < b + EPS; }
inline int sign(LD x) { return eq(x, 0) ? 0 : (x < 0 ? -1 : 1); }

struct point {
  LD x, y;
  point(LD x = 0, LD y = 0) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x+p.x, y+p.y); }
  point operator-(const point& p) const { return point(x-p.x, y-p.y); }
  point operator*(LD s) { return point(x*s, y*s); }
  point operator/(LD s) { return point(x/s, y/s); }
  LD operator*(const point& p) const { return x*p.x + y*p.y; } // dot
  LD operator%(const point& p) const { return x*p.y - y*p.x; } // cross
  LD norm_sq() { return *this * *this; }
  LD norm() { return sqrt(*this * *this); }
  point rotate(LD cs, LD sn) { return point(x*cs-y*sn, x*sn+y*cs); }
  point rotate(LD angle) { return rotate(cos(angle), sin(angle)); }
  bool operator==(const point& p) const { return eq(x, p.x) && eq(y, p.y); }
  bool operator<(const point& p) const { return eq(y, p.y) ? x < p.x : y < p.y; }
};

int ccw(point a, point b, point c) { return sign((b - a) % (c - b)); }


// Graham’s Scan Algorithm
// need implement operator<,-,cross,ccw on Point’s library
long long dist2(point a, point b) {// norm_sq(b - a)
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
point pivot;
bool angle_cmp(point a, point b) {
  if(ccw(pivot, a, b) == 0)
    return dist2(a, pivot) < dist2(b, pivot);
  return ccw(pivot, a, b) > 0;
}

// hasil convexHull tidak siklik(P[0] != P.back())
void convexHull(vector<point> & P) {
  int i, j, n = (int) P.size();
  if(n < 3) {
    return;
  }
  int PO = 0;
  for(i = 1; i < n; i++) {
    if(P[i] < P[PO]) {
      PO = i;
    }
  }
  swap(P[0], P[PO]);
  pivot = P[0];
  sort(++P.begin(), P.end(), angle_cmp);
  // if point on boundary is included then uncomment this:
  // int k = (int)P.size()-1; while (k-1 > 0 && ccw(P[0], P[k-1], P.back()) == 0) k--;
  // reverse(P.begin() + k, P.end());
  vector<point> S;
  S.push_back(P[0]);
  S.push_back(P[1]);
  i = 2;
  while(i < n) {
    j = (int) S.size() - 1;
    // if point on boundary is included then ccw >= 0
    if(j < 1 || ccw(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
    else S.pop_back();
  }
  P = S;
}

const long long mod = 2e9 + 2153;
const long long BIG = 1e9 + 7;

long long mul(long long a, long long b) {
  return a * b % mod;
}

long long add(long long a, long long b) {
  long long ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}

long long encode(long long A, long long B, long long C) {
  long long a = mul(5, B);
  long long b = mul(71, C);
  long long c = mul(A, B);
  long long d = mul(7, mul(B, C));
  long long e = mul(BIG, mul(A, C));
  return (a + b + c + d + e) % mod;
}

// lurus, vector
pair<bool, vector<long long>> encode(vector<point> A) {
  vector<long long> HA;
  bool lurus = 1;
  for (int i = 0; i < A.size(); i++) {
    point bef = A[(i-1+A.size())%A.size()];
    point aft = A[(i+1+A.size())%A.size()];
    point p = A[i] - bef;
    point q = aft - A[i];
    long long a = (p % q) % mod;
    long long b = dist2(A[i], bef) % mod;
    long long c = dist2(A[i], aft) % mod;
    if (a) lurus = 0;
    // printf("%lld %lld %lld\n", a, b, c);
    HA.push_back(encode(a, b, c));
  }
  if (lurus) {
    HA.clear();
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
      HA.push_back(dist2(A[i], A[(i+1)%A.size()]));
    }
  }
  return make_pair(lurus, HA);
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

bool same(vector<long long> a, vector<long long> b) {
  if (a.size() != b.size()) return 0;
  auto temp = a;
  for (auto it : a) temp.push_back(it);
  a = temp;

  vector<long long> s;
  s.assign(a.size() + 1, 0);

  for (int i = 0; i < a.size(); i++) {
    s[i+1] = (s[i] * BIG + a[i]) % mod;
  }
  long long ori = 0;
  for (auto it : b) ori = (ori * BIG + it) % mod;
  long long pw = power(BIG, b.size());
  for (int i = b.size(); i <= a.size(); i++) {
    long long cur = s[i] - (s[i-b.size()] * pw);
    cur %= mod;
    if (cur < 0) cur += mod;
    // printf("%lld %lld\n", ori, cur);
    if (ori == cur) return 1;
  }
  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<point> A, B;
  for (int i = 0; i < n; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    A.push_back(point(p, q));
  }
  for (int i = 0; i < m; i++) {
    int p, q;
    scanf("%d %d", &p, &q);
    B.push_back(point(p, q));
  }
  convexHull(A);
  convexHull(B);
  auto HA = encode(A);
  auto HB = encode(B);
  if (HA.first != HB.first) {
    puts("NO");
    return 0;
  }
  // puts("HA");
  // for (auto it : HA.second) printf("%lld\n", it);
  // puts("HB");
  // for (auto it : HB.second) printf("%lld\n", it);
  puts(same(HA.second, HB.second)? "YES": "NO");

  return 0;
}
