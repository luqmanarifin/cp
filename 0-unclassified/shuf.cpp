#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL inf = 4e18;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int dua[33], op = 0;

int main(void)
{
	int i, n, k, q, m;
	
	sf("%d %d %d", &n, &k, &q);
	dua[0] = 1; if(n == 1) m = 0;
	FOR(i,1,30) {
		dua[i] = dua[i-1] * 2;
		if(dua[i] == n) m = i;
	}
	
	while(k--) {
		int x;
		sf("%d", &x);
		op ^= dua[x];
	}
	while(q--) {
		int t;
		sf("%d", &t); t--;
		t ^= op;
		pf("%d\n", t + 1);
	}
	
	return 0;
}
