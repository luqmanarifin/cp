#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e6 + 10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL f[N];

#define upd(x) if(x >= mod) x -= mod; else if(x < 0) x += mod

struct fenwick {
public:
    fenwick(int _n) : n(_n) {
        a.resize(n + 1);
        at.resize(n + 1);
        atc.resize(n + 1);
    };
    void init(int pos, int val) {
        _update(pos, 0, 0, val);
    }
    void update(int l, int r) {
        int now, nex;
        if(l & 1) {
            now = f[l + 1];
            nex = -f[l + 2];
        } else {
            now = -f[l + 1];
            nex = f[l + 2];
        }
        _update(l, now, nex, -1);
        _update(r + 1, -now, -nex, f[r + 2 - l]);
    }
    long long find(int l, int r) {
        LL cur = _find(r) - _find(l - 1);
        cur %= mod;
        if(cur < 0) cur += mod;
        return cur;
    }
    void debug() {
        for(int i = 0; i < n; i++) {
          cerr << find(i, i) << ' ';
        }
        cerr << endl;
    }
private:
    void _update(int pos, long long now, long long nex, long long sum) {
        for(; pos <= n; pos |= pos + 1) {
            a[pos] += now; upd(a[pos]);
            at[pos] += nex; upd(at[pos]);
            atc[pos] += sum; upd(atc[pos]);
        }
    }
    long long _find(int pos) {
        int r = pos;
        long long now = 0, nex = 0, sum = 0;
        for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            now += a[pos]; upd(now);
            nex += at[pos]; upd(nex);
            sum += atc[pos]; upd(sum);
        }
        return (now*f[r + 5] + nex*f[r + 4] + sum) % mod;
    }
    vector<LL> a, at, atc;
    int n;
};

int main(void)
{
    int i, j, n, m, x;
    f[0] = f[1] = 1;
    FOR(i, 2, N - 1) {
        f[i] = f[i-1] + f[i-2];
        upd(f[i]);
    }
    sf("%d %d", &n, &m);
    fenwick fen(n);
    
    FORS(i, n) {
        fen.init(i, 0);
    }
    // fen.debug();
    while(m--) {
        int t, l, r;
        sf("%d %d %d", &t, &l, &r);
        --l, --r;
        if(t == 0) fen.update(l, r);
        else pf("%I64d\n", fen.find(l, r));
        //fen.debug();
    }
    return 0;
}
