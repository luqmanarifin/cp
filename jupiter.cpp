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

const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL bit[N], mod, base;
int l;

LL power(LL a, LL b) {
	if(b == 0) return 1;
	LL temp = power(a, b/2);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

LL inv(LL a) {
	return power(a, mod - 2);
}

void add(int pos, LL val) {
	for(; pos <= l; pos |= pos + 1) {
		bit[pos] += val;
		if(bit[pos] >= mod) bit[pos] -= mod;
	}
}

LL find(int pos) {
	LL temp = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		temp += bit[pos];
	}
	temp %= mod;
	return temp;
}

int main(void)
{
	int t;
	sf("%I64d %I64d %d %d", &base, &mod, &l, &t);
	while(base) {
		reset(bit, 0);
		while(t--) {
			char c = ' ';
			while(c != 'E' && c != 'H') sf("%c", &c);
			int i, j;
			sf("%d %d", &i, &j);
			if(c == 'E') {
				LL temp = find(i) - find(i - 1);
				if(temp < 0) temp += mod;
				add(i, -temp + mod);
				LL tambah = power(base, l - i) * j;
				tambah %= mod;
				add(i, tambah);
			} else {
				LL ret = find(j) - find(i - 1);
				if(ret < 0) ret += mod;
				ret *= inv(power(base, l - j));
				ret %= mod;
				pf("%d\n", (int) ret);
			}
		}
		puts("-");
		sf("%I64d %I64d %d %d", &base, &mod, &l, &t);
	}
	
	return 0;
}
