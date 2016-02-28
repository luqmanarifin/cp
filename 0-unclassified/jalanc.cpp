#include <bits/stdc++.h>

/**
 * TOKI Open Contest Agustus 2014
 * Problem : 
 * Luqman Arifin (kadalbonek)
 */

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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<DB, DB> Point;
#define x first
#define y second
double L;

double dist(Point a, Point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double solve(Point a, Point b, Point c) {
	if(b.y == c.y) return abs(a.y - b.y);
	if(b.x == c.x) return abs(a.x - b.x);
	double m2 = (b.y - c.y)/(b.x - c.x);
	double c2 = b.y - m2*b.x;
	double m1 = -1/m2;
	double c1 = a.y - m1*a.x;
	double potx = (c2 - c1)/(m1 - m2);
	double poty = m1*potx + c1;
	return dist(a, mp(potx, poty));
}

int main(void)
{
	Point a, b, c;
	double ans = 1.0*INF;
	sf("%lf %lf", &a.x, &a.y);
	sf("%lf %lf", &b.x, &b.y);
	sf("%lf %lf", &c.x, &c.y);
	ans = min(ans, solve(a, b, c));
	ans = min(ans, solve(b, c, a));
	ans = min(ans, solve(c, a, b));
	pf("%.18lf\n", ans);
	return 0;
}
