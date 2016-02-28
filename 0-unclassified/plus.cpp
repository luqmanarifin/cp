#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

using namespace std;

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int p[100], xo[100], prob[100];

#define OUT { puts("-1"); return 0; }

int main(void)
{
	unsigned long long a, b, x = 0, y = 0;
	int i, j;
	cin >> a >> b;
	FORS(i, 64) p[i] = (1 & (a >> i));
	FORS(i, 64) xo[i] = (1 & (b >> i));
	FORS(i, 64) prob[i] = (p[i] ^ xo[i]);
	if(prob[0]) OUT;
	FOR(i, 1, 64) {
		if(prob[i] && !prob[i-1] && (p[i-1] || xo[i-1]))
			OUT
		if(!prob[i] && prob[i-1] && (!p[i-1] || xo[i-1]))
			OUT
	}
	FORS(i, 64) {
		LL add = (1LL << i);
		if(!prob[i]) {
			if(p[i])
				x ^= add;
			else if(prob[i+1]) {
				x ^= add;
				y ^= add;
			}
		} else {
			if(!prob[i+1])
				continue;
			x ^= add;
			if(p[i])
				y ^= add;
		}
	}
	if(x > y) swap(x, y);
	cout << x << ' ' << y << endl;
	return 0;
}
