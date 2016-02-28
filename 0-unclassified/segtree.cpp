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
const int N = 2e5 + 5;
const int big = (1 << 19);

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL a[N];

struct Segtree {
public:
    Segtree(int _n) : n(_n) {
        add.resize(big);
        num.resize(big);
        _build(1, 0, n-1);
    };
    void update(int ll, int rr, LL x) {
        if(rr < ll) {
            _update(1, 0, n-1, 0, rr, x);
            _update(1, 0, n-1, ll, n-1, x);
        } else
            _update(1, 0, n-1, ll, rr, x);
    }
    long long find(int ll, int rr) {
        LL cur = INF;
        if(rr < ll) {
            cur = min(cur, _find(1, 0, n-1, 0, rr));
            cur = min(cur, _find(1, 0, n-1, ll, n-1));
        } else
            cur = min(cur, _find(1, 0, n-1, ll, rr));
        return cur;
    }
private:
    void _build(int pos, int l, int r) {
        if(l == r) {
            add[pos] = 0;
            num[pos] = a[l];
            return;
        }
        int lef = pos << 1, rig = lef | 1, mid = (l + r) >> 1;
        _build(lef, l, mid);
        _build(rig, mid+1, r);
        num[pos] = min(num[lef], num[rig]);
        add[pos] = 0;
    }
    void _update(int pos, int l, int r, int ll, int rr, LL x) {
        if(l == ll && r == rr) {
            add[pos] += x;
            return;
        }	
        int lef = pos << 1, rig = lef | 1, mid = (l + r) >> 1;
        if(ll <= mid) _update(lef, l, mid, ll, min(rr, mid), x);
        if(mid < rr) _update(rig, mid+1, r, max(mid+1, ll), rr, x);
        num[pos] = min(num[lef] + add[lef], num[rig] + add[rig]);
    }
    long long _find(int pos, int l, int r, int ll, int rr) {
        if(l == ll && r == rr) {
            return num[pos] + add[pos];
        }
        int lef = pos << 1, rig = lef | 1, mid = (l + r) >> 1;
        LL cur = INF;
        if(ll <= mid)
            cur = min(cur, _find(lef, l, mid, ll, min(rr, mid)));
        if(mid < rr)
            cur = min(cur, _find(rig, mid+1, r, max(mid+1, ll), rr));
        return cur + add[pos];
    }
    int n;
    vector<LL> add, num;
};

bool space(char c) {
    if(('0' <= c && c <= '9') || c == '-') return 0;
    return 1;
}

int main(void)
{
    int n, i, j;
    char junk[105];
    sf("%d", &n);
    FORS(i, n) sf("%I64d", a + i);
    Segtree seg(n);
    
    int q;
    sf("%d", &q);
    gets(junk);
    FOR(j, 1, q) {
        LL r, l, x;
        gets(junk);
        stringstream ss(junk);
        ss >> l >> r;
        if(ss >> x)
            seg.update(l, r, x);
        else
            pf("%I64d\n", seg.find(l, r));
    }
    return 0;
}