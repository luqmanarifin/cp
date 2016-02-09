#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define PI acos(-1.0)
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool equal(double a, double b) {
	return abs(floor(a) - b) < eps;
}

int main(void)
{
	int t, tt, i, n;
	sf("%d", &t);
	FOR(tt, 1, t) {
		sf("%d", &n);
		pf("Kasus-%d:", tt);
		FORS(i, n) {
			int k;
			double L;
			sf("%d %lf", &k, &L);
			L /= (1 << k);
			L = floor(sqrt(L/PI));
			//cout << L << endl;
			pf(" ");
			stack<double> ans;
			int p = 2;
			while(!equal(L, 0.0)) {
				ans.push(floor(fmod(L, 10.0)));
				L /= 10.0;
			}
			while(!ans.empty()) {
				if(p) {
					pf("%.0lf", ans.top());
					p--;
				} else pf("0");
				ans.pop();
			}
			
		}
		nl;
	}
	
	return 0;
}
