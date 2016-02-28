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
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, k, h, m[N], v[N], ans[N], pos[N];

bool by(int lef, int rig) {
	if(m[lef] != m[rig]) return m[lef] < m[rig];
	return v[lef] < v[rig];
}

bool solve(double t) {
	int x = 0, i;
	FORS(i,n)
		if(v[pos[i]] * t >= (DB)(x + 1)*h)
			ans[x++] = pos[i];
			
	return x >= k;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int i;
	sf("%d %d %d", &n, &k, &h);
	FORS(i,n) sf("%d", m + i);
	FORS(i,n) sf("%d", v + i);
	FORS(i,n) pos[i] = i;

	sort(pos, pos + n, by);
	double l = 0.0, r = 1.0*k*h, mid;
	FORS(i, 100) {
		mid = (l + r)/2;
		cout << solve(mid) << endl;
		if(solve(mid))
			r = mid;
		else
			l = mid;
	}
	assert(solve(r));
	pf("%.18f\n%.18f\n%.18f\n",l,mid,r);
	FORS(i, k) pf("%d ", ans[i] + 1); nl;
	return 0;
}
