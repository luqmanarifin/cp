#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e6;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

bool done;

LL power(int a, int b) {
	if(b == 0) return 1;
	LL temp = power(a, b / 2);
	temp *= temp;
	if(temp >= mod) done = 1;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		if(temp >= mod) done = 1;
		temp %= mod;
	}
	return temp;
}

void print(int a) {
	int dig = 1, i;
	int aa = a;
	while(aa >= 10) {
		dig++;
		aa /= 10;
	}
	FORS(i, 6 - dig) pf("0");
	pf("%d\n", a);
}

int main(void)
{
	int a, b;
	sf("%d %d", &a, &b);
	a %= mod;
	int ans = (int) power(a, b);
	if(done) print(ans);
	else pf("%d\n", ans);
	return 0;
}
