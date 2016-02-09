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

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

LL pre[64];

int tingkat(LL a) {
	int l = 0, r = 62;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(a < (1LL << mid)) r = mid - 1;
		else l = mid;
	}
	return l + 1;
}

int main(void)
{
	int t, i, j;
	FOR(i, 1, 63) {
		pre[i] += pre[i-1];
		pre[i] += (1LL << i);
	}
	sf("%d", &t);
	while(t--) {
		LL n, m;
		sf("%lld %lld", &n, &m);
		int tingkatmax = tingkat(n);
		//cout << tingkatmax << endl;
		LL papa = m - 1;
		LL x = n - m;
		LL pol = n;
		if(papa < 63) pol = min(pol, (1LL << m) - 1);
		LL l = 1, r = pol;
		while(l < r) {
			LL mid = (l + r) >> 1;
			int dif = tingkatmax - tingkat(mid);
			LL anak = pre[max(dif - 1, 0)];
			LL rep = 0, minrep = 0;
			if(dif) {
				rep = (mid << dif) + (1LL << dif) - 1;
				minrep = ((mid - 1) << dif) + (1LL << dif) - 1;
			}
			anak += max(0LL, min(rep, n) - minrep);
			if(anak <= x) r = mid;
			else l = mid + 1;
		}
		//pf("%lld %lld   total range : ", l, pol);
		pf("%lld\n", pol - l + 1);
	}
	
	return 0;
}
