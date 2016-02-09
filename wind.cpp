#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const double r = 6378.0;

double phi = 2*acos(0.0);
double maks = 70.0/180.0 * phi;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

double n;

double magic(double theta) {
	return n * cos(theta) / cos(theta + n / r);
} 

double toDeg(double rad) {
	return rad / phi * 180;
}

int main(void)
{
	int tt, t, i;
	sf("%d", &t);
	FOR(tt, 1, t) {
		double m;
		sf("%lf %lf", &n, &m);
		pf("Case %d: ", tt);
		if(n >= 1001.0 || magic(maks) < m) {
			pf("Invalid or impossible.\n");
			continue;
		}
		double lef = 0.0, rig = maks;
		FORS(i, 1000) {
			//pf("%lf %lf\n", toDeg(lef), toDeg(rig));
			double mid = (lef + rig) / 2;
			if(magic(mid) < m) lef = mid;
			else rig = mid;
		}
		lef = lef * 180.0 / phi;
		int deg = (int) lef;
		lef -= (double) deg;
		lef *= 60.0;
		int minu = (int) lef;
		lef -= (double) minu;
		lef *= 60.0;
		int sec = (int) (lef + 0.5);
		pf("%d deg %d min %d sec\n", deg, minu, sec);
	}
	
	return 0;
}
