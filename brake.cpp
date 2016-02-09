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
const double eps = 1e-14;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool equal(double a, double b) {
	return abs(a - b) < eps;
}

int main(void)
{
	int t, i;
	double s, v0, vx, a;
	sf("%d", &t);
	while(t--) {
		sf("%lf %lf %lf %lf", &s, &v0, &vx, &a);
		double pol = max(0.0, sqrt(v0*v0 - 2*s));
		if(vx < pol && !equal(vx, pol)) {
			puts("impossible");
			continue;
		}
		double l = 0.0;
		double r = (double) s;
		FORS(i, 1000) {
			double mid = (l + r)/2;
			double v = sqrt(v0*v0 + 2*a*mid);
			double vt = sqrt(v*v - 2*(s-mid));
			if(v*v - 2*(s-mid) < 0) {
				vt = 0.0;
			}
			if(vx < vt) r = mid;
			else l = mid;
		}
		double v = sqrt(v0*v0 + 2*a*r);
		double vt = sqrt(v*v - 2*(s-r));
		if(equal(r, s)) puts("-1");
		else {
			double tm;
			if(equal(a, 0)) tm = r/v0;
			else tm = (v - v0)/a;
			pf("%.15lf\n", tm);
		}
		pf("%.15lf\n", vt);
	}
	
	return 0;
}
