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
const double eps = 5e-5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

double eq(double a, double b) {
	return abs(a - b) < eps;
}

int main(void)
{
	int t, i;
	sf("%d", &t);
	while(t--) {
		double W, H, x, xe, ye, miu;
		sf("%lf %lf %lf %lf %lf %lf", &W, &H, &x, &xe, &ye, &miu);
		double grad = (ye - H)/(xe - W);
		double l = 0.0, r = H + 100.0;
		FORS(i, 130) {
			double h = (l + r)/2;
			//pf("%.3lf %.3lf %.3lf\n", l, h, r);
			#define Q h
			double P = W - (H - Q)/grad;
			double sinteta = (W - P)/sqrt((W - P)*(W - P) + (H - Q)*(H - Q));
			double len = h*sinteta*sqrt(1/(miu*miu - sinteta*sinteta));
			//pf("len %.3lf\n", len);
			if(x > P - len) l = h;
			else r = h;
		}
		if(r > H || eq(r, H)) puts("Impossible");
		else pf("%.4lf\n", r);
	}
	
	return 0;
}
