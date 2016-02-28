#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define LD long double
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
#define x first
#define y second

const LL mod = 1e9 + 7;
const DB eps = 1e-4;
const DB PI = acos(-1.0);

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }
DB fgcd(DB a, DB b) { return (b < eps)? a : fgcd(b, fmod(a, b)); }

DB toDeg(DB radian) { return (DB) radian*180/PI; }

DB toRad(DB degree) { return (DB) degree*PI/180; }

int main(void)
{
	DB x1, x2, x3, y1, y2, y3;
	sf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	DB a = sqrt(pow(x2 - x1,2) + pow(y2 - y1,2));
	DB b = sqrt(pow(x3 - x2,2) + pow(y3 - y2,2));
	DB c = sqrt(pow(x3 - x1,2) + pow(y3 - y1,2));
	DB s = (a + b + c)/2;
	DB L = sqrt(s*(s - a)*(s - b)*(s - c));
	DB r = a*b*c/(4*L);
	DB teta1 = acos((b*b + c*c - a*a)/(2*b*c));
	DB teta2 = acos((b*b + a*a - c*c)/(2*b*a));
	DB teta3 = acos((a*a + c*c - b*b)/(2*a*c));
	DB teta = fgcd(teta1, fgcd(teta2, teta3));
	DB n = PI/teta;
	DB ans = n*r*r*sin(2*PI/n)/2;
	pf("%.12f\n", ans);
	//pf("%.5lf %.5lf %.5lf %.5lf %.5lf", a, b, c, teta, r); nl;
	return 0;
}
