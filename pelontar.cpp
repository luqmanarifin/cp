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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 5e5 + 6;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

double ans, vmax, amax, dp[N][2], v0, v1, a0, a1, vv0, vv1, aa0, aa1;

double rad(double tt){
	return (tt * acos(-1)) / 180;
}

int main(void)
{
	char junk[25];
	sf("%s", junk);
	int i, n;
	sf("%d", &n);
	FOR(i, 1, n) {
		double vcur, acur;
		sf("%lf %lf", &vcur, &acur);
		acur /= 10.0;
		if(dp[i-1][0] > dp[i-1][1]) {
			dp[i][0] = dp[i-1][0];
			vv0 = v0;
			aa0 = a0;
		} else {
			dp[i][0] = dp[i-1][1];
			vv0 = v1;
			aa0 = a1;
		}
		double vyes = max(v1, vcur);
		double ayes = a1 + acur;
		double yes = (ayes <= 180? abs(2.0*vyes*vyes*sin(rad(ayes))*cos(rad(ayes))*9.8) : -1);
		double vno = max(v0, vcur);
		double ano = a0 + acur;
		double no = (ano <= 180? abs(2.0*vno*vno*sin(rad(ano))*cos(rad(ano))*9.8) : -1);
		if(yes > no) {
			dp[i][1] = yes;
			vv1 = vyes;
			aa1 = ayes;
		} else {
			dp[i][1] = no;
			vv1 = vno;
			aa1 = ano;
		}
		v0 = vv0;
		v1 = vv1;
		a0 = aa0;
		a1 = aa1;
	}
	pf("%.12lf\n", max(dp[n][0], dp[n][1]));
	return 0;
}
