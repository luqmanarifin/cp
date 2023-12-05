//start of jonathanirvings' template v3.0.3 (BETA)
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
 
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
 
#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG
  #define VALUE(x)
  #define debug(...)
#endif
 
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
 
inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}
 
inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}
 
inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}
 
inline string uppercase(string s){
  int n = SIZE(s);
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
 
inline string lowercase(string s){
  int n = SIZE(s);
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
 
inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}
 
//end of jonathanirvings' template v3.0.3 (BETA)
 
#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1
 
#ifdef _MSC_VER
#include <intrin.h>
#endif
 
#if __cplusplus >= 202002L
#include <bit>
#endif
 
namespace atcoder {
 
namespace internal {
 
#if __cplusplus >= 202002L
 
using std::bit_ceil;
 
#else
 
// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}
 
#endif
 
// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}
 
// @param n `1 <= n`
// @return same with std::bit::countr_zero
constexpr int countr_zero_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}
 
}  // namespace internal
 
}  // namespace atcoder
 
#endif  // ATCODER_INTERNAL_BITOP_HPP
 
#ifndef ATCODER_SEGTREE_HPP
#define ATCODER_SEGTREE_HPP 1
 
#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>
 
namespace atcoder {
 
#if __cplusplus >= 201703L
 
template <class S, auto op, auto e> struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");
 
#else
 
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
 
#endif
 
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
 
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
 
    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
 
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;
 
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
 
    S all_prod() const { return d[1]; }
 
    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
 
    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
 
  private:
    int _n, size, log;
    std::vector<S> d;
 
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
 
}  // namespace atcoder
 
#endif  // ATCODER_SEGTREE_HPP
 
struct Node {
  LL total = 0;
  LL premax = -INFF;
  LL sufmax = -INFF;
  LL max = -INFF;
 
  Node(LL x)
  {
    total = premax = sufmax = max = x;
  }
 
  Node() {
    total = 0;
    premax = sufmax = max = -INFF;
  }
};
 
Node op(Node a, Node b)
{
  if (b.max == -INFF) return a;
  if (a.max == -INFF) return b;
  Node c;
  c.total = a.total + b.total;
  c.premax = max(a.premax, a.total + b.premax);
  c.sufmax = max(b.sufmax, b.total + a.sufmax);
  c.max = max(max(a.max, b.max), max(c.premax, c.sufmax));
  MAX(c.max,a.sufmax + b.premax);
  return c;
}
 
Node e() {
  return Node();
}
 
int n,m;
int l,r,x,k;
int q;
vii change[100005];
LL risan[100005];
vector<pair<pii,int>> query[100005];
 
int main()
{
  scanf("%d %d",&n,&m);
  REP(i,m)
  {
    scanf("%d %d %d",&l,&r,&x);
    --l; --r;
    change[l].pb(mp(i,x));
    change[r+1].pb(mp(i,-x));
  }
  scanf("%d",&q);
  REP(i,q)
  {
    scanf("%d %d %d",&k,&l,&r);
    --k; --l; --r;
    query[k].pb(mp(mp(l,r),i));
  }
  atcoder::segtree<Node, op, e> seg(m);
  REP(i,m) seg.set(i,Node(0));
  REP(i,n)
  {
    for (pii c : change[i])
    {
      seg.set(c.fi,Node(seg.get(c.fi).total + c.se));
    }
    for (pair<pii,int> qu: query[i])
    {
      risan[qu.se] = seg.prod(qu.fi.fi,qu.fi.se+1).max;
    }
  }
  REP(i,q) printf("%lld\n",risan[i]);
  return 0;
}