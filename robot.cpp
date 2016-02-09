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
const int N = 1e5 + 5;
const LL inf = 4e18;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL lef[N], rig[N];

int main(void)
{
	int l, r, ql, qr, n, i;
	sf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
	FOR(i,1,n) {
		sf("%I64d", &lef[i]);
		rig[i] = lef[i];
		rig[i] *= 1LL * r;
		lef[i] *= 1LL * l;
	}
	
	FOR(i,1,n) lef[i] += lef[i-1];
	FORD(i,n,1) rig[i] += rig[i+1];
	
	LL ans = inf;
	FOR(i,0,n) {
		LL cur = lef[i] + rig[i+1];
		
		if(n - 2*i - 1 > 0)
			cur += 1LL*(n - 2*i - 1)*qr;
		else if(2*i - n - 1 > 0)
			cur += 1LL*(2*i - n - 1)*ql;

		if(cur < ans) ans = cur;
	}
	cout << ans << endl;
	return 0;
}
