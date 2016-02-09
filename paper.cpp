#include <bits/stdc++.h>

/**
 * Codeforces Round #263 (Div. 2)
 * Problem : E
 * Luqman Arifin (kadalbonek)
 */

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
const int N = 1e5 + 10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL bit[N];
int n;

void add(int pos, LL add) {
	for(; pos <= n; pos |= pos + 1)
		bit[pos] += add;
}

LL find(int pos) {
	LL ret = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ret += bit[pos];
	return ret;
}

int main(void)
{
	int q, i;
	sf("%d %d", &n, &q);
	FOR(i, 1, n) add(i, 1);
	int shift = 0, len = n;
	bool st = 0;
	while(q--) {
		int type, p, l, r;
		sf("%d", &type);
		if(type == 1) {
			sf("%d", &p);
			int rev = len-shift-p;
			if(st == 0) {
				if(p <= rev) {
					FOR(i, 1, p) {
						LL move = find(shift+p+1-i) - find(shift+p-i);
						add(shift+p+i, move);
					}
					shift += p;
				} else {
					FOR(i, 1, rev) {
						LL move = find(shift+p+i) - find(shift+p+i-1);
						add(shift+p+1-i, move);
					}
					len -= rev;
					st ^= 1;
				}
			} else {
				if(p <= rev) {
					FOR(i, 1, p) {
						LL move = find(shift+rev+i) - find(shift+rev+i-1);
						add(shift+rev+1-i, move);
					}
					len -= p;
				} else {
					FOR(i, 1, rev) {
						LL move = find(shift+rev+1-i) - find(shift+rev-i);
						add(shift+rev+i, move);
					}
					shift += rev;
					st ^= 1;
				}
			}
		} else {
			sf("%d %d", &l, &r);
			if(st == 0)
				pf("%I64d\n", find(shift+r) - find(shift+l));
			else {
				pf("%I64d\n", find(len-l) - find(len-r));
				//pf("haha %d %d\n", len-l, len-r);
			}
		}
	} 
	return 0;
}
